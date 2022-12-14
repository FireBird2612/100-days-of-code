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

**Date:** 5 Nov 2022

Back to doing RFID, figured out how I will be storing UID if someone new has to register. Still, plenty of things left to do. Did few experiments with rotary encoder as I will be controlling the visual part on lcd display with the encoder.

---

# Day7 of coding challenge

**Date:** 6 Nov 2022

I learned about how one can store long term data into an EEPROM, so the UIDs of PICC (RFID tags) needs to be stored permanently as the new tags get scanned but I'm a little confused in figuring out how much memory can be alloted for EEPROM emulation on ESP8266 12E (4MB flash). This also means that i need better memmory optimization as i will need as much storage space i can get. Now that I can scan the PICC and compare it with the stored UIDs, I also want to have a master RFID card which allows to store new scanned RFIDs or maybe I can pass the data to the server and store it there. Still lot of things to figure out and lots of things learn.

---

# Day8 of coding challenge

**Date:** 7 Nov 2022

Making a function which will write personal data on the RFID tag, only master card will be able to access this function.
Just reading through header files and main program of the library helps me understand so much about the programming language. I'm still a beginner but I feel like I'm understanding so much just by learning through doing simple projects.
Unfortunately half way through, I'm not able to type any input in serial monitor. Will have to figure figure that out first.

---

# Day9 of coding challenge

**Date:** 8 Nov 2022

Finally, I can read from and write data to PICC (RFID). It took some time understanding how the library works and what each function in the library is meant to do, especially the logic behind the function. 
Now, I have to integrate both the processes of reading and writing which will depend on few conditions.

---

# Day10 of coding challenge

**Date:** 9 Nov 2022

Learned how to do debugging which helped me test my code in every possible scenario that plays out, espcecially when writing the PICC with new information.
A little more tweaking and testing before proceeding further.

---

# Day11 of coding challenge

**Date:** 10 Nov 2022

printing the necessary elements to the lcd at various places. Also, I'm still not able to control the lcd with rotary encoder, since the adding of new PICC to the system will be done through the encoder. I will have to figure out a way to properly use encoder with the lcd. Also, played around the wifi functionality of ESP8266. 

---

# Day12 of coding challenge

**Date:** 11 Nov 2022

Bad News: The MFRC522 module is not working because instead of providing 3.3V supply, I provided 5V supply. The module strictly needs 3.3V supply since it doesn't has any buck converter built into the module. So, I will have to wait for couple of days until the new module arrives. 
So, instead I will be learning IoT communication protocol. 
I started with MQTT (Message Queue Telemetry Transport) protocol which is a popular protocol when it comes to IoT devices.
To see how it works and experiment with it, I have connected DHT11 sensor with NodeMCU. I will be publishing the data to the EMQX Cloud but unfortunately I'm not able to make a proper connection, so will have to figure that out first before proceeding any further.

---

# Day13 of coding challenge

**Date:** 12 Nov 2022

So I managed to get the DHT11 sensor online by using MQTT Protocol. I'll be connecting more sensors to ESP8266 and getting them online. I also want to try different brokers and get myself more familarise with protocol itself.
The temperature and humidity that is being monitored is not the room temperature but instead the outside temperature as I've the setup near my window. I'd would like to see the variations in them through out the night.

---

# Day14 of coding challenge

**Date:** 13 Nov 2022

Practicing questions on arrays from GeeksForGeeks. I want to get myself more comfortable with C language especially the problem solving and logic that one implements. Anyways,
I did not have my laptop today so was not able to continue from I left off yesterday.

---

# Day15 of coding challenge

**Date:** 14 Nov 2022

Back again, playing with RFID. I'm trying to optimise my code, trying to use less variables, and structure the whole code properly by using functions wherever neccessary!

---

# Day16 of coding challenge 

**Date:** 15 Nov 2022

Almost there! Will be figuring out the server part tomorrow. 

---

# Day17 of coding challenge

**Date:** 16th Nov 2022

So many logic errors, spend most of time solving those errors. learning more about using debuggng in VS Code, PlatformIO

---

# Day18 of coding challenge 

**Date:** 17th Nov 2022

I'm trying to figure out how can i remove the blinking effect on the lcd that say's "Scan your tag". I want it to be static but since it is in the loop, it acts like its blinking very rapidly.

---

# Day19 of coding challenge

**Date:** 18 Nov 2022

Today, I connected the Reed Switch with ESP8266, the plan was to get the alert notification on Telegram by a bot which I had to configure.
I was not able to completely get 100% result. but I do feel like with this type of project I now know much more about HTTP protocol. Also, played around with two more library, that i never knew about. 

---

# Day20 of coding challenge

**Date:** 19 Nov 2022

Didnt do much today, just setting up the menu on lcd display which also has few bugs that needs to be sorted after which I might be able to wrap the RFID project and move on to different one but lately I tend to procrastinate on the RFID project and focus on learning IoT protocols.

---

# Day21 of coding challenge

**Date:** 20 Nov 2022

Built a simple web server with ESP8266, again getting myself familiarised with the ESP8266WiFi library.

I was able to control an LED with the web server after which I decided to connect the relay, might as well try connecting an AC load.

This may seem very easy and of course, it is but I get to learn a lot of things by just doing it and building on top of it like how the relay works, the logic that goes behind a function, reading and understanding the library, the networking protocol, and programming.

Just knowing the syntax of any language won't get you anywhere but practicing the language is the way to go.

---

# Day22 of coding challenge

**Date:** 21 Nov 2022

Solved few problems on C programming from G2G.

I will be working on my C language from now on, solving as many problems as I can!

---

# Day23 of coding challenge

**Date:** 22 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day24 of coding challenge

**Date:** 25 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day25 of coding challenge

**Date:** 26 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day26 of coding challenge

**Date:** 27 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day27 of coding challenge

**Date:** 28 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day28 of coding challenge

**Date:** 29 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day29 of coding challenge

**Date:** 30 Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day30 of coding challenge

**Date:** 1 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day31 of coding challenge

**Date:** 2 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day32 of coding challenge

**Date:** 3 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day33 of coding challenge

**Date:** 4 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day34 of coding challenge

**Date:** 5 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day35 of coding challenge

**Date:** 6 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day36 of coding challenge

**Date:** 7 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day37 of coding challenge

**Date:** 8 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day38 of coding challenge

**Date:** 9 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day39 of coding challenge

**Date:** 10 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day40 of coding challenge

**Date:** 11 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day41 of coding challenge

**Date:** 12 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day42 of coding challenge

**Date:** 13 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day43 of coding challenge

**Date:** 14 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day44 of coding challenge

**Date:** 15 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day45 of coding challenge

**Date:** 16 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day46 of coding challenge

**Date:** 17 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day47 of coding challenge

**Date:** 18 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day48 of coding challenge

**Date:** 19 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day49 of coding challenge

**Date:** 20 Dec Nov 2022

Day 2 of understanding, implementing and solving...

---

# Day50 of coding challenge

**Date:** 21 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day51 of coding challenge

**Date:** 22 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day52 of coding challenge

**Date:** 23 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day53 of coding challenge

**Date:** 24 Dec 2022

Day 2 of understanding, implementing and solving...

---

# Day54 of coding challenge

**Date:** 25 Dec 2022

Day 2 of understanding, implementing and solving...

---