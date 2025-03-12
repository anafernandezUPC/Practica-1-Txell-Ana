
//3. Modificar el programa perquè actuï directament sobre els registres dels ports d'entrada i sortida
#include <Arduino.h>
#define LED_PIN 2 // Definim el pin del LED
#define DELAY 1000 // Definim un temps d'espera de 1000 ms

void setup() {
  // Establim el pin com a sortida directament a través dels registres
  pinMode(LED_PIN, OUTPUT); // Això segueix sent necessari
  Serial.begin(115200);     // Inicialitzem la comunicació sèrie
}

void loop() {
  // Engegar el LED utilitzant el registre GPIO
  uint32_t *gpio_out = (uint32_t *)GPIO_OUT_REG;
  *gpio_out |= (1 << LED_PIN);  // Activem el bit corresponent al pin 2
  Serial.println("ON");         // Enviem "ON" pel port sèrie
  delay(DELAY);                 // Esperem 1000 ms
  
  // Apagar el LED utilitzant el registre GPIO
  *gpio_out &= ~(1 << LED_PIN); // Desactivem el bit corresponent al pin 2
  Serial.println("OFF");        // Enviem "OFF" pel port sèrie
  delay(DELAY);                 // Esperem 1000 ms
}
