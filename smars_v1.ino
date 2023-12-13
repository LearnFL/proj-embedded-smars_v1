// This code has been written by Dennis Rotnov.
// You are welcome to use this code and change it, but please keep authorship attribution.
// Board: Raspverry pi pico

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
  delayMicroseconds(70);
  unsigned long duration = pulseIn(echoPin, HIGH); // Time in  micro seconds
  delayMicroseconds(70);
  // int distance = duration * 0.034 / 2; // CM
  int distance = (duration/2) / 29.1;
  Serial.println(distance);
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
  int randomDelay[] = {200, 300, 500, 700};
  // Temp = rand() % ( high - low + 1 ) + low 
  int directionChoice = (rand() % 2);
  int delayChoice = (rand() % 4);
  goBackward(100);
  delay(1000);

  if (directionChoice == 1){
    goLeft();
  } else {
    goRight();
  }

  delay(randomDelay[delayChoice]);
  stop();
}

/*
v1 = rand() % 100;         // v1 in the range 0 to 99
v2 = rand() % 100 + 1;     // v2 in the range 1 to 100
v3 = rand() % 30 + 1985;   // v3 in the range 1985-2014

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
