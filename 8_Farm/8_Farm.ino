#include <DHT.h>

int DHTPIN = D3;
#define DHTTYPE   DHT22


DHT dht(DHTPIN, DHTTYPE);

int relayMotor = D0;
int relayLight = D1;

int dhtIn = D3;
float dhtTemp;
float dhtHumidity;

int moistureIn = A0;
int moistureValue;

void setup() {
  dht.begin();

  Serial.begin(9600);

  pinMode(relayMotor, OUTPUT);
  pinMode(relayLight, OUTPUT);

  pinMode(moistureIn, INPUT);
}

void loop() {

  moistureValue = analogRead(moistureIn);

  dhtHumidity = dht.readHumidity();
  dhtTemp = dht.readTemperature();

  Serial.println((String)"Moisture Value: " + moistureValue  + " ,DHT Temp:  " + dhtTemp + " ,DHT Humidity:  " + dhtHumidity);

  digitalWrite(relayMotor, HIGH);
  digitalWrite(relayLight, HIGH);
  delay(500);


  digitalWrite(relayMotor, LOW);
  digitalWrite(relayLight, LOW);
  delay(500);

}
