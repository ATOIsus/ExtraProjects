

#include <SoftwareSerial.h>

//Ardunio

//SoftwareSerial s(5, 6);
//
//void setup() {
//  s.begin(9600);
//}
//
//void loop() {
//  int data = 50;
//  if (s.available() > 0) {
//    char c = s.read();
//    if (c == 's') {
//      s.write(data);
//    }
//  }
//}



//Node MCU
SoftwareSerial s(D6, D5);
int data;

void setup() {
  s.begin(9600);
  Serial.begin(9600);
}

void loop() {
  s.write("s");
  if (s.available() > 0) {
    data = s.read();
    Serial.println(data);
    delay(200);
  }
}
