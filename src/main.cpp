#include <Arduino.h>

/*
#include <SPI.h>
#include <mcp2515.h>

# define CAN_CS   5
# define LED      17

struct can_frame frametable[] =
{
  {0x33a, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0x33a, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x33a, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0, 0, {0, 0, 0, 0, 0, 0, 0, 0}}
};


MCP2515 mcp2515(CAN_CS);


void setup()
{
//  while (!Serial);
  Serial.begin(115200);
  SPI.begin();
  
  mcp2515.reset();
  mcp2515.setBitrate(CAN_100KBPS, MCP_8MHZ);
  mcp2515.setNormalMode();
  pinMode(LED, OUTPUT);
}

void loop()
{  
  int i;
  digitalWrite(LED, LOW);
  for (i = 0; frametable[i].can_id != 0; i++)
  {
    mcp2515.sendMessage(&(frametable[i]));
    digitalWrite(LED, (i % 2 ? HIGH : LOW));
    delay (100);
  }
  delay(2000);
}
*/

#include <mcp_can.h>
#include <SPI.h>

# define CAN_CS   5
# define LED      17
# define MAX_TX_ERRS 10

typedef struct  canpacket
{
  uint32_t      id;
  uint8_t       ext;
  uint8_t       len;
  uint8_t       data[8];
}               t_canpacket;

t_canpacket packettable[] =
{
  {0x33a, 0, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0x33a, 0, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x4f3, 0, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}},
  {0x33a, 0, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}},
  {0, 0, 0, {0, 0, 0, 0, 0, 0, 0, 0}}
};


MCP_CAN CAN0(CAN_CS);     // Set CS to pin 10

void Error_loop(uint8_t count, uint8_t time)
{
  uint8_t i;

  for (i = 0; i < count; i++)
  {
    digitalWrite(LED, LOW);
    delay(time);
    digitalWrite(LED, HIGH);
    delay(time);
  }
}

void setup()
{
  pinMode(LED, OUTPUT);

  while (!(CAN0.begin(MCP_ANY, CAN_100KBPS, MCP_8MHZ) == CAN_OK))
    Error_loop(5, 2000);
  CAN0.setMode(MCP_NORMAL);   // Change to normal mode to allow messages to be transmitted
}

void loop()
{
  // send data:  ID = 0x100, Standard CAN Frame, Data length = 8 bytes, 'data' = array of data bytes to send
  uint8_t i;
  uint8_t timeout;
  digitalWrite(LED, LOW);
  for (timeout = 0, i = 0; packettable[i].id != 0 && timeout < MAX_TX_ERRS; i++)
  {
    byte sndStat = CAN0.sendMsgBuf(packettable[i].id, packettable[i].ext, packettable[i].len, packettable[i].data);
    if (sndStat == CAN_OK)
      digitalWrite(LED, (i % 2 ? HIGH : LOW));
    else
      {
        i--;
        timeout++;
      }
    delay (100);
  }
  if (timeout == MAX_TX_ERRS)
    Error_loop(42, 20);

  // sleep for 2 secs for now (approx. depending on stars constellations positioning, wind velocity, and air humidity ... XD)  
  delay(2000);
}
