#include "Pattern.h"

Pattern::Pattern() {
  patternID = pBlack;
  start = 0;
  last = 0;
  segLength = 4;
}

void Pattern::setPixels() {
  if (patternID != pBlack) {
    for (int led = start; led < last; led++) {
      int offsetLED = led % (segLength * 2);
      
    }
  }
}

void Pattern::change(int newPatternID, int newStart, int newLast) {
  patternID = newPatternID;
  start = newStart;
  last = newLast;
}

void Pattern:setSegLength(int newSegLength) {
  segLength = newSegLength;
}

