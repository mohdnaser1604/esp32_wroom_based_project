#include <WiFi.h>
#include <ESP32Ping.h>

// Define the static IP address for the main node
IPAddress staticIP(192, 168, 1, 100);  // Main node IP
IPAddress gateway(192, 168, 1, 1);      // Router gateway
IPAddress subnet(255, 255, 255, 0);     // Subnet mask

const char* ssid = "GM";
const char* password = "1922131773";
const IPAddress targetIP(192, 168, 1, 101); // Child node IP

void setup() {
    Serial.begin(115200);
    Serial.println("Node Role: Main Node");

    // Connect to Wi-Fi with static IP configuration
    WiFi.config(staticIP, gateway, subnet);
    WiFi.begin(ssid, password);
    
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected to WiFi. Main Node IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Check Signal Strength (RSSI)
    long rssi = WiFi.RSSI();
    Serial.print("Signal Strength (RSSI): ");
    Serial.print(rssi);
    Serial.println(" dBm");

    // Ping the child node to check connectivity
    Serial.print("Pinging ");
    Serial.print(targetIP);
    Serial.print(" ... ");
    if (Ping.ping(targetIP)) {
        Serial.println("Ping successful");
    } else {
        Serial.println("Ping failed");
    }

    // Wait for a few seconds before the next check
    delay(5000); // Adjust the delay as needed
}
