#include <AFMotor.h>
AF_DCMotor leftMotor(4);
AF_DCMotor rightMotor(1);
void initializeMotors() {
  leftMotor.run(FORWARD);
  rightMotor.run(FORWARD);
}

void setLeftMotorSpeed(int inputSpeed) {
  if(inputSpeed<0) {
    leftMotor.run(FORWARD);
  }
  else {
    leftMotor.run(BACKWARD);
  }
  leftMotor.setSpeed(abs(inputSpeed));
}

void setRightMotorSpeed(int inputSpeed) {
  if(inputSpeed<0) {
    rightMotor.run(FORWARD);
  }
  else {
    rightMotor.run(BACKWARD);
  }
  rightMotor.setSpeed(abs(inputSpeed));
}

void runMotorTest() {
  setLeftMotorSpeed(255);
  setRightMotorSpeed(255);
  Serial.println(leftEncoderPos,DEC);
  delay(50);
}
