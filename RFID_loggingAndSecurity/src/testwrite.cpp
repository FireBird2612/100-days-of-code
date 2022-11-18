/****************************************************************************
Test to check the pushButton functionality of the rotary encoder.
Switching between 1 and 0 will toggle entry to masteraccess.




#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#define pushButton D4

int statPushButton;

void setup()
{
    Serial.begin(112500);
    pinMode(pushButton, INPUT);
}

void loop()
{
    statPushButton = digitalRead(pushButton);
    if (statPushButton == 0)
    {
        Serial.printf("check the output of Push Button: %d\n", statPushButton);
        return;
    }

    Serial.printf("FallDown! and pushButton = %d", statPushButton);
    delay(500);
}
*/