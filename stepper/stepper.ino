
/* 
 Stepper Motor Control - speed control
 
 This program drives a unipolar or bipolar stepper motor. 
 The motor is attached to digital pins 8 - 11 of the Arduino.
 A potentiometer is connected to analog input 0.
 
 The motor will rotate in a clockwise direction. The higher the potentiometer value,
 the faster the motor speed. Because setSpeed() sets the delay between steps, 
 you may notice the motor is less responsive to changes in the sensor value at
 low speeds.
 
 Created 30 Nov. 2009
 Modified 28 Oct 2010
 by Tom Igoe
 
 */

#include <Stepper.h>

const int stepsPerRevolution = 512;  // change this to fit the number of steps per revolution
// for your motor


// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8,10,9,11);            

int stepCount = 0;  // number of steps the motor has taken

void setup() {
  Serial.begin(9600);// nothing to do inside the setup
}

void loop() {
  // read the sensor value:
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 512);//这里最快转速为60rpm
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(60);
    // step 1/100 of a revolution:
    Serial.print("MOTOR SPEED:");
    Serial.println(motorSpeed);
    myStepper.step(motorSpeed);
    delay(1000);
  } 
}
