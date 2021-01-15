#include <QTRSensors.h>
#define numSensors 8
QTRSensors qtr;
int sensorValues[6];
int position;
int goalPosition=3500;
float kp=0.3;
float ki=0.000;
float kd=0.0;
float feedbackVal;
int previousError,currentError,errorTotal;
void qtrSetup() {
  qtr.setTypeRC();
  qtr.setSensorPins((const uint8_t[]){22,23,24,25,26,27,28,29},numSensors);
  qtr.setEmitterPin(46);
  delay(500);
  Serial.println("Calibration Starting");
  digitalWrite(ledPin,HIGH);
  //10 second calibration
  for(int i=0;i<400;i++) {
    qtr.calibrate();
  }
  digitalWrite(ledPin,LOW);
  Serial.println("Calibration Finished");
  for(int i=0;i<numSensors;i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();
  for(int i=0;i<numSensors;i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  delay(1000);
}

void getFloorPosition() {
  position=qtr.readLineWhite(sensorValues);
  for(int i=0;i<numSensors;i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  Serial.print(position);
  Serial.print('\t');
  Serial.println(position-goalPosition);
}
void feedback() {
  currentError=position-goalPosition;
  errorTotal+=currentError;
  previousError=currentError;
  //test just kd and see if it works
  feedbackVal=(kp*currentError)+(ki*errorTotal)+(kd*(currentError-previousError));
  Serial.println(position,DEC);
  //Serial.println(kd*(currentError-previousError),DEC);
  if(feedbackVal<0) {
    setLeftMotorSpeed(255);
    setRightMotorSpeed(255+feedbackVal);
  }
  else if(feedbackVal>0) {
    setLeftMotorSpeed(255-feedbackVal);
    setRightMotorSpeed(255);
  }
  else {
    setRightMotorSpeed(255);
    setLeftMotorSpeed(255);
  
  }
  
  Serial.println(currentError);
  
}
