#include "wifi_manager.h"
#include <WiFi.h>
#include <WiFiManager.h>

// Инициализация WiFiManager
WiFiManager wm;

// Настройка Wi-Fi
void setupWiFi() {
  Serial.println("Setting up Wi-Fi...");

  // Автоматическое подключение или запуск точки доступа
  if (!wm.autoConnect("LED_Controller_AP")) {
    Serial.println("Failed to connect to Wi-Fi. Restarting...");
    ESP.restart();
  }

  Serial.println("Connected to Wi-Fi!");
  Serial.println(WiFi.localIP());
}

// Сброс настроек Wi-Fi
void resetWiFi() {
  Serial.println("Resetting Wi-Fi settings...");
  wm.resetSettings();
  ESP.restart();
}
