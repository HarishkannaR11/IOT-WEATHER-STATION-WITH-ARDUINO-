
# 🌦️ IoT Weather Station with Arduino

An IoT-based real-time weather monitoring system developed using Arduino and environmental sensors to track key weather parameters such as **temperature**, **humidity**, and **atmospheric pressure**. This project integrates hardware with IoT capabilities and includes an Android application for remote data visualization.

---

## 📌 Project Overview

This weather station gathers environmental data using sensors and transmits the information over Wi-Fi using the ESP8266 module (or NodeMCU). The data can be viewed via serial monitor, LCD/OLED display, or a custom-built Android application (`weather.apk` included in repo).

---
## Block diagram:
![image](https://github.com/user-attachments/assets/24ca0f7d-50cc-46f7-a3b6-eec3c3fe0e72)

## Circuit diagram:
![image](https://github.com/user-attachments/assets/88a18d5c-0f4d-4e96-8b9c-3ff95be7fd02)

## ⚙️ Features

- 🌡️ Temperature & Humidity Monitoring (DHT11 / DHT22)
- 📈 Atmospheric Pressure Monitoring (BMP180 / BME280 - optional)
- 📡 Real-time data transmission using Wi-Fi
- 📱 Custom Android App for monitoring (APK included)
- 🖥️ Data display via LCD / OLED screen
- 🔌 Power via USB or external source

---

## 📁 Repository Contents

```bash
📦 IOT-WEATHER-STATION-WITH-ARDUINO
 ┣ 📜 (Review 1)ARUDINO BASED WEATHER STATION.docx
 ┣ 📜 (Review 2)ARUDINO BASED WEATHER STATION.docx
 ┣ 📜 Report.docx
 ┣ 📜 README.md
 ┣ 📱 weather.apk
 ┣ if_you_want_to_run_on_Blynk.cpp
 ┣ Synonpsis.docx




---

## 🛠️ Hardware Requirements

| Component            | Quantity | Purpose                              |
|----------------------|----------|--------------------------------------|
| Arduino UNO / NodeMCU| 1        | Main microcontroller                 |
| DHT11 / DHT22        | 1        | Temperature & Humidity Sensor        |
| BMP180 / BME280      | Optional | Pressure & Altitude Sensor           |
| ESP8266 Module       | 1        | Wi-Fi Connectivity                   |
| OLED / LCD Display   | 1        | Local Data Display                   |
| Breadboard & Wires   | As needed| Circuit Setup                        |

---

## 🧪 How to Run

1. **Connect the circuit**  
   Wire the components as per your circuit diagram using a breadboard. Ensure secure connections.

2. **Upload the Arduino sketch**  
   Open the `.ino` file in the Arduino IDE, select the correct board and port, then upload.

3. **Update Wi-Fi credentials**  
   For NodeMCU/ESP8266 users, modify these lines in your sketch:
   ```cpp
   const char* ssid = "Your_WiFi_SSID";
   const char* password = "Your_WiFi_Password";

