#include <WiFi.h>

const char* ssid = "GM";       // Replace with your network SSID
const char* password = "1922131773"; // Replace with your network password

void setup() {
  Serial.begin(115200);
  
  // Connecting to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  Serial.print("\h hello naser please wait while we are connecting to wifi");
  
  // Wait until the connection is established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); // Print the IP address
}

void loop() {
  // Add any other code here if needed
}
