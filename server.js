const { SerialPort } = require('serialport');
const WebSocket = require('ws');

const wss = new WebSocket.Server({ port: 8080 });

const port = new SerialPort({
    path: process.env.SERIAL_PORT || 'COM7',
    baudRate: 115200,
    autoOpen: false
});

port.open((err) => {
    if (err) {
        console.error("❌ Failed to open serial port:", err.message);
        return;
    }
    console.log("✅ Serial Port Opened");
});

let buffer = "";

port.on('data', (data) => {
    buffer += data.toString();  // Append incoming data

    // Check for complete line
    if (buffer.includes("\n")) {  
        let messages = buffer.split("\n");  // Split into separate messages
        buffer = messages.pop(); // Keep unfinished part for next read

        messages.forEach(message => {
            message = message.trim();  // Remove extra spaces

            if (message.length > 0) {
                console.log("📩 Received Full Message from LoRa:", message);
                
                // Send to WebSocket Clients
                wss.clients.forEach(client => {
                    if (client.readyState === WebSocket.OPEN) {
                        client.send(message);
                    }
                });
            }
        });
    }
});

console.log("🚀 WebSocket Server Running on ws://localhost:8080");
