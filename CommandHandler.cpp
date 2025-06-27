#include "CommandHandler.h"
#include <Arduino.h>

// Constructor - initialize server configuration
CommandHandler::CommandHandler() 
  : serverAddress("webhook.site"), 
    serverPort(80), 
    endpoint("/ae329387-6637-40d9-9cef-982fa282b1e9") {
}

// Set custom endpoint for HTTP requests
void CommandHandler::setEndpoint(String path) {
  endpoint = path;
  Serial.print("HTTP Endpoint updated to: ");
  Serial.println(endpoint);
}

// Send HTTP POST alert to remote server
void CommandHandler::sendAlert(bool smokeDetected) {
  // Check WiFi connection status
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("ERROR: WiFi not connected. Cannot send alert.");
    return;
  }

  // Create HTTP client
  WiFiClient wifi;
  HttpClient client = HttpClient(wifi, serverAddress, serverPort);

  // Create JSON payload
  String jsonData = "{";
  jsonData += "\"deviceId\":\"SafeHome-SDD-001\",";
  jsonData += "\"timestamp\":";
  jsonData += millis();
  jsonData += ",\"smokeDetected\":";
  jsonData += smokeDetected ? "true" : "false";
  jsonData += ",\"alertLevel\":\"";
  jsonData += smokeDetected ? "CRITICAL" : "NORMAL";
  jsonData += "\",\"location\":\"Home\"}";

  Serial.println("Sending HTTP POST request...");
  Serial.print("Server: ");
  Serial.print(serverAddress);
  Serial.print(":");
  Serial.println(serverPort);
  Serial.print("Endpoint: ");
  Serial.println(endpoint);
  Serial.print("Payload: ");
  Serial.println(jsonData);

  // Send HTTP POST request
  client.beginRequest();
  client.post(endpoint);
  client.sendHeader("Content-Type", "application/json");
  client.sendHeader("Content-Length", jsonData.length());
  client.sendHeader("User-Agent", "SafeHome-ESP32-v1.0");
  client.beginBody();
  client.print(jsonData);
  client.endRequest();

  // Read and display response
  int statusCode = client.responseStatusCode();
  String response = client.responseBody();

  Serial.print("HTTP Response Status: ");
  Serial.println(statusCode);
  Serial.print("Response Body: ");
  Serial.println(response);

  if (statusCode >= 200 && statusCode < 300) {
    Serial.println("✓ Alert sent successfully!");
  } else {
    Serial.print("✗ Failed to send alert. Status: ");
    Serial.println(statusCode);
  }
  Serial.println();
}