#include <Servo.h>

const int sensorPin = A0;
const int servoPin = 3;

int lightAmount = 0;
int servoAngle = 0;
int lightLow = 1023;
int lightHigh = 0;
int angleLow = 180;
int angleHigh = 0;
int increment = 5;

Servo myServo; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
  myServo.write(servoAngle);
  delay(1000);

}

void collectData(){
  myServo.write(servoAngle);
  delay(500);
 
  lightAmount = analogRead(sensorPin);
  
  if (lightAmount > lightHigh){
    lightHigh = lightAmount;
    angleHigh = servoAngle;
  }

  if (lightAmount < lightLow) {
    lightLow = lightAmount;
    angleLow = servoAngle;
  }
}

void printData() {

  Serial.print("Angle: ");
  Serial.print(servoAngle);
  Serial.print("     Light Intensity: ");
  Serial.print(lightAmount);
  Serial.print("   High: ");
  Serial.print(lightHigh);
  Serial.print(" at ");
  Serial.print(angleHigh);
  Serial.print(" degrees   Low: ");
  Serial.print(lightLow);
  Serial.print(" at ");
  Serial.print(angleLow);
  Serial.println(" degrees");
}

void loop() {

    for (servoAngle = 0; servoAngle <= 180; servoAngle = servoAngle + increment){
      collectData();
      printData();
    }
    for (servoAngle = 180; servoAngle >= 0; servoAngle = servoAngle - increment){
      collectData();
      printData();
    }
}
