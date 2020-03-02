#include "demosaic.h"

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  int redCount = 0;
  int greenCount = 0;
  int blueCount = 0;
  int red = 0;
  int blue = 0;
  int green = 0;
  for(int i = 0; i < height; i++){
	for(int j = 0; j < width; j++){
		redCount = 0;
		greenCount = 0;
		blueCount = 0;
		red = 0;
		green = 0;
		blue = 0;
		if(i%2 == 0){
			if(j%2 == 0){
				if(i != 0){
					red += bayer[i*width + j - width];
					redCount++;
				}
				if(i != (height - 1)){
					red += bayer[i*width + j + width];
					redCount++;
				}
				if(j != 0){
					blue += bayer[i*width + j - 1];
					blueCount++;
				}
				if(j != (width-1)){
					blue += bayer[i*width + j + 1];
					blueCount++;
				}
				rgb[(i*width + j)*3] = red/redCount;
				rgb[(i*width + j)*3 + 1] = bayer[i*width + j];
				rgb[(i*width + j)*3 + 2] = blue/blueCount;
			}
			else{
				green += bayer[i*width + j - 1];
				greenCount++;
				if(i != 0){
					green += bayer[i*width + j - width];
					greenCount++;
					red += bayer[i*width + j - width - 1];
					redCount++;
					if(j != (width - 1)){
						red += bayer[i*width + j - width + 1];
						redCount++;
					}
				}
				if(i != (height - 1)){
					green += bayer[i*width + j + width];
					greenCount++;
					red += bayer[i*width + j + width - 1];
					redCount++;
					if(j != (width - 1)){
						red += bayer[i*width + j + width + 1];
						redCount++;
					}
				}
				if(j != (width - 1)){
					green += bayer[i*width + j + 1];
					greenCount++;
				}
				rgb[(i*width + j)*3] = red/redCount;
				rgb[(i*width + j)*3 + 1] = green/greenCount;
				rgb[(i*width + j)*3 + 2] = bayer[i*width + j];
			}
		}
		else{
			if(j%2 == 0){
				green += bayer[i*width + j - width];
				greenCount++;				
				if(j != 0){
					green += bayer[i*width + j - 1];
					greenCount++;
					blue += bayer[i*width + j - width - 1];
					blueCount++;
					if(i != height -1){
						blue += bayer[i*width + j + width - 1];
						blueCount++;
					}
				}
				if(j != (width - 1)){
					green += bayer[i*width + j + 1];
					greenCount++;
					blue += bayer[i*width + j + width + 1];
					blueCount++;
					if(i != height - 1){
						blue += bayer[i*width + j + width + 1];
						blueCount++;
					}
				}
				if(i != (height - 1)){
					green += bayer[i*width + j + width];
					greenCount++;
				}
				rgb[(i*width + j)*3] = bayer[i*width + j - width];
				rgb[(i*width + j)*3 + 1] = green/greenCount;
				rgb[(i*width + j)*3 + 2] = blue/blueCount;
			}
			else{
				red += bayer[i*width + j - 1];
				redCount++;
				blue += bayer[i*width + j - width];
				blueCount++;
				if(i != (height - 1)){
					blue += bayer[i*width + j + width];
					blueCount++;
				}
				if(j != (width-1)){
					red += bayer[i*width + j + 1];
					redCount++;
				}
				rgb[(i*width + j)*3] = red/redCount;
				rgb[(i*width + j)*3 + 1] = bayer[i*width + j];
				rgb[(i*width + j)*3 + 2] = blue/blueCount;
			}
		}
	}
  }
  ////////////////////////////////////////////////////////////////////////////
}
