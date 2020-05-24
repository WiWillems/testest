#ifndef ROOMBASENSEHAT_H
#define ROOMBASENSEHAT_H

#include <cstdint>
#include "LedMatrix.h"

class Pixel;

class RoombaSenseHAT: public LedMatrix
{
public:
   static const int MAX_X;
   static const int MAX_Y;
   static const int MIN_X;
   static const int MIN_Y;
   int clean;
   int spot;
   int dock;

   RoombaSenseHAT();
   ~RoombaSenseHAT();

   void clear();
   void clear(const Pixel &pixel);
   void invert();
   void cleaning();
   void spotting();
   void docking();
   int setPixel(uint8_t x, uint8_t y, const Pixel &pixel);
   Pixel getPixel(uint8_t x, uint8_t y) const;

private:
};

#endif
