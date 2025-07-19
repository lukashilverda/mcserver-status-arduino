# \# 🌐 ESP32 JSON Status Checker

# 

# This project allows an \*\*ESP32\*\* to connect to a Wi-Fi network, send an \*\*HTTP GET request\*\* to a specified URL, and parse the JSON response using the powerful \*\*ArduinoJson\*\* library. It’s ideal for checking online services like a \*\*Minecraft server\*\*, a REST API status, or any endpoint that returns JSON data.

# 

# ---

# 

# \## 🚀 Features

# 

# \- 📡 Connects to any Wi-Fi network

# \- 🌍 Makes HTTP requests to any given API or server URL

# \- 📦 Parses and processes JSON data

# \- ✅ Reads the `online` key from the response and displays it via the Serial Monitor

# 

# ---

# 

# \## 🧰 Requirements

# 

# \- ESP32 development board

# \- Arduino IDE or PlatformIO

# \- Active Wi-Fi connection

# \- A valid URL that returns JSON data (e.g., a Minecraft server status API)

# 

# ---

# 

# \## 📜 Example Use Case

# 

# Using the API from \[mcsrvstat.us](https://api.mcsrvstat.us), you can check the online status of a Minecraft server:

# 

# ```cpp

# String url = "https://api.mcsrvstat.us/3/mc.example.com";



