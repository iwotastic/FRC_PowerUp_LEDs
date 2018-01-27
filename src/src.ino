#include "src.h"

Pattern patterns[numarrays];

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

//int scrollIncr = 0;

void setup() {
  strip.begin(); 
  strip.show();

  for (int i = 0; i < 5; i++) {
    patterns[i] = Pattern();
  }
  patterns[0].setStrip(&strip);
  patterns[0].setLocation(0, 30);
  patterns[0].aze(4, true);

  patterns[1].setStrip(&strip);
  patterns[1].setLocation(30, 60);
  patterns[1].scroll(0xff0000, 0x00ff00, 6, false);

  patterns[2].setStrip(&strip);
  patterns[2].setLocation(60, 90);
  patterns[2].scroll(0xffffff, 0x000000, 10, true);
  
  patterns[3].setStrip(&strip);
  patterns[3].setLocation(90, 99);
  patterns[3].flash(0xff0000, 0x000000, 500);
}

void loop() {
  for (int i = 0; i < numarrays; i++) {
    patterns[i].setPixels();
  }
  strip.show();
}

//void aze() {
//  twoColorScroll(blue, yellow, 10, 50, false);
//}
//
//void solid(uint32_t color) {
//  solidAlternate(color, color, 1);
//}
//
//void policeFlash(uint32_t color1, uint32_t color2, int len) {
//  switch ((millis() / 100L) % 6) {
//    case 0:
//    solidAlternate(color1, 0, len);
//    break;
//    case 2:
//    solidAlternate(color1, 0, len);
//    break;
//    case 3:
//    solidAlternate(0, color2, len);
//    break;
//    case 5:
//    solidAlternate(0, color2, len);
//    break;
//    default:
//    solidAlternate(0, 0, 1);
//    break;
//  }
//}
//
//void solidAlternate(uint32_t color1, uint32_t color2, int len) {
//  for (int led = 0; led < NUMPIXELS; led++) {
//    int offsetLED = led % (len * 2);
//    if (offsetLED >= len) {
//      strip.setPixelColor(led, color1);
//    }else{
//      strip.setPixelColor(led, color2);
//    }
//  }
//  strip.show();
//}
//
//void alternateColors(uint32_t stage1Color1, uint32_t stage1Color2, uint32_t stage1Color3, uint32_t stage2Color1, uint32_t stage2Color2, uint32_t stage2Color3, int len, int scrollTime, bool comeIn, unsigned long altInterval) {
//  if ((millis() / altInterval) % 2 == 0) {
//    colorScroll(stage1Color1, stage1Color2, stage1Color3, len, scrollTime, comeIn);
//  }else{
//    colorScroll(stage2Color1, stage2Color2, stage2Color3, len, scrollTime, comeIn);
//  }
//}
//
//void alternate2Colors(uint32_t stage1Color1, uint32_t stage1Color2, uint32_t stage2Color1, uint32_t stage2Color2, int len, int scrollTime, bool comeIn, unsigned long altInterval) {
//  if ((millis() / altInterval) % 2 == 0) {
//    twoColorScroll(stage1Color1, stage1Color2, len, scrollTime, comeIn);
//  }else{
//    twoColorScroll(stage2Color1, stage2Color2, len, scrollTime, comeIn);
//  }
//}
//
//void twoColorScroll(uint32_t firstColor, uint32_t secondColor, int len, int scrollTime, bool comeIn, int startLED, int endLED) {
//  if (scrollIncr >= (len * 2)) {
//    scrollIncr = 0;
//  }
//  if (scrollIncr <= 0) {
//    scrollIncr = (len * 2) - 1;
//  }
//  for (int led = startLED; led < endLED; led++) {
//    int offsetLED = (led + scrollIncr) % (len * 2);
//    if (offsetLED > 0 && offsetLED < (len + 1)) {
//      strip.setPixelColor(led, firstColor);
//    }else{
//      strip.setPixelColor(led, secondColor);
//    }
//  }
//  strip.show();
//  delay(scrollTime);
//  scrollIncr += comeIn ? 1 : -1;
//}
//
//void fourColorScroll(uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, uint32_t fourthColor, int len, int scrollTime, bool comeIn, int startLED, int endLED) {
//  if (scrollIncr >= (len * 4)) {
//    scrollIncr = 0;
//  }
//  if (scrollIncr <= 0) {
//    scrollIncr = (len * 4) - 1;
//  }
//  for (int led = startLED; led < endLED; led++) {
//    int offsetLED = (led + scrollIncr) % (len * 4);
//    if (offsetLED > 0 && offsetLED < (len + 1)) {
//      strip.setPixelColor(led, firstColor);
//    }else if (offsetLED > len && offsetLED < (len * 2 + 1)) {
//      strip.setPixelColor(led, secondColor);
//    }else if (offsetLED > (len * 2) && offsetLED < (len * 3 + 1)) {
//      strip.setPixelColor(led, thirdColor);
//    }else{
//      strip.setPixelColor(led, fourthColor);
//    }
//  }
//  strip.show();
//  delay(scrollTime);
//  scrollIncr += comeIn ? 1 : -1;
//}
//
//void colorScroll(uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, int len, int scrollTime, bool comeIn, int startLED, int endLED) {
//  if (scrollIncr >= (len * 3)) {
//    scrollIncr = 0;
//  }
//  if (scrollIncr <= 0) {
//    scrollIncr = (len * 3) - 1;
//  }
//  for (int led = startLED; led < endLED; led++) {
//    int offsetLED = (led + scrollIncr) % (len * 3);
//    if (offsetLED > 0 && offsetLED < (len + 1)) {
//      strip.setPixelColor(led, firstColor);
//    }else if (offsetLED > len && offsetLED < (len * 2 + 1)) {
//      strip.setPixelColor(led, secondColor);
//    }else{
//      strip.setPixelColor(led, thirdColor);
//    }
//  }
//  strip.show();
//  delay(scrollTime);
//  scrollIncr += comeIn ? 1 : -1;
//}

