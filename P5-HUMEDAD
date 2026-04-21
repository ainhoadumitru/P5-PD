#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(115200);
  Serial.println("Iniciando prueba AHT10/AHT20...");

  // Inicializa el sensor en el bus I2C (usa D21 y D22 por defecto en ESP32)
  if (!aht.begin()) {
    Serial.println("¡No se pudo encontrar el sensor AHT! Revisa las conexiones.");
    while (1) delay(10);
  }
  Serial.println("Sensor AHT encontrado y listo.");
}

void loop() {
  sensors_event_t humidity, temp;
  
  // Obtenemos los eventos de temperatura y humedad
  aht.getEvent(&humidity, &temp); 

  // Imprimimos los resultados en el Monitor Serie
  Serial.print("Temperatura: ");
  Serial.print(temp.temperature);
  Serial.println(" +-C");

  Serial.print("Humedad: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" % rH");

  Serial.println("---------------------------");
  delay(2000); // Espera 2 segundos para la siguiente lectura
}
