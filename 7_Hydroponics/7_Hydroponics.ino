
const int turbityIn = A0;

const int dhtIn = A1;

const int poIn = A3;
const int t1In = A4;
const int t2In = A5;


int val1;
int val2;
int val3;
int val4;
int val5;

void setup() {
  Serial.begin(9600);
}

void loop() {

  val1 = analogRead(turbityIn);
  val2 = analogRead(dhtIn);
  val3 = analogRead(poIn);
  val4 = analogRead(t1In);
  val5 = analogRead(t2In);
  
  
  Serial.println((String)"$" + val1 + "$" + val2 + "$" + val3 + "$" + val4+"$"+ val5+"$");
}
