#ifndef masterUID_h

#define masterUID_h
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "masterUID.h"

#define RST_PIN D3
#define SS_PIN D8

LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

MFRC522::MIFARE_Key key;

byte bufferUIDStore1[4];

void masterUIDAccess(byte mastercard[], int swStatus){
    lcd.clear();
    Serial.print("Checking for Master Card\n");
    delay(500);

    //checks for new ID
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        lcd.setCursor(1, 0);
        Serial.print("Scan your tag for master access!\n");
        return;
    }
    
    //reads the PICC if new card is found
    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    Serial.print("\n\n\nReading ID!\n");
    delay(500);
    Serial.print("ID: ");

    //prints the UID of PICC onto the Screen!
    for (int i = 0; i < mfrc522.uid.size; i++)
    {
        bufferUIDStore1[i] = mfrc522.uid.uidByte[i];
        Serial.print(bufferUIDStore1[i]);
        Serial.print(" ");
    }
    int i = 0;
    if (bufferUIDStore1[i] == mastercard[i]){
        i++;
        if (bufferUIDStore1[i] == mastercard[i]){
            i++;
            if (bufferUIDStore1[i] == mastercard[i]){
                i++;
                if (bufferUIDStore1[i] == mastercard[i]){
                    Serial.print("Authenticated!");
                }
            }
        }
    }

    else{
        Serial.print("Master Card not detected!\n");
    }
    mfrc522.PICC_HaltA();
}
#endif