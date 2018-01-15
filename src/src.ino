#include <Adafruit_DotStar.h>
#include <SPI.h>

#define NUMPIXELS 100

#define DATAPIN 35
#define CLOCKPIN 32

#define red 0x660000
#define white 0x666666
#define blue 0x000066
#define green 0x006600
#define yellow 0x666600

Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DATAPIN, CLOCKPIN, DOTSTAR_BGR);

int scrollIncr = 0;

void setup() {
  strip.begin(); 
  strip.show();
}

void loop() {
  //alternateColors(red, white, blue, red, white, yellow, 8, 25, false, 500);
  //policeFlash(red, blue, 10);
  //solid(green);
  //aze();
}

void aze() {
  policeFlash(blue, yellow, 15);
}

void solid(uint32_t color) {
  solidAlternate(color, color, 1);
}

void policeFlash(uint32_t color1, uint32_t color2, int len) {
  switch ((millis() / 100L) % 6) {
    case 0:
    solidAlternate(color1, 0, len);
    break;
    case 2:
    solidAlternate(color1, 0, len);
    break;
    case 3:
    solidAlternate(0, color2, len);
    break;
    case 5:
    solidAlternate(0, color2, len);
    break;
    default:
    solidAlternate(0, 0, 1);
    break;
  }
}

void solidAlternate(uint32_t color1, uint32_t color2, int len) {
  for (int led = 0; led < NUMPIXELS; led++) {
    int offsetLED = led % (len * 2);
    if (offsetLED >= len) {
      strip.setPixelColor(led, color1);
    }else{
      strip.setPixelColor(led, color2);
    }
  }
  strip.show();
}

void alternateColors(uint32_t stage1Color1, uint32_t stage1Color2, uint32_t stage1Color3, uint32_t stage2Color1, uint32_t stage2Color2, uint32_t stage2Color3, int len, int scrollTime, bool comeIn, unsigned long altInterval) {
  if ((millis() / altInterval) % 2 == 0) {
    colorScroll(stage1Color1, stage1Color2, stage1Color3, len, scrollTime, comeIn);
  }else{
    colorScroll(stage2Color1, stage2Color2, stage2Color3, len, scrollTime, comeIn);
  }
}

void alternate2Colors(uint32_t stage1Color1, uint32_t stage1Color2, uint32_t stage2Color1, uint32_t stage2Color2, int len, int scrollTime, bool comeIn, unsigned long altInterval) {
  if ((millis() / altInterval) % 2 == 0) {
    twoColorScroll(stage1Color1, stage1Color2, len, scrollTime, comeIn);
  }else{
    twoColorScroll(stage2Color1, stage2Color2, len, scrollTime, comeIn);
  }
}

void twoColorScroll(uint32_t firstColor, uint32_t secondColor, int len, int scrollTime, bool comeIn) {
  if (scrollIncr >= (len * 2)) {
    scrollIncr = 0;
  }
  if (scrollIncr <= 0) {
    scrollIncr = (len * 2) - 1;
  }
  for (int led = 0; led < NUMPIXELS; led++) {
    int offsetLED = (led + scrollIncr) % (len * 2);
    if (offsetLED > 0 && offsetLED < (len + 1)) {
      strip.setPixelColor(led, firstColor);
    }else{
      strip.setPixelColor(led, secondColor);
    }
  }
  strip.show();
  delay(scrollTime);
  scrollIncr += comeIn ? 1 : -1;
}

void fourColorScroll(uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, uint32_t fourthColor, int len, int scrollTime, bool comeIn) {
  if (scrollIncr >= (len * 4)) {
    scrollIncr = 0;
  }
  if (scrollIncr <= 0) {
    scrollIncr = (len * 4) - 1;
  }
  for (int led = 0; led < NUMPIXELS; led++) {
    int offsetLED = (led + scrollIncr) % (len * 4);
    if (offsetLED > 0 && offsetLED < (len + 1)) {
      strip.setPixelColor(led, firstColor);
    }else if (offsetLED > len && offsetLED < (len * 2 + 1)) {
      strip.setPixelColor(led, secondColor);
    }else if (offsetLED > (len * 2) && offsetLED < (len * 3 + 1)) {
      strip.setPixelColor(led, thirdColor);
    }else{
      strip.setPixelColor(led, fourthColor);
    }
  }
  strip.show();
  delay(scrollTime);
  scrollIncr += comeIn ? 1 : -1;
}

void colorScroll(uint32_t firstColor, uint32_t secondColor, uint32_t thirdColor, int len, int scrollTime, bool comeIn) {
  if (scrollIncr >= (len * 3)) {
    scrollIncr = 0;
  }
  if (scrollIncr <= 0) {
    scrollIncr = (len * 3) - 1;
  }
  for (int led = 0; led < NUMPIXELS; led++) {
    int offsetLED = (led + scrollIncr) % (len * 3);
    if (offsetLED > 0 && offsetLED < (len + 1)) {
      strip.setPixelColor(led, firstColor);
    }else if (offsetLED > len && offsetLED < (len * 2 + 1)) {
      strip.setPixelColor(led, secondColor);
    }else{
      strip.setPixelColor(led, thirdColor);
    }
  }
  strip.show();
  delay(scrollTime);
  scrollIncr += comeIn ? 1 : -1;
}

