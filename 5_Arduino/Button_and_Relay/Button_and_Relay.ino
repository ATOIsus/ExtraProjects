
int smth = 2;
int smth1 = 3;
int smth2 = 4;
int smth3 = 5;

#define SwitchPin1 10  //SD3

void setup() {
  Serial.begin(9600);
  pinMode(smth, OUTPUT);
  pinMode(smth1, OUTPUT);
  pinMode(smth2, OUTPUT);
  pinMode(smth3, OUTPUT);
  pinMode(SwitchPin1, INPUT);
  
  
  pinMode(6, OUTPUT);
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

  int val = digitalRead(smth);
  int val1 = digitalRead(smth1);
  int val2 = digitalRead(smth2);
  int val3 = digitalRead(smth3);

  int val4 = digitalRead(SwitchPin1);
  
  Serial.print(val);
  Serial.print(" ");

  Serial.print(val1);
  Serial.print(" ");

  Serial.print(val2);
  Serial.print(" ");

  Serial.print(val3);
  Serial.print(" ");

  Serial.print(val4);
  Serial.print(" ");

  Serial.println(" ");

  delay(200);
                 
     
}
