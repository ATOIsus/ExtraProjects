
int val1 = 1;
int val2 = 2;
int val3 = 3;
int val4 = 4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println((String)"$"+val1+"$"+val2+"$"+val3+"$"+val4);
}
