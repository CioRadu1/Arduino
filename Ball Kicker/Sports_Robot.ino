#include <Servo.h>
Servo myServo;

const int potPin = A0;
const int buttonPin = 7;

int potValue = 0;
int servoAngle = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9); // ataseaza pe pin 9
  Serial.begin(9600);

}

void loop() {
  if(digitalRead(buttonPin) == HIGH){
    myServo.write(179);
  }
  else {
    potValue = analogRead(potPin);
    // map command can only work with integer values
    servoAngle = map(potValue, 0 , 1023, 0, 179);

    myServo.write(servoAngle);
  }
  // put your main code here, to run repeatedly:
  //Serial.print(potValue);
  //Serial.print(servoAngle);
  //Serial.print("\n\n");
  //delay(100); // the time needed to reach a position


}
