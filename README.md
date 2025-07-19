<h1 align="center">ESP32 WiFi JSON Status Checker</h1>



> Made by Lukas Hilverda



This project is a simple ESP32 program that connects to a Wi-Fi network and fetches a JSON response from a specified URL. It parses the JSON and checks for an `"online"` field, then prints the result to the serial monitor.



&nbsp;	\* \[Features](#features)

&nbsp;	\* \[Requirements](#requirements)

&nbsp;	\* \[Installation](#installation)



\## Features



\* Connects to a Wi-Fi network

\* Sends an HTTP GET request to a server

\* Parses JSON response using ArduinoJson

\* Checks if a device or service is online

\* Output shown via Serial Monitor



\## Requirements



\* ESP32 board

\* Arduino IDE or PlatformIO

\* Libraries:

&nbsp;	\* \[WiFi.h](https://www.arduino.cc/en/Reference/WiFi)

&nbsp;	\* \[HTTPClient.h](https://www.arduino.cc/en/Reference/HTTPClient)

&nbsp;	\* \[ArduinoJson](https://arduinojson.org/)



\## Installation



1\. Clone or download the project.

2\. Open the code in Arduino IDE.

3\. Fill in your Wi-Fi credentials and the server URL:

   ```cpp

   const char\* ssid = "YOUR\_WIFI\_SSID";

   const char\* password = "YOUR\_WIFI\_PASSWORD";

   String url = "http://your-server.com/status";

