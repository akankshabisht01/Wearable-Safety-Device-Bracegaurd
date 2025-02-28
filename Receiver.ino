#include <SPI.h>
#include <LoRa.h>

#define SS 10
#define RST 9
#define DIO0 2

void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("🚀 LoRa Receiver");
  LoRa.setPins(SS, RST, DIO0);

  if (!LoRa.begin(433E6)) {
    Serial.println("❌ LoRa Initialization Failed!");
    while (1);
  }

  LoRa.setSyncWord(0xF3);
  Serial.println("✅ LoRa Initialized. Waiting for messages...");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("📩 Received Packet: ");
    while (LoRa.available()) {
      Serial.print((char)LoRa.read());
    }
    Serial.println();
  }
}

