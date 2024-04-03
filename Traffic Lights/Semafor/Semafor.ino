int led_rosu = 7;
int led_galben = 4;
int led_verde = 2;

void setup() {
  pinMode(led_rosu, OUTPUT);
  pinMode(led_galben, OUTPUT);
  pinMode(led_verde, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led_verde, HIGH);
  delay(120000);
  digitalWrite(led_verde, LOW);
  delay(500);
  digitalWrite(led_verde, HIGH);
  delay(500);
  digitalWrite(led_verde, LOW);
  delay(500);
  digitalWrite(led_verde, HIGH);
  delay(500);
  digitalWrite(led_verde, LOW);
  digitalWrite(led_galben, HIGH);
  delay(3000);
  digitalWrite(led_galben, LOW);
  digitalWrite(led_rosu, HIGH);
  delay(78000);
  digitalWrite(led_rosu, LOW);

}
