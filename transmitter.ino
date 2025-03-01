#include <LoRa.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

#define SS 5
#define RST 14
#define DIO0 26

TinyGPSPlus gps;
#define gpsSerial Serial1  // Use Serial1 for GPS

void setup() {
    Serial.begin(115200);
    Serial.println("\n🚀 ESP32 Starting...");

    gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
    Serial.println("📡 GPS Initialized");
\
    Serial.println("🔄 Initializing LoRa...");
    LoRa.setPins(SS, RST, DIO0);
    delay(100);
    
    if (!LoRa.begin(433E6)) {
        Serial.println("❌ LoRa Initialization Failed! Check wiring.");
        while (1);
    }
    Serial.println("✅ LoRa Initialized");
}

void loop() {
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) {
            if (gps.location.isUpdated()) {
                
                float latitude = gps.location.lat();
                float longitude = gps.location.lng();
                float speed = gps.speed.kmph();

                
                String mapsURL = "https://www.google.com/maps?q=" + String(latitude, 6) + "," + String(longitude, 6);

                
                String dataToSend = String(latitude, 6) + "," + String(longitude, 6);


                sendLoRaMessage(dataToSend);
                
    
                Serial.println(dataToSend);
            }
        }
    }
}

void sendLoRaMessage(String message) {
    Serial.print("📡 Sending via LoRa: ");
    Serial.println(message);

    LoRa.beginPacket();
    LoRa.print(message);  
    LoRa.print("\n");
    LoRa.endPacket();
    
    Serial.println("✅ LoRa Message Sent!");
}
