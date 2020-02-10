#include <IFCT.h>
#include <kinetis_flexcan.h>

int bitVar1 = 65535;
int bitVar2;
int bitVar3;

//int msg.buf[1];
int led = 13;
// create CAN object
IFCT CAN0(500000);
static CAN_message_t msg;

void setup() {
  Serial.begin(115200); delay(3000);
  // init CAN bus
  CAN0.begin();
  Can0.setBaudRate(500000);
  pinMode(led, OUTPUT);
  delay(1000);
  Serial.println("CAN Transmitter Initialized");
}

void loop() {

  bitVar2 = lowByte(bitVar1);
  bitVar3 = highByte(bitVar1); 
  
  Serial.print("Sending: ");
  msg.id = 0x222;
  msg.len = 2;
  msg.buf[0] = bitVar2;
  msg.buf[1] = bitVar3;
  Serial.println("");
  CAN0.write(msg);
  digitalWrite(led, !digitalRead(led));
  delay(1);
}
