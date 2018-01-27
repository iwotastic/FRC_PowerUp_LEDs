#ifndef PATTERN_H
#define PATTERN_H

#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>

////// COLORS //////

#define cRED     0x660000
#define cGREEN   0x006600
#define cBLUE    0x000066
#define cYELLOW  0x666600
#define cMAGENTA 0x660066
#define cCYAN    0x006666
#define cWHITE   0x666666
#define cOFF     0x000000

// PATTERN CONSTANTS //

#define pBLACK 0
#define pAZE 1
#define pTwoColorScroll 2
#define pThreeColorScroll 3
#define pFourColorScroll 4
#define pTwoColorScrollAlternating 5
#define pThreeColorScrollAlternating 6
#define pFourColorScrollAlternating 7


class Pattern {
  //////////////
  //PROPERTIES//
  //////////////
  private:
    // Properies for ALL functions
    int patternID, start, last;

    Adafruit_DotStar *strip;

    // Basic properties of scrolling functions
    int segmentLength, comeIn;

    // Properties of customizeable color funtions
    uint32_t color1, color2;
  
  public:

    Pattern();

    void Test();
  
    void setStrip(void*);

    ////////////////////
    //PROPERTY SETTERS//
    ////////////////////
  
    //Way to set pattern location
    void setLocation(int, int);
    
    // Function to execute pattern code 
    void setPixels();
  
    //////////////////////
    //PATTERN ID SETTERS//
    //////////////////////
  
    // Function to clear functionallity
    void goBlack();
  
    // Function to display AZE colors
    void aze(int, bool);

    // Functions with customizable color scroling
    void scroll(uint32_t, uint32_t, int, bool);
};

#endif
