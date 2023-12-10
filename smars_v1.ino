// This code has been written by Dennis Rotnov.
// You are welcome to use this code and change it, but please keep authorship attribution.
// Board: Raspberry pi pico

#define trigPin 14
#define echoPin 15
#define motorA_in1 0
#define motorA_in2 1
#define motorB_in1 2
#define motorB_in2 3

void setup() {
  Serial.begin(115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);  
  pinMode(motorA_in1, OUTPUT);  
  pinMode(motorA_in2, OUTPUT);  
  pinMode(motorB_in1, OUTPUT);  
  pinMode(motorB_in2, OUTPUT);  
}

void loop() {
  if (sendPing() > 5){
    goForward(255);
  } else {
    randomDirectionChange();
  }
}

int sendPing(){
  digitalWrite(trigPin, 0);
  delayMicroseconds(2);
  digitalWrite(trigPin, 1);
  delayMicroseconds(10);
  digitalWrite(trigPin, 0);
  long duration = pulseIn(echoPin, HIGH); // Time in  micro seconds
  int distance = duration * 0.034 / 2; // CM
  Serial.print("Distance: ");
  Serial.println(distance + "cm");
  return distance;
} 

void goBackward(int speed){
  digitalWrite(motorA_in1, 0);
  analogWrite(motorA_in2, speed);
  analogWrite(motorB_in2, speed);
  digitalWrite(motorB_in1, 0);
}

void goForward(int speed){
  analogWrite(motorA_in1, speed);
  digitalWrite(motorA_in2, 0);
  digitalWrite(motorB_in2, 0);
  analogWrite(motorB_in1, speed);
}

void goRight(){  
    digitalWrite(motorA_in1, 0);
    analogWrite(motorA_in2, 150);
    digitalWrite(motorB_in2, 0);
    analogWrite(motorB_in1, 150);
  }

void goLeft(){
    analogWrite(motorB_in2, 150);
    digitalWrite(motorB_in1, 0);
    analogWrite(motorA_in1, 150);
    digitalWrite(motorA_in2, 0);
}

void stop(){
  digitalWrite(motorA_in1, 1);
  digitalWrite(motorA_in2, 1);
  digitalWrite(motorB_in1, 1);
  digitalWrite(motorB_in2, 1);
}

void randomDirectionChange(){
  int randomDelay[] = {300, 500, 1000, 1500};
  // Temp = rand() % ( high - low + 1 ) + low 
  int directionChoice = (rand() % 3);
  int delayChoice = (rand() % 4);
  goBackward(150);
  delay(1500);
  if (directionChoice == 1){
    goLeft();
  } else {
    goRight();
  }
  delay(randomDelay[delayChoice]);
  stop();
}

/*
https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
In order to generate the ultrasound we need to set the Trig pin on a High State for 10 µs. That will send out an 8 cycle ultrasonic 
burst which will travel at the speed of sound. The Echo pins goes high right away after that 8 cycle ultrasonic burst is sent, and 
it starts listening or waiting for that wave to be reflected from an object.
If there is no object or reflected pulse, the Echo pin will time-out after 38ms and get back to low state.
f we receive a reflected pulse, the Echo pin will go down sooner than those 38ms. According to the amount of time the Echo pin was HIGH, 
we can determine the distance the sound wave traveled, thus the distance from the sensor to the object.
For that purpose we are using the following basic formula for calculating distance:
Distance = Speed x Time
The time is the amount of time the Echo pin was HIGH, and the speed is the speed of sound which is 340m/s. 
There’s one additional step we need to do, and that’s divide the end result by 2. and that’s because we are measuring 
the duration the sound wave needs to travel to the object and bounce back.

https://www.arduino.cc/reference/en/language/functions/advanced-io/pulsein/
Reads a pulse (either HIGH or LOW) on a pin. For example, if value is HIGH, pulseIn() waits for the pin to go from LOW to HIGH, starts timing, then waits for the pin 
to go LOW and stops timing. Returns the length of the pulse in microseconds or gives up and returns 0 if no complete pulse was received within the timeout.
*/
