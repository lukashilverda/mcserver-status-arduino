<h1 align="center">Minecraft server ESP32 status checker</h1>



Made by Lukas Hilverda



This project connects an ESP32 to Wi-Fi and fetches a JSON response from a server. It checks for an `"online"` field and prints the status to the Serial Monitor.

* [Features](#features)
* [Requirements](#requirements)
* [Setup](#setup)



## Features



\* Connects to Wi-Fi

\* Sends an HTTP GET request

\* Parses JSON using ArduinoJson

\* Prints online status



## Requirements



\* ESP32 board

\* Arduino IDE or PlatformIO

\* Libraries:

&nbsp; * WiFi.h

&nbsp; * HTTPClient.h

&nbsp; * ArduinoJson



## Setup



1\. Open the code in Arduino IDE.

2\. Fill in your Wi-Fi credentials and server URL:

```cpp

 const char\* ssid = "YOUR_SSID";

 const char\* password = "YOUR_PASSWORD";

 String url = "https://api.mcsrvstat.us/3/YOUR_SERVER_IP";

```



