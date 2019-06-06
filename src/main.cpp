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
  bool		firstrun;
  unsigned long	start;
  unsigned long	cycletime;
  t_canpacket	*packet;
}		t_framecycle;

t_canpacket status = {0x33a, 5, {0x30, 0x82, 0x81, 0x0a, 0x7f, 0, 0, 0}};
t_canpacket network = {0x4f3, 8, {0x78, 0x42, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff}};
t_framecycle	framecycletable[] = 
  {
    {true, 0, 10000, &status},
    {true, 200, 10000, &status},
    {true, 400, 10000, &status},
    {true, 0, 940, &network},
    {true, 0, 0, 0}
  };

unsigned long inittime;
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
  uint8_t	i = 0;
  uint8_t	timeout = 0;

  while (timeout <= MAX_TX_ERRS)
    {
      byte sndStat = CANDEV.sendMsgBuf(id, len, data);

      if(sndStat == CAN_OK)
	{
	  Serial.println("Message Sent Successfully!");
	  break ;
	}
      else
	{
	  Serial.println("Error Sending Message...");
	  timeout++;
	}
    }
  if (timeout >= MAX_TX_ERRS)
    {
      Serial.println("Giving up this packet, going to next one");
      return (false);
    }
  else
    return (true);
}

void setup()
{
  pinMode(LED, OUTPUT);
  Serial.begin(115200);

  while (!(CANDEV.begin(MCP_ANY, CAN_100KBPS, MCP_8MHZ) == CAN_OK))
    {
      Error_loop(5, 2000);
      Serial.println("Error Initializing CAN DEVICE...");
    }
  CANDEV.setMode(MCP_NORMAL);
  inittime = millis();
}

void loop()
{
  uint8_t i;
  bool sent;
  
  digitalWrite(LED, LOW);
  for (i = 0, sent = false; framecycletable[i].packet; i++)
    if (framecycletable[i].firstrun == true)
      {
	if ((inittime + framecycletable[i].start) >= millis())
	  {
	    sent = send_packet(framecycletable[i].packet->id, framecycletable[i].packet->len, framecycletable[i].packet->data);
	    framecycletable[i].start = millis();
	    framecycletable[i].firstrun = false;
	    if (sent)
	      digitalWrite(LED, (i % 2 ? HIGH : LOW));
	  }
      }
    else
      {
	if ((framecycletable[i].start + framecycletable[i].cycletime) >= millis())
	  {
	    sent = send_packet(framecycletable[i].packet->id, framecycletable[i].packet->len, framecycletable[i].packet->data);
	    framecycletable[i].start = millis();
	    if (sent)
	      digitalWrite(LED, (i % 2 ? HIGH : LOW));
	  }
      }
  delay(5);
}
