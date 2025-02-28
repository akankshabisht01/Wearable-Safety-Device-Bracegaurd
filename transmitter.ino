#define BLYNK_TEMPLATE_ID "Put Blynk Template ID"
#define BLYNK_TEMPLATE_NAME "esp32"
#define BLYNK_AUTH_TOKEN "Put yours Blynk Auth Token"

#include <LoRa.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_PRINT Serial  

#define SS 5
#define RST 14
#define DIO0 26

TinyGPSPlus gps;
HardwareSerial gpsSerial(1);  


const char* ssid = "Put Your WiFi Name";       
const char* password = "Put Your WiFI Password";    

BlynkTimer timer;


#define SWITCH_PIN 4   // Lift switch connected to GPIO 4

void setup() {
    Serial.begin(115200);
    Serial.println("\n🚀 ESP32 Starting...");

    
    gpsSerial.begin(9600, SERIAL_8N1, 16, 17);
    Serial.println("📡 GPS Initialized");

    
    Serial.println("🔄 Initializing LoRa...");
    LoRa.setPins(SS, RST, DIO0);
    delay(100);
    
    if (!LoRa.begin(433E6)) {
        Serial.println("❌ LoRa Initialization Failed! Check wiring.");
        while (1);
    }
    Serial.println("✅ LoRa Initialized");

    
    pinMode(SWITCH_PIN, INPUT_PULLUP);  

    
    Serial.println("🌍 Connecting to WiFi...");
    WiFi.begin(ssid, password);

    unsigned long startAttemptTime = millis();
    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < 5000) {  
        Serial.print(".");
        delay(500);
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n✅ WiFi Connected!");
    } else {
        Serial.println("\n❌ WiFi Connection Failed! Proceeding without WiFi.");
    }

    
    Serial.println("🔄 Connecting to Blynk...");
    Blynk.config(BLYNK_AUTH_TOKEN);
    Blynk.connect(3000); 

    if (Blynk.connected()) {
        Serial.println("✅ Blynk Connected!");
    } else {
        Serial.println("❌ Blynk Connection Failed! Proceeding without Blynk.");
    }
}

void loop() {
    if (Blynk.connected()) {
        Blynk.run();
    }
    timer.run();

    
    bool isEmergency = digitalRead(SWITCH_PIN) == LOW;

    if (isEmergency) {
        sendGPSData();  
    }

    delay(100);  
}

void sendGPSData() {
    while (gpsSerial.available() > 0) {
        if (gps.encode(gpsSerial.read())) {
            if (gps.location.isUpdated()) {
                
                float latitude = gps.location.lat();
                float longitude = gps.location.lng();
                float speed = gps.speed.kmph();

                
                String mapsLink = "https://www.google.com/maps?q=" + String(latitude, 6) + "," + String(longitude, 6);

                String dataToSend = "Lat: " + String(latitude, 6) + 
                                   ", Lon: " + String(longitude, 6) + 
                                   "HELP\n" + 
                                   "📍 Location: " + mapsLink;

                
                sendLoRaMessage(dataToSend);

                
                Serial.println(dataToSend);

                
                if (Blynk.connected()) {
                    Blynk.virtualWrite(V0, latitude);   
                    Blynk.virtualWrite(V1, longitude);  
                    Blynk.virtualWrite(V2, speed);      
                    Blynk.virtualWrite(V3, "HELP");     
                    Blynk.virtualWrite(V4, mapsLink);   
                    Serial.println("✅ GPS Data Sent to Blynk!");
                } else {
                    Serial.println("⚠️ Blynk Not Connected. Data Sent Only via LoRa.");
                }
            }
        }
    }
}

void sendLoRaMessage(String message) {
    Serial.print("📡 Sending via LoRa: ");
    Serial.println(message);

    LoRa.beginPacket();
    LoRa.print(message);
    LoRa.endPacket();
    
    Serial.println("✅ LoRa Message Sent!");
}

