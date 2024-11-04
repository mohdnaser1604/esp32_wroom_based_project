#include <WiFi.h>
#include <ESP32Ping.h>

// Define the static IP address for the child node
IPAddress staticIP(192, 168, 1, 101);  // Child node IP
IPAddress gateway(192, 168, 1, 1);      // Router gateway
IPAddress subnet(255, 255, 255, 0);     // Subnet mask

const char* ssid = "GM";
const char* password = "1922131773";
const char* nodeName = "Child Node"; // Define the name of this node

void setup() {
    Serial.begin(115200);
    Serial.print("Node Role: ");
    Serial.println(nodeName); // Display the name of the node

    // Connect to Wi-Fi with static IP configuration
    WiFi.config(staticIP, gateway, subnet);
    WiFi.begin(ssid, password);
    
    Serial.print("Connecting to WiFi");
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }
    Serial.println();
    Serial.print("Connected to WiFi. ");
    Serial.print(nodeName);
    Serial.print(" IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Check Signal Strength (RSSI)
    long rssi = WiFi.RSSI();
    Serial.print("Signal Strength (RSSI) at ");
    Serial.print(nodeName);
    Serial.print(": ");
    Serial.print(rssi);
    Serial.println(" dBm");

    // Wait for a few seconds before the next check
    delay(5000); // Adjust the delay as needed
}
