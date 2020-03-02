#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
    double h;
  double s;
  double v;
  double r;
  double g;
  double b;
  for(int i = 0; i < height; i++){
  	for(int j = 0; j < width; j++){
  		int pixelIndex = (i*width + j)*3;
  		r = (double)rgb[pixelIndex];
  		g = (double)rgb[pixelIndex + 1];
  		b = (double)rgb[pixelIndex + 2];
  		rgb_to_hsv(r, g, b, h, s, v);
  		s *= (1-factor);
  		hsv_to_rgb(h, s, v, r, g, b);
  		desaturated[pixelIndex] = (unsigned char)r;
  		desaturated[pixelIndex + 1] = (unsigned char)g;
  		desaturated[pixelIndex + 2] = (unsigned char)b;
  	}
  }
  ////////////////////////////////////////////////////////////////////////////
}
