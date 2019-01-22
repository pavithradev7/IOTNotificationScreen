/*
 * Project FinalProjectPrototype
 * Description:
 * Author:
 * Date:
 */

#if defined(PARTICLE)
  #include <Adafruit_mfGFX.h>
  #include "Adafruit_ILI9341.h"

  // For the Adafruit shield, these are the default.
  #define TFT_DC D5
  #define TFT_CS D4

#else
  #include "SPI.h"
  #include <Adafruit_mfGFX.h>
  #include "Adafruit_ILI9341.h"

  // For the Adafruit shield, these are the default.
  #define TFT_DC 9
  #define TFT_CS 10
#endif

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, 0);

int button = D1;

// setup() runs once, when the device is first turned on.
void setup() {
  Particle.function("writeMessage", writeMessage);

  tft.begin();
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0,0);
  tft.setRotation(1);
  tft.setTextSize(4);
  tft.println("Screensaver");

  pinMode(button, INPUT_PULLUP);
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  if(digitalRead(button) == LOW){
    tft.fillScreen(ILI9341_BLACK);
    tft.setCursor(0,0);
    tft.setRotation(1);
    tft.setTextSize(4);
    tft.println("Screensaver");
  }
}

int writeMessage(String message){
  tft.fillScreen(ILI9341_BLACK);
  tft.setCursor(0,0);
  tft.setRotation(1);
  tft.setTextSize(4);
  tft.println(message);
  return 0;
}
