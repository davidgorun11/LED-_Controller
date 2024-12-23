#include "wifi_manager.h"
#include "leds.h"
#include "display.h"
#include "controls.h"
#include "homekit.h"

#define RESET_BUTTON_PIN 13

void setup() {
  Serial.begin(115200);

  // Инициализация кнопки сброса
  pinMode(RESET_BUTTON_PIN, INPUT_PULLUP);

  // Настройка Wi-Fi
  setupWiFi();

  // Инициализация остальных компонентов
  initLEDs();
  initDisplay();
  initControls();
  initHomeKit();
}

void loop() {
  // Обработка удержания кнопки для сброса настроек Wi-Fi
  static unsigned long pressStart = 0;
  if (digitalRead(RESET_BUTTON_PIN) == LOW) {
    if (pressStart == 0) {
      pressStart = millis();
    }
    if (millis() - pressStart > 5000) { // Удержание 5 секунд
      resetWiFi();
    }
  } else {
    pressStart = 0; // Кнопка отпущена
  }

  // Основной код устройства
