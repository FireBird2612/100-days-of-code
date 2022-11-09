/*
#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN D3
#define SS_PIN D8

MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance

MFRC522::MIFARE_Key key;

void readFromBlock1(int Block, byte dataFromBlock[]);
void readFromBlock2(byte dataFromBlock2[]);
void writeDataPICC(int block, byte writeBuffer[]);

byte bufferUIDStore[4];
byte mastercard[4];
char uidStoreRoom[50][4] = {
    {135, 196, 119, 122},
};
int idNumber = 1;

// variables for reading the data on PICC
byte blockNo = 1, length = 18;
byte dataFromBlock1[18];
byte dataFromBlock2[18];

// variables to write data to PICC
byte datatoblock1[18];
byte datatoblock2[18];

MFRC522::StatusCode status;

void setup()
{
    Serial.begin(112500); // Initialize serial communications with the PC
    SPI.begin();
    mfrc522.PCD_Init(); // Init MFRC522

    for (byte i = 0; i < 6; i++)
    {
        key.keyByte[i] = 0xFF;
    }
}

void loop()
{

    if (!mfrc522.PICC_IsNewCardPresent())
    {
        return;
    }

    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }

    Serial.print("Writing to the PICC\n");

    writeDataPICC(blockNo, datatoblock1);
}

void writeDataPICC(int block, byte writeBuffer[])
{
    int Block = 1;
    // Ask data from serial port
    Serial.setTimeout(20000);
    Serial.println("Enter your first name, ending with #");
    // read bytes until # character
    length = Serial.readBytesUntil('#', (char *)writeBuffer, 18);

    // authenticate with KeyA before proceeding to write the data
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, Block, &key, &(mfrc522.uid));
    // check status
    if (status != MFRC522::STATUS_OK){
        Serial.print("Authentication Failed!");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else{
        Serial.print("Authentication Successful!");
    }

    // write data to block 1
    status = mfrc522.MIFARE_Write(block, writeBuffer, length);
    if (status != MFRC522::STATUS_OK)
    {
        Serial.print(F("MIFARE_Write() failed: "));
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else
        Serial.println(F("MIFARE_Write() success: "));
}
*/