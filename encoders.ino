int leftEncoderPos,rightEncoderPos;
void initializeEncoders() {
  initializeLeftEncoder();
  initializeRightEncoder();
  Serial.println("Encoders Initialized");
}
void initializeLeftEncoder() {
  #define leftEncoderA 18
  #define leftEncoderB 19
  leftEncoderPos=0;
  pinMode(leftEncoderA,INPUT);
  pinMode(leftEncoderB,INPUT);
  attachInterrupt(leftEncoderA,runLeftEncoderA,CHANGE);
  attachInterrupt(leftEncoderB,runLeftEncoderB,CHANGE);
}

void initializeRightEncoder() {
  #define rightEncoderA 37
  #define rightEncoderB 39
  rightEncoderPos=0;
  pinMode(rightEncoderA,INPUT);
  pinMode(rightEncoderB,INPUT);
  attachInterrupt(rightEncoderA,runRightEncoderA,CHANGE);
  attachInterrupt(rightEncoderB,runRightEncoderB,CHANGE);
}

void runLeftEncoderA() {
  //found a low-to-high on channel A
  if(digitalRead(leftEncoderA)==HIGH) {
    //chceck channel B to see which way we are turning
    if(digitalRead(leftEncoderB)==LOW) {
      leftEncoderPos+=1;
    }
    else {
      leftEncoderPos-=1;
    }
  }
  else {
    if(digitalRead(leftEncoderB)==HIGH) {
      //chceck channel B to see which way we are turning
      if(digitalRead(leftEncoderB)==LOW) {
        leftEncoderPos+=1;
      }
      else {
        leftEncoderPos-=1;
      }
    }
  }
  //Serial.println(leftEncoderPos,DEC);
}

void runLeftEncoderB() {
  //look a low-to-high on Channel B
  if(digitalRead(leftEncoderB)==HIGH) {
    if(digitalRead(leftEncoderA)==HIGH) {
      leftEncoderPos+=1;
    }
    else {
      leftEncoderPos-=1;
    }
  }
  else {
    if(digitalRead(leftEncoderA)==LOW) {
      leftEncoderPos+=1;
    }
    else {
      leftEncoderPos-=1;
    }
  }
  //Serial.println(leftEncoderPos,DEC);
}

void runRightEncoderA() {
  //found a low-to-high on channel A
  if(digitalRead(rightEncoderA)==HIGH) {
    //chceck channel B to see which way we are turning
    if(digitalRead(rightEncoderB)==LOW) {
      rightEncoderPos+=1;
    }
    else {
      rightEncoderPos-=1;
    }
  }
  else {
    if(digitalRead(leftEncoderB)==HIGH) {
      //chceck channel B to see which way we are turning
      if(digitalRead(leftEncoderB)==LOW) {
        rightEncoderPos+=1;
      }
      else {
        rightEncoderPos-=1;
      }
    }
  }
  //Serial.println(rightEncoderPos,DEC);
}

void runRightEncoderB() {
  //look a low-to-high on Channel B
  if(digitalRead(rightEncoderB)==HIGH) {
    if(digitalRead(rightEncoderA)==HIGH) {
      rightEncoderPos+=1;
    }
    else {
      rightEncoderPos-=1;
    }
  }
  else {
    if(digitalRead(rightEncoderA)==LOW) {
      rightEncoderPos+=1;
    }
    else {
      rightEncoderPos-=1;
    }
  }
  //Serial.println(rightEncoderPos,DEC);
}
