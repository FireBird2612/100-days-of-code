
/*
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>

#define RST_PIN D3
#define SS_PIN D8

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

byte bufferUIDStore[5];
byte mastercard[5];
char uidStoreRoom[50][5]={ {135, 196, 119, 122, 132},

};
int idNumber = 1;

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	SPI.begin();
	mfrc522.PCD_Init();		// Init MFRC522
}

/*
void loop() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	Serial.print("\n\n\n\n");
	Serial.print("-------------------------------\n");

	for (byte i = 0; i < mfrc522.uid.size; i++) {				//will store the UID in the temporary buffer
		bufferUIDStore[i] = (mfrc522.uid.uidByte[i]);
		Serial.print(bufferUIDStore[i]);
		Serial.print(" ");
	}

	Serial.print("\n");

	/*
	if(bufferUIDStore[4] == 0){									//checking the last element of the buffer to decide if the last elements has anything written to it previously
	bufferUIDStore[4] = random(99);
	}

	else{
		Serial.print("occupied");
	}
	Serial.print(uidStoreRoom[0][4]);
	Serial.print("\n");
	*/

	/*

	delay(1000);

	mfrc522.PICC_HaltA();

	for (int i = 0; i < 49; i++){											//Compares the UID 
		for (int j = 0 + 4; j < 5; j++){
			if (bufferUIDStore[j] == uidStoreRoom[i][j])
			{
				Serial.print("User not present in database\n");
				idNumber = i;
				goto terminate;
			}
			else{

			}

		}
	}

	terminate:
	Serial.print("Succesfully exited from the loop since user is not present\nIdNumber is:");
	Serial.print(idNumber);


}

void masterAccess(byte inputUID[4])
{
}




void loop() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	for (int i = 0; i < mfrc522.uid.size; i++){
		Serial.print(mfrc522.uid.uidByte[i], HEX);
		Serial.print("\n");
		bufferUIDStore[i] = mfrc522.uid.uidByte[i];
		Serial.print(bufferUIDStore[i], HEX);
		Serial.print("\n");
	}

	mfrc522.PICC_HaltA();
}
*/