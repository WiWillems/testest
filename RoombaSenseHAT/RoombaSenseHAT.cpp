#include "RoombaSenseHAT.h"
#include "Pixel.h"
#include "LedMatrix.h" 

#include "LedMatrixDevice.h"

const int RoombaSenseHAT::MAX_X{7};
const int RoombaSenseHAT::MAX_Y{7};
const int RoombaSenseHAT::MIN_X{0};
const int RoombaSenseHAT::MIN_Y{0};

RoombaSenseHAT::RoombaSenseHAT()
{
   ::init_fb();
}

RoombaSenseHAT::~RoombaSenseHAT()
{
   ::blank();
}

void RoombaSenseHAT::clear()
{
   ::blank();
}

void RoombaSenseHAT::clear(const Pixel &pixel)
{
   ::clear(pixel[Pixel::RGB::R], pixel[Pixel::RGB::G],
           pixel[Pixel::RGB::B]);
}

void RoombaSenseHAT::invert()
{
   ::invert();
}

int RoombaSenseHAT::setPixel(uint8_t x, uint8_t y, const Pixel &pixel)
{
   return set_pixel(x, y, pixel[Pixel::RGB::R], pixel[Pixel::RGB::G],
                    pixel[Pixel::RGB::B]);
}

Pixel RoombaSenseHAT::getPixel(uint8_t x, uint8_t y) const
{
   uint8_t r;
   uint8_t g;
   uint8_t b;
   get_pixel(x, y, &r, &g, &b);

   return Pixel{r, g, b};
}

void RoombaSenseHAT::cleaning();
{
  
  RoombaSenseHAT::clean = 1;

  setPixel(0, 0, Pixel(40, 80, 100));

  std::cout<<"clean is on";
  
  RoombaSenseHAT::clean = 0;

}

void RoombaSenseHAT::spotting();
{
  
  spot = 1;

  ::setPixel(1, 0, Pixel(40, 80, 100));

  std::cout<<"spot is on";
  
  spot = 0;

}

void RoombaSenseHAT::docking();
{
  
  dock = 1;

  ::setPixel(2, 0, Pixel(40, 80, 100));

  std::cout<<"dock is on";
  
  clean = 0;

}
