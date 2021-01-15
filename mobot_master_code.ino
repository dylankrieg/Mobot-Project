#define ledPin 53

void setup() {
  Serial.begin(9600);
  initializeMotors();
  //qtrSetup();
}

void loop() {
  runMotorTest();
  //getFloorPosition();
  //feedback();
  
}
