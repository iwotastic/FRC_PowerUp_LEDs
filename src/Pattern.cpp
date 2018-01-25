#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>
#include "Pattern.h"

Pattern::Pattern() {
  patternID = pBLACK;
  start = 0;
  last = 0;
  strip = NULL;
}

void Pattern::Test(){
  while(1);
}

void Pattern::setStrip(void* newstrip){
  strip = (Adafruit_DotStar*)newstrip;
}

void Pattern::setPixels() {
  switch (patternID) {
    case pAZE:
    for (int led = start; led < last; led++) {
      int offsetLED = led - (millis() % 100L) / ((100.0 / segmentLength) * 2.0);
//      strip.setPixelColor(led, off);
    }
    break;
    
    default:
    for (int led = start; led < last; led++) {
//      strip.setPixelColor(led, off);
    }
    break;
  }
}

void Pattern::setLocation(int newStart, int newLast) {
  start = newStart;
  last = newLast;
}

void Pattern::goBlack() {
  patternID = pBLACK;
}

void Pattern::aze(int newSegmentLength, bool comeIn) {
  patternID = pAZE;
}

