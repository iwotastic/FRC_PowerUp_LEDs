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
    case pTwoColorFlash:
    for (int led = start; led < last; led++) {
      strip->setPixelColor(led, (millis() % (patternSpeed * 2)) > patternSpeed ? color1 : color2);
    }
    break;
    
    case pTwoColorScroll:
    for (int led = start; led < last; led++) {
      long tempDividend = long((led + long(millis() / 100) * (comeIn ? 1 : -1)) / segmentLength);
      strip->setPixelColor(led, (tempDividend * (tempDividend < 0 ? -1 : 1)) % 2 == 1 ? color1 : color2);
    }
    break;
    
    case pAZE:
    for (int led = start; led < last; led++) {
      long tempDividend = long((led + long(millis() / 100) * (comeIn ? 1 : -1)) / segmentLength);
      strip->setPixelColor(led, (tempDividend * (tempDividend < 0 ? -1 : 1)) % 2 == 1 ? 0x0000ff : 0xffff00);
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

void Pattern::aze(int newSegmentLength, bool newComeIn) {
  segmentLength = newSegmentLength;
  comeIn = newComeIn;
  patternID = pAZE;
}

void Pattern::scroll(uint32_t newColor1, uint32_t newColor2, int newSegmentLength, bool newComeIn) {
  color1 = newColor1;
  color2 = newColor2;
  segmentLength = newSegmentLength;
  comeIn = newComeIn;
  patternID = pTwoColorScroll;
}

void Pattern::flash(uint32_t newColor1, uint32_t newColor2, int newPatternSpeed) {
  color1 = newColor1;
  color2 = newColor2;
  patternSpeed = newPatternSpeed;
  patternID = pTwoColorFlash;
}

