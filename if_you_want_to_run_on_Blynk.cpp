#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BMP085_U.h>

// Wi-Fi & Blynk Credentials
char auth[] = "Your_Blynk_Auth_Token";
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";

// Sensor Pins
#define DHTPIN D2
#define DHTTYPE DHT11
#define RAIN_SENSOR_PIN A0

// Objects
DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085_Unified bmp = Adafruit_BMP085_Unified(10085);
BlynkTimer timer;

// Variables
float temperature, humidity, pressure, altitude, sealevelPressure;
int rainValue;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  dht.begin();
  if (!bmp.begin()) {
    Serial.println("Could not find a valid BMP180 sensor!");
    while (1);
  }

  timer.setInterval(3000L, sendSensorData);
}

void sendSensorData() {
  // DHT11 Data
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();

  // BMP180 Data
  sensors_event_t event;
  bmp.getEvent(&event);
  pressure = event.pressure;
  sealevelPressure = bmp.pressureToAltitude(1013.25, pressure); // assuming standard sea level pressure
  altitude = bmp.readAltitude();

  // Rain Sensor
  rainValue = analogRead(RAIN_SENSOR_PIN); // lower value = more rain
  rainValue = map(rainValue, 0, 1023, 100, 0); // inverse scale

  // Send to Blynk
  Blynk.virtualWrite(V1, temperature);
  Blynk.virtualWrite(V2, humidity);
  Blynk.virtualWrite(V3, pressure);
  Blynk.virtualWrite(V4, altitude);
  Blynk.virtualWrite(V5, rainValue);

  // Debug Serial Output
  Serial.println("========== Weather Data ==========");
  Serial.print("Temp: "); Serial.print(temperature); Serial.println(" °C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("Altitude: "); Serial.print(altitude); Serial.println(" m");
  Serial.print("Rain: "); Serial.print(rainValue); Serial.println(" %");
  Serial.println("===================================");
}

void loop() {
  Blynk.run();
  timer.run();
}
