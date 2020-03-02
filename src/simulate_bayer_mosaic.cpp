#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for(int i = 0; i < height; i++){
	for(int j = 0; j < width; j++){
		if(i%2 == 0){
			if(j%2 == 0)
				bayer[i*width + j] = rgb[(i*width + j)*3 + 1];
			else
				bayer[i*width + j] = rgb[(i*width + j)*3 + 2];
		}
		else{
			if(j%2 == 0)
				bayer[i*width + j] = rgb[(i*width + j)*3];
			else
				bayer[i*width + j] = rgb[(i*width + j)*3 + 1];
		}
	}
  }
  ////////////////////////////////////////////////////////////////////////////
}
