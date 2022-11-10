#include <Arduino.h>

#define RESWITCH D4

void setup()
{
    pinMode(D4, INPUT);
}

void loop()
{
    int ReadThis = digitalRead(D4);
    Serial.printf("%d\n", ReadThis);
    delay(500);
}