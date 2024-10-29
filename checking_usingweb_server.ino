#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "GM";       // Replace with your network SSID
const char* password = "1922131773"; // Replace with your network password

WebServer server(80); // Create a web server on port 80

const int ledPin = 2; // Onboard LED pin for ESP32 (usually GPIO 2)

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  
  // Connecting to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  Serial.print(" \ naser please wait while we are connecting ");
  
  // Wait until the connection is established
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); // Print the IP address

  // Define web server routes
  server.on("/", handleRoot);           // Handle root URL
  server.on("/led/on", handleLEDon);   // Handle turning the LED on
  server.on("/led/off", handleLEDoff);  // Handle turning the LED off

  // Start the server
  server.begin();
  Serial.println("HTTP server started");
  Serial.println("welcome naser");
}

void loop() {
  server.handleClient(); // Handle client requests
}

// Function to handle the root URL
void handleRoot() {
  String html = "<h1>ESP32 Web Server nexec team </h1>";
  String htmlRoot = "<h2>welcome Naser</h2>";
  html += "<p><a href=\"/led/on\">Turn LED ON</a></p>";
  html += "<p><a href=\"/led/off\">Turn LED OFF</a></p>";
  server.send(600, "text/html", html); // Send HTML response
}

// Function to turn the LED ON
void handleLEDon() {
  digitalWrite(ledPin, HIGH); // Turn the LED on
  server.send(600, "text/html", "<h1>LED is ON</h1><a href=\"/\">Back</a>"); // Respond with a message
}

// Function to turn the LED OFF
void handleLEDoff() {
  digitalWrite(ledPin, LOW); // Turn the LED off
  server.send(600, "text/html", "<h1>LED is OFF</h1><a href=\"/\">Back</a>"); // Respond with a message
}
