#include <IFCT.h>
#include <kinetis_flexcan.h>

//int msg.buf[1];
int led = 13;
// create CAN object
IFCT CAN0(500000);
static CAN_message_t msg;

void setup() {
  Serial.begin(115200);delay(3000);
  // init CAN bus
  CAN0.begin();
  Can0.setBaudRate(500000);
  pinMode(led, OUTPUT); 
  delay(1000);
  Serial.println("CAN Transmitter Initialized");
}

void loop() {
  Serial.print("Sending: ");
  msg.id = 0x220;
  msg.len = 2;
  msg.buf[0] = 9;
  msg.buf[1] = 8;
  /*
      for(int i=0; i<msg.len; i++) { 
        msg.buf[i] = '0' + i;
        Serial.print(msg.buf[i]); Serial.print(" ");
      }
      */
  Serial.println("");
  CAN0.write(msg);
  digitalWrite(led, !digitalRead(led));
  delay(1);
}
