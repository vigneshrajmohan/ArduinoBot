#include <NewPing.h>
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

//ultrasonic
#define TRIGGER_PIN  4  
#define ECHO_PIN     5  
#define MAX_DISTANCE 400 

// Left motor pins
#define enableL 6     
#define LPin1 7       
#define LPin2 8       

// Right motor pins
#define enableR 11    
#define RPin1 9      
#define RPin2 10     

//neopixel lights
#define PIN            12
#define NUMPIXELS      6

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int rightspeed = 200;
int leftspeed = 200;
int response = 1;
int ledPin = 13;
int state = 0;
int flag = 0;
boolean condit = true;
int trigPin = 4;
int echoPin = 5;
long duration;
int distance;

void setup()
{
  Serial.begin (9600);
  // motors
  pinMode(enableR, OUTPUT);
  pinMode(enableL, OUTPUT);
  pinMode(RPin1, OUTPUT);
  pinMode(RPin2, OUTPUT);
  pinMode(LPin1, OUTPUT);
  pinMode(LPin2, OUTPUT);
  
  //LED Test
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  //Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //neopixels
  pixels.begin();

}

void loop()
{
  if (Serial.available() > 0) 
  {
    state = Serial.read();
    flag = 0;
  }

  //use switch case in next version

  if (state == '0')
  {
    condit = false;
    digitalWrite(ledPin, LOW);

    if (flag == 0)
    {
      Serial.println("STOP");
      flag = 1;
      motorsOff();
      lights(0, 0, 0);
      //Serial.begin(9600);
    }
  }

  else if (state == '1') 
  {
    digitalWrite(ledPin, HIGH);
    lights(200, 0, 0);

    if (flag == 0) 
    {
      Serial.println("forward");
      condit = true;
      flag = 1;
      forward();
    }
  }

  else if (state == '2')
  {
    digitalWrite(ledPin, HIGH);
    if (flag == 0)
    {
      Serial.println("backward");
      condit = true;
      flag = 1;
      lights(200, 200, 0);
      reverse();
    }
  }

  else if (state == '3')
  {
    digitalWrite(ledPin, HIGH);
    if (flag == 0)
    {
      Serial.println("right turn");
      condit = true;
      flag = 1;
      lights(0, 200, 0);
      rightTurn();
    }
  }

  else if (state == '4')
  {
    digitalWrite(ledPin, HIGH);
    if (flag == 0)
    {
      Serial.println("random forward");
      condit = true;
      flag = 1;
      lights(200, 0, 200);
      randRun();
    }
  }

  else if (state == '5')
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("free run");
    if (flag == 0)
    {
      lights(0, 0, 200);
      freeRun();
    }
  }

  else if (state == '6')
  {
    digitalWrite(ledPin, HIGH);
    if (flag == 0)
    {
      Serial.println("lights");
      condit = true;
      flag = 1;

      lights(0, 100, 200);

    }
  }
}
