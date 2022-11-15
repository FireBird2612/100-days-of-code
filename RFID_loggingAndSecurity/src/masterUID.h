#ifndef masterUID_h

#define masterUID_h
#include <Arduino.h>
#include <SPI.h>

void masterUIDAccess(byte inputArr[], byte mastercard[], int swStatus){
        while (swStatus == 0)
            {
            
            Serial.print("Checking for Master Card\n");
            delay(500);

            if (mastercard[0] == inputArr[0] && mastercard[1] == inputArr[1] && mastercard[2] == inputArr[2] && mastercard[3] == inputArr[3])
            {
                Serial.print("Master Card Successfully Authenticated");
                // function that will scan and write data to the new ID
                //
            }
            else
            {
                Serial.print("Master Card not detected!");
            }
        }
}
#endif