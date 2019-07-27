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

  total = trVal + tlVal + brVal + blVal;
  Serial.println(total);
  total = constrain(total,50,250);
  total = map(total,50,250,0,255);
  analogWrite(led11,total);  

}
