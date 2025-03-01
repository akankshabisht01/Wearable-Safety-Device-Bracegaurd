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



## Wearable Safety Device - LoRa GPS Receiver 🚀  

## Overview  
This Arduino Uno-based LoRa Receiver listens for incoming GPS location data and displays it on a web page with a real-time map and the Serial Monitor. It enables real-time tracking and emergency response without requiring an internet connection.  

## Features  
✅ Receives real-time GPS location via LoRa  
✅ Displays location on a web page with Google Maps  
✅ Shows received data on Serial Monitor for debugging  
✅ Works without internet dependency  
✅ Low-power, long-range communication  

## Hardware  
- Arduino Uno (Microcontroller)  
- LoRa RA-02 Module (Long-range communication)  

## Connections  
Arduino Uno | LoRa  
------------|------  
10          | NSS  
9           | RST  
2           | DIO0  
3.3V        | VCC  
GND         | GND  

## Setup & Deployment  
1. Install Libraries: LoRa (via Arduino IDE)  
2. Upload Code: Flash Arduino Uno with the provided receiver script  
3. Open Serial Monitor (Baud: 115200) to check incoming data  
4. Web Page Setup: Display location on a real-time map  
5. Verify LoRa Data: Ensure messages are received correctly  

## How It Works  
1. LoRa receiver listens for incoming GPS data  
2. Received data is displayed on the Serial Monitor  
3. The location is plotted on a web page with Google Maps  
4. Emergency responders can act based on real-time tracking  

## Why This Project?  
🔹 Hackathon-Ready: Efficient and impactful  
🔹 No Internet Dependency: Works in remote areas  
🔹 Women’s Safety Focused: Enables real-time emergency tracking  


## As this is our 1st prototype in futuer we will use the different and compact modules
