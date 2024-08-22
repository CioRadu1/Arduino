int timesPressed = 0;
int stageCheck1 = 0;
int stageCheck2 = 0;

void FirstShowCode (int pin){
    int i = 0;
    int reverse = 0;
    int pressed = 0;
    while (reverse != 1){
      if(digitalRead(2) == HIGH){
        timesPressed = 1;
        pressed = 1;
        break;
      }
      analogWrite(pin, i);
      i++;
      if (i == 256){
        reverse = 1;
      }
      delay(10);
    }
    while (i != 0){
      if(pressed != 0){
        break;
      }
      if(digitalRead(2) == HIGH){
        timesPressed = 1;
        break;
      }
      i--;
      analogWrite(pin, i);
      delay(10);
    }
    delay(500);
}

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

  pinMode(2, INPUT);\
  Serial.begin(9600);

}

void loop() {

  int readPin2 = digitalRead(2);
  if (timesPressed >= 3) {timesPressed = 0;}
  
  switch(timesPressed){

      case 0: 
            digitalWrite(11, LOW);
            digitalWrite(9, LOW);
            digitalWrite(10, LOW);
            //Show for the red led
            FirstShowCode(11);
            if (timesPressed == 1){
              stageCheck1 = 1;
              break;
            }
            //Show for the green led
            FirstShowCode(10);
            if (timesPressed == 1){
              stageCheck1 = 1;
              break;
            }
            //Show for the blue led
            FirstShowCode(9);
            if (timesPressed == 1){
              stageCheck1 = 1;
              break;
            } 
          break;
      case 1:
            digitalWrite(10, LOW);
            digitalWrite(11, HIGH);
            if(digitalRead(2) == HIGH && stageCheck2 == 0 && stageCheck1 == 1){
              timesPressed = 2;
              stageCheck2 = 1;
              break;
            }
            digitalWrite(9,HIGH);
            delay(100);
            digitalWrite(11, LOW);
            digitalWrite(9, LOW);
            if(digitalRead(2) == HIGH && stageCheck2 == 0 && stageCheck1 == 1){
              timesPressed = 2;
              stageCheck2 = 1;
              break;
            }
            digitalWrite(10, HIGH);
            delay(100);
        break;
      case 2:
            digitalWrite(11, HIGH);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            digitalWrite(10, HIGH);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            digitalWrite(9, HIGH);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            digitalWrite(11, LOW);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            digitalWrite(10, LOW);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            digitalWrite(9, LOW);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
            delay(100);
            if(digitalRead(2) == HIGH && stageCheck2 == 1 && stageCheck1 == 1){
              timesPressed = 3;
              stageCheck1 = 0;
              stageCheck2 = 0;
              break;
            }
        break;
  }
  delay(200);

}
