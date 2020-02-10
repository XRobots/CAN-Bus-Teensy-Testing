#include <IFCT.h>

int bitVar1;

void setup() {
  pinMode(2, OUTPUT); // for the transceiver enable pin
  Can0.setBaudRate(500000);
  Can0.enableFIFO();
}

void loop() {
  CAN_message_t msg;
  if ( Can0.read(msg) ) canSniff(msg);
}

void canSniff(const CAN_message_t &msg) {
  Serial.print("MB "); Serial.print(msg.mb);
  Serial.print("  LEN: "); Serial.print(msg.len);
  Serial.print(" EXT: "); Serial.print(msg.flags.extended);
  Serial.print(" REMOTE: "); Serial.print(msg.rtr);
  Serial.print(" TS: "); Serial.print(msg.timestamp);
  Serial.print(" ID: "); Serial.print(msg.id, HEX);
  Serial.print(" Buffer: ");
  for ( uint8_t i = 0; i < msg.len; i++ ) {
    Serial.print(msg.buf[i], DEC); Serial.print(" ");
  }

  if (msg.id == 0x222) {

      bitVar1 = (msg.buf[1] * 256) + msg.buf[0];
    
      Serial.print(" *** 16 bit var: ");
      Serial.print(bitVar1);
  }

  Serial.println();
}
