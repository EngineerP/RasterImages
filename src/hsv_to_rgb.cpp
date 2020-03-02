#include "hsv_to_rgb.h"
#include <cmath>

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  r = 0;
  g = 0;
  b = 0;
  
  double c = v*s;
  if(!std::isnan(h))
  {
  	double hPrime;
  	double temp = h;
  	while (temp < 0) { temp += 360; }
  	if (h > 360) hPrime = (std::fmod(temp,360))/60;
  	else hPrime = temp/60;
  	double x = c*(1-std::fabs(std::fmod(hPrime,2)-1));
  	if(hPrime >= 0 && hPrime <= 1){
  		r = c;
  		g = x;
  		b = 0;
  	}
  	else if(hPrime > 1 && hPrime <= 2){
  		r = x;
  		g = c;
  		b = 0;
	}
  	else if(hPrime > 2 && hPrime <= 3){
  		r = 0;
  		g = c;
  		b = x;
	}
  	else if(hPrime > 3 && hPrime <= 4){
  		r = 0;
  		g = x;
  		b = c;
	}
  	else if(hPrime > 4 && hPrime <= 5){
  		r = x;
  		g = 0;
  		b = c;
	}
	else if (hPrime > 5 && hPrime <= 6){
		r = c;
		g = 0;
		b = x;
	}
	double m = v - c;
	r += m;
	g += m;
	b += m;
	r *= 255;
	g *= 255;
	b *= 255;
  }
  ////////////////////////////////////////////////////////////////////////////
}
