
int smth = 2;
int smth1 = 3;
int smth2 = 4;
int smth3 = 5;

void setup() {
  pinMode(smth, OUTPUT);
  pinMode(smth1, OUTPUT);
  pinMode(smth2, OUTPUT);
  pinMode(smth3, OUTPUT);  
  
}

void loop() {
  digitalWrite(smth, HIGH);
  digitalWrite(smth1, HIGH);
  digitalWrite(smth2, HIGH);
  digitalWrite(smth3, HIGH);
  delay(500);


  digitalWrite(smth, LOW);
  digitalWrite(smth1, LOW);
  digitalWrite(smth2, LOW);
  digitalWrite(smth3, LOW);  
  delay(500);
}
