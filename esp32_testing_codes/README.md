# ESP32 WiFi Mesh Network Project

This project demonstrates a WiFi mesh network using ESP32 WROOM modules. The network consists of a main node and multiple child nodes. The main node manages connectivity and signal strength monitoring, while the child nodes send data and respond to the main node.

## Project Overview

- **Main Node**: 
  - Responsible for managing the WiFi network.
  - Monitors the signal strength (RSSI) of the WiFi connection.
  - Pings external IPs to check connectivity and log results.

- **Child Nodes**:
  - Communicate with the main node.
  - Collect data and send it to the main node for processing.

## Features

- **Signal Strength Monitoring**: The main node reports the RSSI (Received Signal Strength Indicator) to help determine network reliability.
- **Connectivity Checks**: The main node periodically pings a known IP address (like 8.8.8.8) to check Internet connectivity.
- **Flexible Node Structure**: Easily expand the network by adding more child nodes.

## Requirements

- **Hardware**: 
  - ESP32 WROOM modules (one main node, one or more child nodes).
  
- **Software**: 
  - Arduino IDE
  - ESP32 board definitions for Arduino

## Usage

1. **Set up your hardware**: Connect the ESP32 modules according to your network design.
2. **Install necessary libraries**: Ensure you have the `ESP32Ping` library installed in your Arduino IDE.
3. **Upload the code**:
   - Upload the `esp32_mainnode.ino` code to the main node.
   - Upload the child node code (e.g., `esp32_childnode.ino`) to each child node.
4. **Power the nodes**: Connect the ESP32 modules to a power source.
5. **Monitor output**: Use the Serial Monitor in the Arduino IDE to observe the status and connectivity information.

## Author

- mohdnaser(https://github.com/mohdnaser1604)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
