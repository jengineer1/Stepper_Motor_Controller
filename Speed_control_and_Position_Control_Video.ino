// Written By: Jeremy Fielding. Watch the instructional video here. https://youtu.be/QMgckRoRy38


#include <AccelStepper.h>


//Defining pins
int Stepper1Pulse = 5;  // Pulse or step pin
int Stepper1Direction = 6;  // Direction pin
int Stepper2Pulse = 7;
int Stepper2Direction = 8;
int speedpot = A0;   // Potentiometer
int positionpot = A1;


//defining terms


int Motor1speed = 0;
int Motor2position = 0;
int speedmin = 0; //pulses per second
int speedmax = 4000;  //pulses per second
int positionmax = 1600;
AccelStepper step1(1, Stepper1Pulse, Stepper1Direction);
AccelStepper step2(1, Stepper2Pulse, Stepper2Direction);


void setup() {               
   

  step1.setMaxSpeed (speedmax);  
  step1.setSpeed(0);
  step1.setAcceleration(1000);
  step2.setMaxSpeed (10000);  
  step2.setSpeed(5000);
  step2.setAcceleration(10000);
  pinMode(Stepper1Pulse, OUTPUT);
  pinMode(Stepper1Direction, OUTPUT);
  pinMode(Stepper2Pulse, OUTPUT);
  pinMode(Stepper2Direction, OUTPUT);
  digitalWrite(Stepper1Pulse, LOW);
  digitalWrite(Stepper1Direction, LOW);
  digitalWrite(Stepper2Pulse, LOW);
  digitalWrite(Stepper2Direction, HIGH);

}

void loop() {
  
  Motor1speed = map((analogRead(speedpot)),0,1023,speedmin,speedmax);
  step1.setSpeed(Motor1speed);
  step1.runSpeed();
  Motor2position = map((analogRead(positionpot)),0,1023,0,positionmax);
  step2.moveTo(Motor2position);
  step2.run();


}
