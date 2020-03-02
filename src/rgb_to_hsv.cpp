#include "rgb_to_hsv.h"
#include <cmath>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  h = 0;
  s = 0;
  v = 0;
  double red = r/255;
  double green = g/255;
  double blue = b/255;
  v = std::fmax(red,std::fmax(green,blue));
  double minVal = std::fmin(red,std::fmin(green,blue));
  if(v != 0) s = (v - minVal)/v;
  
  if(red != green || red != blue){		
  	if(v == red){
  		h = 60*((green-blue)/(v-minVal));
  	}
  	else if (v == green){
  		h = 60*(2 + ((blue-red)/(v-minVal)));
  	}
  	else if (v == blue){
  		h = 60*(4 + ((red-green)/(v-minVal)));
  	}
  	if(h < 0) h += 360;
  }
  
  
  ////////////////////////////////////////////////////////////////////////////
}
