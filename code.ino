// Made by Lukas Hilverda
// MIT LICENSE
// https://github.com/lukashilverda/mcserver-status-arduino



#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = ""; // WiFi ssid
const char* password = ""; // WiFi password
String url = ""; // Server IP or URL

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Get JSON data
  getJsonData();
}

void loop() {
  // Nothing to do here
}

void getJsonData() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;


    // Start HTTP connection
    http.begin(url);

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      // Parse JSON
      DynamicJsonDocument jsonBuffer(1024); // Adjust the size according to your JSON
      DeserializationError error = deserializeJson(jsonBuffer, http.getStream());

      if (!error) {
        // Check if "online" field is present
        if (jsonBuffer.containsKey("online")) {
          // Get the value of "online"
          bool isOnline = jsonBuffer["online"];
          Serial.print("Online status: ");
          Serial.println(isOnline);
        } else {
          Serial.println("Server is offline");
        }
      } else {
        Serial.print("Error parsing JSON: ");
        Serial.println(error.c_str());
      }
    } else {
      Serial.print("HTTP error code: ");
      Serial.println(httpResponseCode);
    }

    // End HTTP connection
    http.end();
  } else {
    Serial.println("WiFi not connected");
  }
}
