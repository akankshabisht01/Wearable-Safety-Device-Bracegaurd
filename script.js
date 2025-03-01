var map = L.map('map').setView([28.7041, 77.1025], 13); // Default coordinates

L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: '&copy; OpenStreetMap contributors'
}).addTo(map);

var marker = L.marker([28.7041, 77.1025]).addTo(map);

const ws = new WebSocket('ws://localhost:8080');

ws.onopen = () => console.log("✅ Connected to WebSocket Server");

ws.onmessage = (event) => {
    let data = event.data.trim();
    console.log("📡 Received:", data);

    let coords = data.split(",");
    if (coords.length === 2) {
        let lat = parseFloat(coords[0]);
        let lng = parseFloat(coords[1]);

        document.getElementById("coords").innerText = lat + ", " + lng;
        map.setView([lat, lng], 13);
        marker.setLatLng([lat, lng]);
    }
};

ws.onclose = () => console.log("❌ Disconnected from WebSocket Server");
