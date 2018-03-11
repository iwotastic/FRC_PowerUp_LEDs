#include "src.h"

//#define TEST_MODE_ENABLED

#ifdef TEST_MODE_ENABLED

#define COM Serial
#define SETUP begin(9600)
#define COM_READ COM.parseInt()

#else

#include <Wire.h>
#define COM Wire
#define SETUP begin(5)
#define COM_READ int(uint8_t(COM.read()))

#endif

/*
 * 44 - Length of bumper lights
 * 77 - Length of top light
 * 38 - Top split point
 */

Pattern patterns[numarrays];

Adafruit_DotStar strip1 = Adafruit_DotStar(NUMPIXELS1, DATAPIN1, CLOCKPIN1, DOTSTAR_BGR);
Adafruit_DotStar strip2 = Adafruit_DotStar(NUMPIXELS2, DATAPIN2, CLOCKPIN2, DOTSTAR_BGR);

void setup() {
  strip1.begin(); 
  strip1.show();
  strip2.begin(); 
  strip2.show();

  COM.SETUP;

  patterns[0].setStrip(&strip1);
  patterns[1].setStrip(&strip1);
  patterns[2].setStrip(&strip1);
  patterns[3].setStrip(&strip2);
}

void loop() {
  for (int i = 0; i < numarrays; i++) {
    patterns[i].setPixels();
    
  }
  strip1.show();
  strip2.show();
  if (COM.available() > 0) {
    int code = COM_READ;
    switch (code) {
      case 8:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xff0000, 0x000000, 44, false);
      patterns[1].setLocation(44, 82);
      patterns[1].scroll(0xff0000, 0x000000, 4, false);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].scroll(0xff0000, 0x000000, 4, true);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xff0000, 0x000000, 44, false);
      break;
      case 7:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xff00ff, 0xff7f00, 4, true);
      patterns[1].setLocation(44, 82);
      patterns[1].flash(0xff00ff, 0xff7f00, 100);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].flash(0xff00ff, 0xff7f00, 100);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xff00ff, 0xff7f00, 4, true);
      break;
      case 6:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xffff00, 0xff0000, 4, false);
      patterns[1].setLocation(44, 82);
      patterns[1].flash(0xffff00, 0xff0000, 100);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].flash(0xffff00, 0xff0000, 100);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xffff00, 0xff0000, 4, false);
      break;
      case 5:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xffff00, 0xff7f00, 4, false);
      patterns[1].setLocation(44, 82);
      patterns[1].flash(0xffff00, 0xff7f00, 100);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].flash(0xffff00, 0xff7f00, 100);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xffff00, 0xff7f00, 4, false);
      break;
      case 4:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xffff00, 0x00ff00, 4, false);
      patterns[1].setLocation(44, 82);
      patterns[1].flash(0xffff00, 0x00ff00, 100);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].flash(0xffff00, 0x00ff00, 100);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xffff00, 0x00ff00, 4, false);
      break;
      case 3:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0xffff00, 0x000000, 4, false);
      patterns[1].setLocation(44, 82);
      patterns[1].flash(0xffff00, 0x000000, 100);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].flash(0xffff00, 0x000000, 100);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0xffff00, 0x000000, 4, false);
      break;
      case 2:
      patterns[0].setLocation(0, 44);
      patterns[0].scroll(0x0000ff, 0x000000, 44, false);
      patterns[1].setLocation(44, 82);
      patterns[1].scroll(0x0000ff, 0x000000, 4, false);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].scroll(0x0000ff, 0x000000, 4, true);
      patterns[3].setLocation(0, 44);
      patterns[3].scroll(0x0000ff, 0x000000, 44, false);
      break;
      case 1:
      patterns[0].setLocation(0, 44);
      patterns[0].aze(6, false);
      patterns[1].setLocation(44, 82);
      patterns[1].aze(2, true);
      patterns[2].setLocation(82, NUMPIXELS1);
      patterns[2].aze(2, false);
      patterns[3].setLocation(0, 44);
      patterns[3].aze(6, false);
      break;
      default:
      patterns[0].setLocation(0, NUMPIXELS1);
      patterns[0].goBlack();
      patterns[1].setLocation(0, 0);
      patterns[1].goBlack();
      patterns[2].setLocation(0, 0);
      patterns[2].goBlack();
      patterns[3].setLocation(0, NUMPIXELS2);
      patterns[3].goBlack();
      break;
    }
  }
}
