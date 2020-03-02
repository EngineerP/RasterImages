#include "rgba_to_rgb.h"
#include "iostream"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int counter = 0;
  for(std::size_t i = 0; i < rgba.size(); i++){
  	if(i%4 != 3){
		rgb[counter] = rgba[i];
		counter++;
  	}
  }
  ////////////////////////////////////////////////////////////////////////////
}
