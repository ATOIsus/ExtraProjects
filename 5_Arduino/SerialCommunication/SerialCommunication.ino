
#include <SoftwareSerial.h>

//Ardunio

SoftwareSerial s(8, 9);

void setup() {
  Serial.begin(115200);
}

void loop() {
  int data = 50;

  Serial.println(99);
  
}



//Node MCU
int data;
//
//void setup() {
//  Serial.begin(115200);
//}
//
//void loop() {
//    Serial.println(Serial.read());
//    delay(200);
//  }
