int readValueOfA0 = 0;

int writeValueFromA0 = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT); //first led
  pinMode(10, OUTPUT); //second led
  pinMode(11, OUTPUT); //third led
  Serial.begin(9600); // biti per second (9600 or 115,200 bits mostly used)
}

void loop() {
  // put your main code here, to run repeatedly:
  readValueOfA0 = analogRead(A0); //read A0 value 0 to 1023 (0V to 5V)
  writeValueFromA0 = readValueOfA0 / 4; //we devide by 4 bcs analog has 10 bits while digital PWM has 8 bits
  int writeValueOfLed2 = 0;
  int writeValueOfLed3 = 0;
  if(readValueOfA0 < 341){
    analogWrite(9, writeValueFromA0*3);
    analogWrite(10, 0);
    analogWrite(11, 0);
  }
  if(readValueOfA0 > 341 && readValueOfA0 < 682){
    writeValueOfLed2 = 3*(writeValueFromA0-85);
    analogWrite(10, writeValueOfLed2);
    analogWrite(11, 0);
  }
  if(readValueOfA0 > 682){
    writeValueOfLed3 = 3*(writeValueFromA0 - 170);
    analogWrite(11, writeValueOfLed3);
  }
  Serial.print(readValueOfA0);
  Serial.print("; ");
  Serial.print(readValueOfA0/6);
  Serial.print("; ");
  Serial.print(readValueOfA0/12);
  Serial.print("; ");
  Serial.print(writeValueFromA0);
  Serial.print(".\n");

}
