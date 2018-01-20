#include "Pattern.h"

#include "Arduino.h"
#include <Adafruit_DotStar.h>
#include <SPI.h>

////// COLORS //////

#define red 0x660000
#define white 0x666666
#define blue 0x000066
#define green 0x006600
#define yellow 0x666600
#define off 0

// PATTERN CONSTANTS //

#define pBLACK 0
#define pAZE 1
#define pTwoColorScroll 2
#define pThreeColorScroll 3
#define pFourColorScroll 4
#define pTwoColorScrollAlternating 5
#define pThreeColorScrollAlternating 6
#define pFourColorScrollAlternating 7

Pattern::Pattern() {
  patternID = pBLACK;
  start = 0;
  last = 0;
  strip = NULL;
}
////
//Pattern::Pattern() {
//  patternID = pBLACK;
//  start = 0;
//  last = 0;
////  strip = &theStrip;
//}

void Pattern::setStrip(Adafruit_Dotstar* newstrip){

  strip = newstrip;
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

