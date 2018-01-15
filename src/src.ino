#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 30

#define DATAPIN 4
#define CLOCKPIN 5

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BRG);

void setup() {
  strip.begin(); 
  strip.show();
}

void loop() {
  strip.setPixelColor(0, 0xFF0000); // 'On' pixel at head
  strip.show();                     // Refresh strip
  delay(1000); 
  strip.setPixelColor(0, 0); // 'On' pixel at head
  strip.show();                     // Refresh strip
  delay(1000);
}

