//move forward  !!Reason for 154 and 180 being the motor speeds is due to the variation in the motors. For a perfectly equal set of motors will be able to work properly with equal speed settings. 
//adjust the speeds of the motors according to your needs.
void forward()
{
  //forward motion
  digitalWrite(RPin1, HIGH);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, HIGH);
  digitalWrite(LPin2, LOW);
  analogWrite(enableR, 154);
  analogWrite(enableL, 180);
}

//move in reverse
void reverse()  
{
  digitalWrite(RPin1, LOW);
  digitalWrite(RPin2, HIGH);
  digitalWrite(LPin1, LOW);
  digitalWrite(LPin2, HIGH);
  analogWrite(enableR, 154);
  analogWrite(enableL, 180);
}

//turn right indefinately
void rightTurn()  // similar to forward test
{
  // set up both motors for reverse direction
  digitalWrite(RPin1, LOW);
  digitalWrite(RPin2, HIGH);
  digitalWrite(LPin1, HIGH);
  digitalWrite(LPin2, LOW);
  analogWrite(enableR, 154);
  analogWrite(enableL, 154);
}

//turn off all motors
void motorsOff()
{
  digitalWrite(RPin1, LOW);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, LOW);
  digitalWrite(LPin2, LOW);
}

//random forward
void randRun()
{
  digitalWrite(RPin1, HIGH);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, HIGH);
  digitalWrite(LPin2, LOW);
  analogWrite(enableR, random(0, 244));
  analogWrite(enableL, random(0, 244));
}

//free run with ultrasonic
void freeRun()
{
  digitalWrite(RPin1, HIGH);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, HIGH);
  digitalWrite(LPin2, LOW);
  analogWrite(enableR, 154);
  analogWrite(enableL, 180);
  
  if (sonar.ping_cm() < 5)
  {
    reverse();
    delay(200);
    rightTurn();
    delay(200);
  }
}

//neopixels
void lights(int RLED, int GLED, int BLED)
{
  for(int i = 0; i < 6; i++)
  {
    pixels.setPixelColor(i, pixels.Color(RLED, GLED, BLED));
    pixels.show();
  }
}

//experimental
void dance()
{
  digitalWrite(RPin1, HIGH);
  digitalWrite(RPin2, LOW);
  digitalWrite(LPin1, HIGH);
  digitalWrite(LPin2, LOW);
  analogWrite(enableR, random(0, 244));
  analogWrite(enableL, random(0, 244));
}

