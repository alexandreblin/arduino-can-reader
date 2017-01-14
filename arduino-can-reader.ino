#include <SPI.h>
#include "mcp_can.h"

///////////////////
// Configuration //
///////////////////

// CS pin for CAN bus shield.
// The default pin depends on the shield's version:
//  - 1.0: digital pin 10
//  - 1.1 and newer: digital pin 9
const int CS_PIN = 9;

// Serial port data rate
const long SERIAL_SPEED = 115200;

// CAN bus data rate
const byte CAN_SPEED = CAN_125KBPS;

///////////////////

MCP_CAN CAN(CS_PIN);
unsigned char len = 0;
byte buffer[8];

void setup() {
    Serial.begin(SERIAL_SPEED);
    byte canSpeed = CAN_SPEED;

    while (CAN.begin(canSpeed) != CAN_OK) {
      delay(100);
    }
}

void loop() {
    if (CAN.checkReceive() == CAN_MSGAVAIL) {
        CAN.readMsgBuf(&len, buffer);

        Serial.print("FRAME:ID=");
        Serial.print(CAN.getCanId());
        Serial.print(":LEN=");
        Serial.print(len);
        
        char tmp[3];
        for(int i = 0; i<len; i++) {
            Serial.print(":");
            
            snprintf(tmp, 3, "%02X", buffer[i]);
            
            Serial.print(tmp);
        }

        Serial.println();
    }
}


