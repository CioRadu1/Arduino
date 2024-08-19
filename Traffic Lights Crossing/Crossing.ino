void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int crossingButton = digitalRead(2);
  int pushedButton = 0;
  if(crossingButton != HIGH && pushedButton == 0){
      digitalWrite(5, LOW);
      digitalWrite(11, LOW);
      digitalWrite(3, HIGH);
      digitalWrite(12, HIGH);
    
  }else {
      pushedButton = 1;
      digitalWrite(3, LOW);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      delay(3000);
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
      delay(1000);
      digitalWrite(12, LOW);
      digitalWrite(11, HIGH);
      delay(10000);
      digitalWrite(11, LOW);
      delay(500);
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(11, LOW);
      delay(500);
      digitalWrite(11, HIGH);
      delay(500);
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      delay(3000);
      pushedButton = 0;
    }

}
