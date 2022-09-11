
int val1 = 1;
int val2 = 2;
float val3 = 3.9;
float val4 = 4.23;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println((String)"$" + val1 + "$" + val2 + "$" + val3 + "$" + val4+"$");
}
