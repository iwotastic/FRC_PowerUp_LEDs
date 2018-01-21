#ifndef PATTERN_H
#define PATTERN_H

#include <Arduino.h>
#include <Adafruit_DotStar.h>
#include <SPI.h>

class Pattern {
  //////////////
  //PROPERTIES//
  //////////////
  
  // Properies for ALL functions
  int patternID, start, last;

  Adafruit_DotStar *strip;

  // Basic properties of scrolling functions
  int segmentLength, comeIn;
  
  public:

  Pattern();

  void setStrip(Adafruit_DotStar*);

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
};

#endif
