#include <Arduino.h>
#include <Wire.h>

void setup() {
  // Inicializamos el bus I2C (en ESP32 usa por defecto D21 para SDA y D22 para SCL)
  Wire.begin();
  
  // Inicializamos la comunicación serie a 115200 baudios (como en tu platformio.ini)
  Serial.begin(115200);
  
  // Esperamos un poco a que el monitor serie esté listo
  while (!Serial); 
  Serial.println("\n--- Escáner I2C Iniciado ---");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  Serial.println("Escaneando bus I2C...");

  // Las direcciones I2C van desde 1 hasta 127
  for (address = 1; address < 127; address++) {
    // Inicia la transmisión a la dirección actual
    Wire.beginTransmission(address);
    // Termina la transmisión y guarda el código de retorno
    error = Wire.endTransmission();

    // Si el error es 0, significa que un dispositivo respondió correctamente
    if (error == 0) {
      Serial.print("¡Dispositivo I2C encontrado en la dirección 0x");
      // Formateo para que se vea bonito (ej. 0x03 en vez de 0x3)
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    } 
    // Si el error es 4, hay un problema en esa dirección
    else if (error == 4) {
      Serial.print("Error desconocido en la dirección 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }

  // Resumen del escaneo
  if (nDevices == 0) {
    Serial.println("No se encontraron dispositivos I2C conectados.");
  } else {
    Serial.println("Escaneo finalizado.");
  }

  // Espera 5 segundos antes de volver a escanear
  Serial.println("-----------------------------------\n");
  delay(5000); 
}
