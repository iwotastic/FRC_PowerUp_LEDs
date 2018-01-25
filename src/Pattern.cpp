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
      strip->setPixelColor(led, ((millis() / (10L * segmentLength * 2)) % (segmentLength * 2) >= segmentLength) ? 0x0000ff : 0xffff00);
    }
    break;
    
    default:
    for (int led = start; led < last; led++) {
      strip->setPixelColor(led, 0);
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

