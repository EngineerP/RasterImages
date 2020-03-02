#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  for (int i = 0; i < height; i++) {
  	for (int j = 0; j < width; j++) {
  		int aRed = A[4*(i*width + j)];
  		int aGreen = A[4*(i*width + j) + 1];
  		int aBlue = A[4*(i*width + j) + 2];
  		double aAlpha = (A[4*(i*width + j) + 3])/255.0;
  		
  		int bRed = B[4*(i*width + j)];
  		int bGreen = B[4*(i*width + j) + 1];
  		int bBlue = B[4*(i*width + j) + 2];
  		double bAlpha = (B[4*(i*width + j) + 3])/255.0;
  		
  		int cRed = 255;
  		int cGreen = 255;
  		int cBlue = 255;
  		double cAlpha = 0;
  		if(!(aAlpha == 0 && bAlpha == 0)){
  			cRed = ((aRed*aAlpha) + (bRed*bAlpha)*(1-aAlpha))/(aAlpha + bAlpha*(1-aAlpha));
  			cGreen = ((aGreen*aAlpha) + (bGreen*bAlpha)*(1-aAlpha))/(aAlpha + bAlpha*(1-aAlpha));
  			cBlue = ((aBlue*aAlpha) + (bBlue*bAlpha)*(1-aAlpha))/(aAlpha + bAlpha*(1-aAlpha));
  			cAlpha = (aAlpha + bAlpha*(1-aAlpha))*255.0;
  		}
  		else {
  			cRed = 255;
  			cGreen = 255;
  			cBlue = 255;
  			cAlpha = 0;
		}
  		C[4*(i*width + j)] = (unsigned char)(cRed);
  		C[4*(i*width + j) + 1] = (unsigned char)(cGreen);
  		C[4*(i*width + j) + 2] = (unsigned char)(cBlue);
  		C[4*(i*width + j) + 3] = (unsigned char)(cAlpha);
  	}
  }
  ////////////////////////////////////////////////////////////////////////////
}
