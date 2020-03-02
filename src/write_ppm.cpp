#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  std::ofstream ppmFile;
  ppmFile.open(filename, std::ios::out | std::ios::binary);
  if(num_channels == 3)
  	ppmFile << "P3" << "\n";
  else
  	ppmFile << "P2" << '\n';
  ppmFile << width << "\n";
  ppmFile << height << "\n";
  ppmFile << 255 << "\n";
  for(int i = 0; i < data.size(); i++){
  	ppmFile << (int)data[i] << " ";
	if((i + 1)%(width*num_channels) == 0){
		ppmFile << '\n';
	}
	else{
		ppmFile << " ";
	}
  }
  ppmFile.close();
  return false;
  ////////////////////////////////////////////////////////////////////////////
}
