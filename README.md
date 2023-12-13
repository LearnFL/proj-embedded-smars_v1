# Kid's project SMARS robot using Raspberry Pi Pico.
Built with my kid for fun.

# Design
3d design was found on [ThingsGivers.com](https://www.thingiverse.com/thing:2662828) by Kevin Thomas. <br>
[How to assemble the robot](https://www.instructables.com/SMARS-Robot-Arduino-Smart-Robot-Tank-Bluetooth/). <br>
We utilized the Raspberry Pi Pico as it was readily available for our project. As the board required a 5v VCC, we incorporated a buck converter. Additionally, we integrated an H-bridge to regulate the motors. Upon detection of an obstacle within 5cm by the ultrasonic sensor, the robot will reverse for 1.5 seconds at a reduced speed. It will then randomly select a direction and turn at a random angle before continuing to drive forward until encountering another obstacle. Raspberry pi pico was programmed in c++ using Arduino IDE. This is version 1 of the project, we will make further modifications. Feel free to use, change, update the code but keep authorship attribution. 

# Parts used
1) Raspberry pi pico
2) H-bridge
3) Buck converter
4) Prototype board
5) Wires
6) 9v battery
7) 3d printed model

# How to put it all together
1) Print 3d model and assemble it. [How to assemble the robot](https://www.instructables.com/SMARS-Robot-Arduino-Smart-Robot-Tank-Bluetooth/).
2) Connect 9v battery to a buck converter.
3) Connect buck converter (5v out) to pipico VSYS (vcc).
4) Connect ground pin of pi pico to a ground pin of a buck converter. 
5) Connect 9 v bettery to H-bridge.
6) Connect pi pico pins 0, 1, to H-bridge in1 and in2.
7) Connect pi pico pins 2, 3, to H-bridge in3 and in4.
8) Connect motor A to H-bridge output for motor A.
9) Connect motor B to H-bridge output for motor B.
10) Connect ultrasonic sensor VCC to 5v output of a buck converter, connect ground terminal to a ground.
11) Connect trigger pin and echo pin of an ultrasonic sensor to pins 14 and 15 of pi pico correspondingly.
12) For convenience may add a switch for a positive terminal of 9v battery.

If I missed anything please text me for clarifiactions. 

# Comments
I have observed that the ultrasonic sensor has suddenly started malfunctioning and was no longer able to accurately measure distance. <br>
Even small delays between measurements did not improve the situation. However, after lowering the buck converter to below 5 volts, <br> 
the issue was resolved. It is possible that the switching power supply was causing interference with the sensor. I will confirm this later.<br>
In addition, I have added a 0.1uF capacitor between the 5V and ground rails of the sensor to reduce noise.

# Video
[Watch video on YouTube](https://youtube.com/shorts/sbUY9tzoYJg?feature=share)

# Pictures
![3506BF33-EB88-46F1-B2C6-B0FBFA3EB994](https://github.com/LearnFL/pros-embedded-smars_v1/assets/86169204/f64f58b1-c251-4814-a226-46f2b1964827)
![49CFCFAB-4EEC-4934-8124-1F30901ABDEE](https://github.com/LearnFL/pros-embedded-smars_v1/assets/86169204/6a1e0852-6586-4ccc-94c1-298182692e75)
