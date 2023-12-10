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

# Video
[Watch video on YouTube](https://youtube.com/shorts/sbUY9tzoYJg?feature=share)

# Pictures
![3506BF33-EB88-46F1-B2C6-B0FBFA3EB994](https://github.com/LearnFL/pros-embedded-smars_v1/assets/86169204/f64f58b1-c251-4814-a226-46f2b1964827)
![49CFCFAB-4EEC-4934-8124-1F30901ABDEE](https://github.com/LearnFL/pros-embedded-smars_v1/assets/86169204/6a1e0852-6586-4ccc-94c1-298182692e75)
