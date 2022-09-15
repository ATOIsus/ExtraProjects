

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"

#include "Adafruit_MQTT_Client.h"

#include <DHT.h>

int DHTPIN = D3;
#define DHTTYPE   DHT22


DHT dht(DHTPIN, DHTTYPE);

int relayMotor = D0;

int switchBtn = D1;
int buttonState = LOW;

int dhtIn = D3;
float dhtTemp;
float dhtHumidity;

int moistureIn = A0;
int moistureValue;


#define WLAN_SSID     "IOT"     // replace with your wifi ssid and wpa2 key
#define WLAN_PASS     "cecurity"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883

#define AIO_USERNAME    "SmthOnee"   // Your Adafruit IO Username
#define AIO_KEY    "aio_HQQU37od5QpaThsHvdfvN1jjwAUA" // Adafruit IO AIO key


WiFiClient client;


// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe LED = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay1");
//Adafruit_MQTT_Subscribe Motor = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME"/feeds/Relay4");

Adafruit_MQTT_Publish Moisture = Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME "/feeds/SoilMoisture"); 
Adafruit_MQTT_Publish Temperature = Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME "/feeds/Temperature");
Adafruit_MQTT_Publish Humidity = Adafruit_MQTT_Publish(&mqtt,AIO_USERNAME "/feeds/Humidity");


void MQTT_connect();

void setup()
{
  Serial.begin(115200);

  dht.begin();

  pinMode(relayMotor, OUTPUT);
  pinMode(switchBtn, INPUT);
  pinMode(moistureIn, INPUT);


  Serial.println("Connecting to ");
  Serial.println(WLAN_SSID);


//  WiFi.begin(WLAN_SSID, WLAN_PASS);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

// Setup MQTT subscription for onoff feed.
  mqtt.subscribe(&LED);
  mqtt.subscribe(&Motor);

}


void loop() {

  MQTT_connect();

  moistureValue = analogRead(moistureIn);

  dhtHumidity = dht.readHumidity();
  dhtTemp = dht.readTemperature();

  Temperature.publish(dhtTemp);
  Humidity.publish(dhtHumidity);
  Moisture.publish(moistureValue);

  Serial.println((String)"Moisture Value: " + moistureValue  + " ,DHT Temp:  " + dhtTemp + " ,DHT Humidity:  " + dhtHumidity);

  buttonState = digitalRead(switchBtn);
  if(buttonState == HIGH){
    digitalWrite(relayMotor, HIGH);
    delay(50);
  }else{
    digitalWrite(relayMotor, LOW);
    delay(50);
  }

}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;

  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}
