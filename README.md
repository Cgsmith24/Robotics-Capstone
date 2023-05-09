Project TASRC
![IMG-8384](https://user-images.githubusercontent.com/90796216/236971352-8e43199f-4bd9-4b5a-b9b0-b4fc07e1d22c.JPG)

Designed and Engineered by: Chase Smith
Coded and Reported by: Chase Smith


Date: February 20th - May 10th 2023.


With Project TASRC, I had a vision, A vision of a car that could drive almost anywhere, perfectly smoothly. The car would be able to use 4 separate sensors for each wheel, and can sense the ground in front of each wheel, and would be able to adapt each individual arm to accommodate the terrain it was given. Unfortunately, due to time constraints, and hardware limitations. I was not able to achieve this dream to what it could truly be. Due to the processing power limitations of an arduino, and time limitations, I was unable to get all 4 sensors to function properly, So, the solution was to have 2 sensors, one for the front, and one for the rear. Nevertheless with the issues I have, I believe that I have achieved my goal to a great extent. 

The system uses two ultrasonic sensors connected to an arduino mega, each sensor controls two servos, two for the front, and two for the rear. The servos control a double wishbone suspension arm, this system is useful because no matter how the suspension moves, the wheels will stay vertical. If I don’t have this system, the more you raise and lower the suspension, the more the wheels would tilt in or out, effectively giving you camber, which for a car meant to crawl over things isn't the best idea.

The whole car is made up of custom made parts, the only structural parts that aren’t printed are the main chassis, and the upper chassis. The main chassis is made of an aluminum alloy bar that gives many mounting holes. The upper chassis is just a cut piece of cardboard, it is not structural, it is only used as a place to put micro controllers and battery packs. Every 3D printed part (with the exception of the ultrasonic sensor holders) was designed and printed by me on my basic Ender 3 3D printer. Every part is printed in PLA. The parts are printed in PLA so that they are cheap, reliable, and easy to print. The infill is low where it needs to be to support structure. But low where it doesn’t need to be as strong, all this combined means that I can have lots of prints for a low gram count. 

	
Functional Categories

Output Display: The output display is very simple, there are 2 LEDS, 1 green one, and one red one. The 1 green one turns on when the suspension system is not moving, sensing, but not moving, meaning that it has reached an acceptable range. The red LED is built into the rc receiver, it shows when the remote is connected to the car, and when input is being given.

Manual User Input: Manual User input is given in two ways, there is a controller that I pulled from an old rc car that isn’t worth much. The left stick controls the left side of the car, and the right side controls the right side. There is also a switch that can lock up the suspension system, so you can just ride around with no suspension, this is ideal for flat surfaces.

Automatic sensor: The automatic sensors are just 2 ultrasonic sensors, and  one for the front and one for the rear. These sensors record distance to the ground and tell the servos controlling the suspension to move based on that distance.

Actuators, Mechanisms, and Hardware: Three are 4 servos, one for each arm, 4 motors, one for each wheel. Physical mechanisms are: Double wishbone suspension front and rear. Each servo has its own shock connected to a servo horn, which is then connected to the arm for control of the arm. Hardware: There is an Arduino mega to control the entirety of the suspension system, the mega is needed due to the insane amount of wires and connections needed to control the suspension. There is also an Arduino Nano to control the entirety of the Drive system. There is a FLYSKY radio, and a KYOSHO Receiver, that is connected to the Nano, with one channel running to the mega to lock up suspension. There are two 6 volt power packs, not wired in series or in parallel, they are wired completely separate from each other, one power pack powers all the servos and sensors. And one powers both microcontrollers and the receiver.

Logic, Processing, and Control: The logic behind the suspension sounds simple, but actually is quite complicated. The sensors send an ultrasonic pulse to the ground, and it bounces back, the time between these two processes determines the distance to the ground. This happens 20 times a second. Then you have to take that time reading, and convert it to centimeters. After that you have to take that centimeter reading, and convert it to angle adjustments to the servos. So with this complicated process, you have to convert time to angles (Crazy, right). 
	I also have 2 Microcontrollers processing and completing two separate functions. The second controller is an Arduino Nano, this one is necessary because when you tell an arduino to use radio signals, it takes over every other function of the arduino. Meaning I could not possibly use one arduino for this whole project. The nano receives 2 signals from the remote, one for the left side drive, and the other for the right side drive. 





Parts List


Part
Model #
Source
Arduino Mega
EL-CB-002
Amazon
Arduino Nano
ATmega328P
Amazon
Motor Controller
L298N
Amazon
Ultrasonic Sensor
HC-SR04
Amazon
Arduino Motors+Tires
FZ
Amazon
1123 Series Pattern Plate
1123-0043-0096
GoBilda
Power Pack
ZRM & E
Amazon
FLYSKY Radio 
FS-i6X
Amazon
Kyosho Receiver
82135 Syncro KR-331
Kyosho America
Hobby Shocks
94166
Amazon




Lessons Learned

An arduino mega has a hard time controlling more than 4 servos and 2 distance sensors, so I had to switch to only 2 sensors.
An arduino when connected to a radio signal, blocks any other functions from occurring, So I had to integrate another arduino to use the radio signals.
Steering is hard, and I was running out of time. I had originally planned to have a real steering assembly. But I was running out of time, So I switched to tank drive. 
PLA can be brittle when not printed correctly. So I had to redesign and reprint the arms a few times to get ones strong enough to do the job.
A single battery pack can only do so much. I had to use 2 of them to get the project to have enough power.
Ultrasonic sensors are actually incredibly accurate, any minor movement would cause them to tell the servos to readjust, and that would just cause a chain reaction and make the robot go crazy, so I added an acceptable distance for the sensors to read, which fixed the problem. 








Build it Yourself

What you need:

A 3D Printer capable of printing PLA
200 Grams of PLA 3d Printing materials
A computer capable of a 3D slicer, and capable of Arduino IDE.
Solder
Soldering Iron
4 standard size servos
4 Arduino Motors and wheels
L298N Motor Controller
1 Arduino Mega 2560 (A normal UNO may work but not guaranteed)
1 Arduino Nano
2 5 AA power packs
2 HC-SR04 Ultrasonic sensors
Any RC remote and receiver
A piece of metal/plastic to make the main chassis
Cardboard
Hot Glue
Tons of wires
PATIENCE!!!

Step one: Printing

Print the following parts found on my github:

TASRC A-arm_fixed.stl x4
TASRC Turnbuckle V2.stl x4
TASRC Shock Tower V3.stl x2
TASRC Rear Hub Right_fixed.stl x2
TASRC Rear Hub Left_fixed.stl x2
TASRC Shock Tensioner.stl x4
Ultrasonic_HC-SR04_-_FOOT_MOUNT.stl x2


                      



Step Two: Wiring

![IMG-8390](https://user-images.githubusercontent.com/90796216/236971381-ba533319-e8b9-4781-a074-db242ad6dd9b.JPG)

Once you have all the parts printed described in step one, get all your materials together.  And look at the wiring diagram shown in the Github, and wire all your systems like that. 

Yes, it looks like spaghetti, but it works. 

Step 3: Assembly
In the 3D Files folder in the github, open FULL_BUILD.stl, that will show how all the parts interlock with each other, use whichever hardware you want to hold it all together. It is not shown in the 3D file, but the sensor holder holes match up with the holes that hold the arms to the shock tower, so just put your screws through that. Also not shown in the stl, is that you need to put a piece of cardboard on top of the servos, I just hot glued a cut piece of cardboard. That is where you mount your aduinos, power pack, and RC receiver, it doesn’t matter where you mount them, as long as you are happy with the placements. Once you have all that done, you can attach the wheels, I just used some metal bars and hot glue to attach them. 


Step 4: Coding

On the ardunio mega, upload the code Suspension_Code.ino, and upload to the Arduino nano Drive_Code.ino. Adjustments to code may need to be made in order to get it to function properly on your build.



Step 5: Testing/Trial and Error


From this point forward, it’s just testing and trial/error. It may take lots of testing to get it to work.  But with some time and effort, I guarantee you can do it!











