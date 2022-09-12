
int relayMotor = 2;
int relayLight = 3;

int dhtIn = 6;
int dhtValue;

int moistureIn = A0;
int moistureValue;

void setup() {
  pinMode(relayMotor, OUTPUT);
  pinMode(relayLight, OUTPUT);

  pinMode(dhtIn, INPUT);
  pinMode(moistureIn, INPUT);
}

void loop() {

  moistureValue = analogRead(moistureIn);
  dhtValue = digitalRead(dhtIn);

  digitalWrite(relayMotor, HIGH);
  digitalWrite(relayLight, HIGH);
  delay(5000);


  digitalWrite(relayMotor, LOW);
  digitalWrite(relayLight, LOW);
  delay(5000);

}
