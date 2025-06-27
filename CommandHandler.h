#ifndef COMMAND_HANDLER_H
#define COMMAND_HANDLER_H

#include <WiFi.h>
#include <ArduinoHttpClient.h>

class CommandHandler {
private:
  const char* serverAddress;  // Remote server address
  const int serverPort;       // Server port number
  String endpoint;            // API endpoint path

public:
  CommandHandler();                    // Constructor
  void sendAlert(bool smokeDetected);  // Send HTTP alert
  void setEndpoint(String path);       // Set custom endpoint
};

#endif