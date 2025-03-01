# Wearable-Safety-Device-Bracegaurd

# Wearable Safety Device - LoRa GPS Transmitter 🚀  

## Overview  
This ESP32-based LoRa Transmitter sends real-time GPS location using LoRa communication, ensuring emergency alerts without internet dependency. It’s designed for women’s safety, allowing rapid SOS transmission in critical situations.  

## Features  
✅ Real-time GPS tracking (Latitude, Longitude)  
✅ LoRa-based communication (No Internet needed)  
✅ Low-power, long-range transmission  
✅ Compact & wearable design  

## Hardware  
- ESP32-WROOM-32 (Microcontroller)  
- LoRa Module RA-02 (Long-range communication)  
- Neo 6m GPS Module (Location tracking)  

## Connections  
ESP32 | LoRa  | GPS  
------|------|------  
5     | NSS  | -    
14    | RST  | -    
26    | DIO0 | -    
16    | -    | TX  
17    | -    | RX  
3.3V  | VCC  | VCC  
GND   | GND  | GND  

## Setup & Deployment  
1. Install Libraries: LoRa, TinyGPS++ (via Arduino IDE)  
2. Upload Code: Flash ESP32 with the provided transmitter script  
3. Monitor Output: Open Serial Monitor (Baud: 115200)  
4. Verify LoRa Data: Ensure GPS coordinates are sent  

## How It Works  
1. GPS acquires real-time location  
2. ESP32 formats and transmits location data  
3. LoRa sends alerts to receiver station  
4. Police/emergency contacts receive live tracking info  

## Why This Project?  
🔹 Hackathon-Ready: Compact, efficient & real-world impact  
🔹 No Internet Dependency: Works in remote areas  
🔹 Women’s Safety Focused: Instant emergency response  
