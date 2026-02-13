# mcserver-status-arduino

Een compacte Arduino/ESP32-sketch die de online status van een Minecraft-server opvraagt via een HTTP-API en het resultaat toont in de Serial Monitor.

## Over het project

Dit project is bedoeld als eenvoudige basis om:

- een ESP32 met wifi te verbinden;
- een HTTP `GET`-request uit te voeren;
- JSON te parseren met `ArduinoJson`;
- de `online`-status van een Minecraft-server uit te lezen.

De sketch gebruikt hiervoor de API-respons van bijvoorbeeld `mcsrvstat.us`.

## Functionaliteit

- Verbindt met een opgegeven wifi-netwerk.
- Vraagt JSON-data op van een opgegeven endpoint.
- Controleert of het veld `online` aanwezig is.
- Print de status (online/offline) in de Serial Monitor.
- Print duidelijke foutmeldingen bij netwerk-, HTTP- of parsefouten.

## Benodigdheden

### Hardware

- ESP32-board
- USB-kabel

### Software

- Arduino IDE (of PlatformIO)
- Board package voor ESP32
- Libraries:
  - `WiFi.h`
  - `HTTPClient.h`
  - `ArduinoJson`

## Installatie

1. Clone of download deze repository.
2. Open `code.ino` in de Arduino IDE.
3. Installeer (indien nodig) de ESP32 board support en `ArduinoJson`.
4. Selecteer het juiste board en de juiste COM-poort.

## Configuratie

Vul in `code.ino` de volgende waarden in:

```cpp
const char* ssid = "JOUW_WIFI_NAAM";
const char* password = "JOUW_WIFI_WACHTWOORD";
String url = "https://api.mcsrvstat.us/3/jouw.server.domein.of.ip";
```

Voorbeeld:

```cpp
String url = "https://api.mcsrvstat.us/3/play.example.net";
```

## Gebruik

1. Upload de sketch naar je ESP32.
2. Open de Serial Monitor op `115200` baud.
3. Wacht tot de wifi-verbinding tot stand komt.
4. Lees de output:
   - `Online status: 1` betekent online.
   - `Online status: 0` of `Server is offline` betekent offline/niet beschikbaar.

## Structuur

- `code.ino`: hoofdsketch met wifi-verbinding, HTTP-request en JSON-verwerking.
- `README.md`: documentatie en gebruiksinstructies.

## Bekende aandachtspunten

- HTTPS werkt alleen correct als de ESP32-omgeving en certificaatafhandeling goed zijn ingesteld.
- De huidige sketch vraagt de status één keer op in `setup()`. Wil je periodieke updates, dan kun je `getJsonData()` op interval in `loop()` aanroepen.
- `DynamicJsonDocument(1024)` is een vaste buffer; vergroot deze als je grotere JSON-responses verwacht.

## Mogelijke uitbreidingen

- Periodiek pollen met een instelbaar interval.
- Weergave op een OLED/TFT-scherm.
- LED-indicatie voor online/offline.
- Automatische reconnect-logica voor wifi.
- Ondersteuning voor meerdere servers.

## Licentie

Dit project valt onder de MIT-licentie. Zie `LICENSE` voor details.
