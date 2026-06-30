#include <Arduino.h>
// #define R1_PIN_DEFAULT  25
// #define G1_PIN_DEFAULT  26
// #define B1_PIN_DEFAULT  27
// #define R2_PIN_DEFAULT  14
// #define G2_PIN_DEFAULT  12
// #define B2_PIN_DEFAULT  13

// #define A_PIN_DEFAULT   23
// #define B_PIN_DEFAULT   19
// #define C_PIN_DEFAULT   5
// #define D_PIN_DEFAULT   17
// #define E_PIN_DEFAULT   -1 // IMPORTANT: Change to a valid pin if using a 64x64px panel.
            
// #define LAT_PIN_DEFAULT 4
// #define OE_PIN_DEFAULT  15
// #define CLK_PIN_DEFAULT 16


#include <Adafruit_Protomatter.h>

// RGB pins
uint8_t rgbPins[] = {
  25, // R1
  26, // G1
  27, // B1
  14, // R2
  12, // G2
  13  // B2
};

// Address pins (A-D for 64x32)
uint8_t addrPins[] = {
  23, // A
  19, // B
  5,  // C
  17  // D
};


#define latchPin 4
#define oePin  15
#define clockPin 16
// Create matrix object
Adafruit_Protomatter matrix(
  32, 4, 1, rgbPins, 4, addrPins, clockPin, latchPin, oePin, false);

void setup() {
  Serial.begin(9600);

  ProtomatterStatus status = matrix.begin();

  if (status != PROTOMATTER_OK) {
    Serial.print("Protomatter failed: ");
    Serial.println((int)status);
    while (1);
  }

  Serial.println("Display initialized!");
}

void loop() {

  matrix.fillScreen(matrix.color565(255, 0, 0));
  matrix.show();
  delay(1000);

  matrix.fillScreen(matrix.color565(0, 255, 0));
  matrix.show();
  delay(1000);

  matrix.fillScreen(matrix.color565(0, 0, 255));
  matrix.show();
  delay(1000);

  matrix.fillScreen(matrix.color565(255, 255, 255));
  matrix.show();
  delay(1000);

  matrix.fillScreen(0);
  matrix.show();
  delay(1000);
}