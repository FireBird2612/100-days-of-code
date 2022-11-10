
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

void ReadDataFromBlock(int blockNum, byte readBlockData[]);

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

    ReadDataFromBlock(blockNo, dataFromBlock1);

    Serial.print("\n");
    Serial.print("Data in Block:");
    Serial.print(blockNo);
    Serial.print(" --> ");
    for (int j = 0; j < 16; j++)
    {
        Serial.write(dataFromBlock1[j]);
    }
    Serial.print("\n");
}

void ReadDataFromBlock(int blockNum, byte readBlockData[])
{
    // Authenticating the desired data block for Read access using Key A
    status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, blockNum, &key, &(mfrc522.uid));

    if (status != MFRC522::STATUS_OK)
    {
        Serial.print("Authentication failed for Read: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else
    {
        Serial.println("Authentication success");
    }

    /* Reading data from the Block */
    status = mfrc522.MIFARE_Read(blockNum, readBlockData, &length);
    if (status != MFRC522::STATUS_OK)
    {
        Serial.print("Reading failed: ");
        Serial.println(mfrc522.GetStatusCodeName(status));
        return;
    }
    else
    {
        Serial.println("Block was read successfully");
    }
}