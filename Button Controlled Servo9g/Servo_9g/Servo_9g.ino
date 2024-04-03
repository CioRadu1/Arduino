#include <Servo.h>
Servo servo;

const int nDegrees = 2;
const int zDegrees = 4;
const int fvDegrees = 7;
const int tsdDegrees = 12;

int nDState = 0;
int zState = 0;
int fvState = 0;
int tsdState = 0; 

int angle = 0;
void setup() {
  Serial.begin(9600);
  servo.attach(9);
  servo.write(angle);

  pinMode(nDegrees, INPUT);
  pinMode(zDegrees, INPUT);
  pinMode(fvDegrees, INPUT);
  pinMode(tsdDegrees, INPUT);
}
void loop() 
{ 
  nDState = digitalRead(nDegrees);
  zState = digitalRead(zDegrees);
  fvState = digitalRead(fvDegrees);
  tsdState = digitalRead(tsdDegrees);
  if(nDState == HIGH){
    servo.write(90);
  }
  else if (zState == HIGH){
    servo.write(0);
  }
  else if (fvState == HIGH){
    servo.write(45);
  }
  else if(tsdState == HIGH){
    servo.write(180);
  }

}