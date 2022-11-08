# Day1 of coding challenge

**Date:** 31 Oct 2022

Since I'm new to the Visual Studio Code, Git and GitHub, it took some time getting around and setting up the environment but I got it done.

The project that I'm working on is RFID based Security System and the coding part for today was easy, it was just the interfacing of 16x2 display with NodeMCU ESP8266.

---

# Day2 of Coding Challenge

**Date:** 1 Nov 2022

Today, I worked on getting the RFID MFRC522 Module up and working with ESP8266. MFRC522 uses SPI protocol to talk to ESP8266. It was quite fun going through the datasheet for the PICC and PCD and also popular library for MFRC522.

Link for the MFRC522 Library [here](https://github.com/miguelbalboa/rfid)

---

# Day3 of Coding Challenge

**Date:** 2 Nov 2022

Lot of troubleshooting, got stuck so many times...
Played with arrays, especially 2D array to store the UID of PICC tags.
Again, going through datasheet, understanding how library for MFRC522 works.
But at the end felt like not much progress was made.

---

# Day4 of Coding Challenge

**Date:** 3 Nov 2022

Decided to practice few string concepts such as strlen, strcmp, strstr, strcat, etc.

---

# Day5 of Coding Challenge

**Date:** 4 Nov 2022

Played around with different algorithims today in how they work.
While in the middle of coding I figured out a way I'd be scanning and storing UID of PICC in my RFID Project. So will definetly try that out tomorrow. Would have loved to code some more but my brain is not functioning anymore, being sleep deprived is not good, need that 7hrs of sleep.

---

# Day6 of coding challenge

**Date:** 5th Nov 2022

Back to doing RFID, figured out how I will be storing UID if someone new has to register. Still, plenty of things left to do. Did few experiments with rotary encoder as I will be controlling the visual part on lcd display with the encoder.

---

# Day7 of coding challenge

**Date:** 6th Nov 2022

I learned about how one can store long term data into an EEPROM, so the UIDs of PICC (RFID tags) needs to be stored permanently as the new tags get scanned but I'm a little confused in figuring out how much memory can be alloted for EEPROM emulation on ESP8266 12E (4MB flash). This also means that i need better memmory optimization as i will need as much storage space i can get. Now that I can scan the PICC and compare it with the stored UIDs, I also want to have a master RFID card which allows to store new scanned RFIDs or maybe I can pass the data to the server and store it there. Still lot of things to figure out and lots of things learn.

---

# Day8 of coding challenge

**Date:** 7th Nov 2022

Making a function which will write personal data on the RFID tag, only master card will be able to access this function.
Just reading through header files and main program of the library helps me understand so much about the programming language. I'm still a beginner but I feel like I'm understanding so much just by learning through doing simple projects.
Unfortunately half way through, I'm not able to type any input in serial monitor. Will have to figure figure that out first.

---

# Day9 of coding challenge

**Date:** 8th Nov 2022

Finally, I can read from and write data to PICC (RFID). It took some time understanding how the library works and what each function in the library is meant to do, especially the logic behind the function. 
Now, I have to integrate both the processes of reading and writing which will depend on few conditions.

---
