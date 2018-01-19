#ifndef PATTERN_H
#define PATTERN_H

class Pattern {
  int patternID, start, last, segLength;
  public:
  Pattern();
  void setPixels();
  void change(int, int, int);
  void setSegLength(int);
};

#endif
