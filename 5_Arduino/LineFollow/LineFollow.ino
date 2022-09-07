#define enA 9//Enable1 L298 Pin enA 
#define enB 3 //Enable2 L298 Pin enB 
#define in1 7 //Motor1  L298 Pin in1 
#define in2 6 //Motor1  L298 Pin in1 
#define in3 5 //Motor2  L298 Pin in1 
#define in4 4 //Motor2  L298 Pin in1 


#define R_S A0 //ir sensor Right
#define L_S A1 //ir sensor Left

void setup() { // put your setup code here, to run once

  pinMode(R_S, INPUT); // declare if sensor as input
  pinMode(L_S, INPUT); // declare ir sensor as input

  pinMode(enA, OUTPUT); // declare as output for L298 Pin enA
  pinMode(in1, OUTPUT); // declare as output for L298 Pin in1
  pinMode(in2, OUTPUT); // declare as output for L298 Pin in2
  pinMode(in3, OUTPUT); // declare as output for L298 Pin in3
  pinMode(in4, OUTPUT); // declare as output for L298 Pin in4
  pinMode(enB, OUTPUT); // declare as output for L298 Pin enB

  analogWrite(enA, 150); // Write The Duty Cycle 0 to 255 Enable Pin A for Motor1 Speed
  analogWrite(enB, 150); // Write The Duty Cycle 0 to 255 Enable Pin B for Motor2 Speed
  delay(1000);
}
void loop() {

  digitalWrite(in1, HIGH); //Right Motor forword Pin

  
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
    forword(); //if Right Sensor and Left Sensor are at White color then it will call forword function
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)) {
    turnRight(); //if Right Sensor is Black and Left Sensor is White then it will call turn Right function
  }

  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)) {
    turnLeft(); //if Right Sensor is White and Left Sensor is Black then it will call turn Left function
  }

  if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)) {
    Stop(); //if Right Sensor and Left Sensor are at Black color then it will call Stop function
  }
}

void forword() { //forword
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin
}

void turnRight() { //turnRight
  digitalWrite(in1, LOW);  //Right Motor forword Pin
  digitalWrite(in2, HIGH); //Right Motor backword Pin
  digitalWrite(in3, LOW);  //Left Motor backword Pin
  digitalWrite(in4, HIGH); //Left Motor forword Pin
}

void turnLeft() { //turnLeft
  digitalWrite(in1, HIGH); //Right Motor forword Pin
  digitalWrite(in2, LOW);  //Right Motor backword Pin
  digitalWrite(in3, HIGH); //Left Motor backword Pin
  digitalWrite(in4, LOW);  //Left Motor forword Pin
}

void Stop() { //stop
  digitalWrite(in1, LOW); //Right Motor forword Pin
  digitalWrite(in2, LOW); //Right Motor backword Pin
  digitalWrite(in3, LOW); //Left Motor backword Pin
  digitalWrite(in4, LOW); //Left Motor forword Pin
}
