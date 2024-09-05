#include <Servo.h>

Servo wiperServo;
const int onButtonPin = 3;
const int LEDPin = 9;
const int servoPin = 11;
const int potPin = A0;

int wiperState= 0;
int potValue = 0;
int delayTime = 0;
long timerCount = 0;
int buttonState = 0;
int lastButtonState = 0;
int servoAngle = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(onButtonPin, INPUT);
  wiperServo.attach(servoPin);
  pinMode(LEDPin, OUTPUT);

  Serial.begin (9600);

  wiperServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  potValue = analogRead(potPin);

  Serial.print(wiperState);
  Serial.print(" : ");
  Serial.println(potValue);

      switch(wiperState){
        case 0 :
            servoAngle = 0;
            delayTime = 1000;
          break;
        case 1: 
            if (servoAngle == 0) {servoAngle = 179;}
            else {servoAngle = 0;}
            delayTime = 1000;
          break;
        case 2:
            if (servoAngle == 0) {
              servoAngle = 179;
              delayTime = 1000;
            }
            else {
              servoAngle = 0;
              delayTime = map(potValue, 0, 1023, 1000, 6000);
            }
          break; 
        case 3:
            digitalWrite(LEDPin, HIGH);

            for(int i=0; i<5; i++) {
              wiperServo.write(179);
              delay(1000);
              wiperServo.write(0);
              delay(1000);
            }
            digitalWrite(LEDPin,LOW);
            wiperState = 0;
          break;    
      }
      wiperServo.write(servoAngle);
      timerCount = millis();
      while (millis() < timerCount + delayTime) {
          buttonState = digitalRead(onButtonPin); 
          if (buttonState != lastButtonState) {             
              lastButtonState = buttonState;

              if (digitalRead(onButtonPin) == HIGH) {
                  wiperState = wiperState + 1;
                  if (wiperState >= 4) {wiperState = 0;}
                  delay(200);
              }
          }
      }
}
