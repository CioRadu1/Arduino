const int notePin = A0;
const int togglePin = 3;
const int buzzerPin = 8;

int keyVal = 0;
int key = 0;
int switchState = 0; 
int note = 0;     
int oldNote = 0; 

int notes[] = {262, 294, 330, 349, 392, 440, 494, 523};

void setup() {

    pinMode(togglePin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
  keyVal = analogRead(notePin); 
  switchState = digitalRead(togglePin);

  if (keyVal > 1005) {key = 1;} 
  else if (keyVal > 900) {key = 2;} 
  else if (keyVal > 800) {key = 3;}  
  else if (keyVal > 400) {key = 4;}  
  else {key = 0;} 

  switch (switchState) {
    case 0:
        note = key - 1;
    break;
    
    case 1:
        note = key + 3;
    break;
  }

  if (key > 0) {
    tone(buzzerPin, notes[note]);
  }
  else {
    noTone(buzzerPin);
  }

  if (note != oldNote) {
    Serial.println("toggle state : analog value : note");
    Serial.print(switchState);
    Serial.print(" : ");
    Serial.print(keyVal);
    Serial.print(" : ");
    Serial.println(note);
  }
  oldNote = note;
}
