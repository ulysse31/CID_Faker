/*
CID_Faker
Copyright (C) 2019  Ulysse31 a.k.a Nix
                    ulysse31@gmail.com
Author Name : Victor do Vale
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <Arduino.h>
#include <mcp_can.h>
#include <SPI.h>

# define CAN_CS   5
# define LED      17
# define MAX_TX_ERRS 3

typedef struct      canpacket
{
  unsigned long     id;
  uint8_t           len;
  uint8_t           data[8];
}                   t_canpacket;


typedef struct	framecycle
{
  unsigned long	start;
  unsigned long	cycletime;
  t_canpacket	*packet;
}		t_framecycle;

t_canpacket status = {0x33a, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}};
t_canpacket network = {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};


// PROD VALUES
t_framecycle	framecycletable[] = 
  {
    {0, 10030, &status},
    {160, 10030, &status},
    {380, 10030, &status},
    {0, 940, &network},
    {0, 0, 0}
  };

MCP_CAN CANDEV(CAN_CS);

void Error_loop(uint8_t count, uint16_t time)
{
  uint8_t i;

  for (i = 0; i < count; i++)
  {
    digitalWrite(LED, LOW);
    delay(time);
    digitalWrite(LED, HIGH);
    delay(time);
  }
    digitalWrite(LED, LOW);
}

bool		send_packet(INT32U id, INT8U len, INT8U *data)
{
  uint8_t	timeout = 0;

  while (CANDEV.sendMsgBuf(id, len, data) != CAN_OK && timeout <= MAX_TX_ERRS)
     timeout++;
  if (timeout >= MAX_TX_ERRS)
    return (false);
  else
    return (true);
}

void            setup()
{
  unsigned long inittime;

  pinMode(LED, OUTPUT);
  while (CANDEV.begin(MCP_ANY, CAN_100KBPS, MCP_8MHZ) != CAN_OK)
    Error_loop(5, 2000);
  CANDEV.setMode(MCP_NORMAL);
  inittime = millis();
  for (uint8_t i = 0; framecycletable[i].packet != NULL; i++)
    framecycletable[i].start += inittime;
}

void loop()
{
  digitalWrite(LED, LOW);
  for (uint8_t i = 0; framecycletable[i].packet != NULL; i++)
    if (framecycletable[i].start <= millis())
      {
        if (send_packet(framecycletable[i].packet->id, framecycletable[i].packet->len, framecycletable[i].packet->data) == true)
          digitalWrite(LED, (i % 2 ? LOW : HIGH));
        framecycletable[i].start = framecycletable[i].start + framecycletable[i].cycletime;
      }
  delay(5);
}
