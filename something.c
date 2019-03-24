/*
  Arduino Code not C. 
  Createed By Nam Le on 3-24-19
*/
#include <Servo.h> 

int servo1Pin = 3;
int servo2Pin = 2;
 
// Create a servo object 
Servo Servo1; 
Servo Servo2;
int servo1Val = Servo1.read();
int servo2Val = Servo2.read();

// LDR pins
int tr = A0;
int tl = A1;
int br = A2;
int bl = A3;
// LDR Values
int trVal = 0;
int tlVal = 0;
int brVal = 0;
int blVal = 0;

int led11 = 11;

//total of LDR values
int total;

// Sides of crosshair; The sum of two LDRs from one side
int top = 0;
int bot = 0;
int left = 0;
int right = 0;

void setup() {
  Servo1.attach(servo1Pin); 
  Servo2.attach(servo2Pin);
  pinMode(tr, INPUT);
  pinMode(tl, INPUT);
  pinMode(br, INPUT);
  pinMode(bl, INPUT);
  Serial.begin(9600);
}

void loop() {
  delay(20);
  trVal = analogRead(A0);
  tlVal = analogRead(A1);
  brVal = analogRead(A2);
  blVal = analogRead(A3);
  /*
  Serial.println(trVal);
  Serial.println(tlVal);
  Serial.println(brVal);
  Serial.println(blVal);
  */ 
  /*
  servo1Val = Servo1.read();
  servo2Val = Servo2.read();
  
  top = trVal + tlVal;
  bot = brVal + blVal;
  left = tlVal + blVal;
  right = trVal + brVal;

  
  // threshold to cause change up and down is 100
  if(top > bot && top - bot > 100) {
      //Serial.println("top");
      //Serial.println(servo1Val);  
      if(servo1Val < 174) {
          Servo1.write(servo1Val + 1);          
      }
  } else if(bot - top > 100) {
      //Serial.println("bottom");
      //Serial.println(servo1Val);
      if(servo1Val > 4 ) {
          Servo1.write(servo1Val - 1);          
      }
  }
  
  if(left > right && left - right > 100) {
    //Serial.println("left");
    //Serial.println(servo2Val);
    if(servo2Val < 176) {
      Servo2.write(servo2Val + 1);
    }
  } else if(right - left > 100) {
    //Serial.println("right");
    //Serial.println(servo2Val);
    if(servo2Val > 4) {
      Servo2.write(servo2Val - 1);
    }
  }
  */

  total = trVal + tlVal + brVal + blVal;
  Serial.println(total);
  total = constrain(total,50,250);
  total = map(total,50,250,0,255);
  analogWrite(led11,total);
  

  Serial.println(" ");
  
  

}