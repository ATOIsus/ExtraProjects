void setup() {
  pinMode(A2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A2);

  Serial.print("$");
  Serial.println(val);

  delay(20);

}
