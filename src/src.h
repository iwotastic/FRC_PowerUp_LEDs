#ifndef SRC_H
#define SRC_H

////// COLORS //////

#define red 0x660000
#define white 0x666666
#define blue 0x000066
#define green 0x006600
#define yellow 0x666600

/// PATTERN CONSTANTS ///

#define pBLACK 0
#define pAZE 1
#define pTwoColorScroll 2
#define pThreeColorScroll 3
#define pFourColorScroll 4
#define pTwoColorScrollAlternating 5
#define pThreeColorScrollAlternating 6
#define pFourColorScrollAlternating 7

/////// INCLUDES ///////

#include <Adafruit_DotStar.h>
#include <SPI.h>

//// DOTSTAR CONFIG ////

#define NUMPIXELS 100
#define DATAPIN 35
#define CLOCKPIN 32
Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

// INTERNAL INCLUDES //

#include "Pattern.h"

#endif
