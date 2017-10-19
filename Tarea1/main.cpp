#include"image.cpp"
#include"matriz.h"
#include<ImageMagick-6/Magick++/Include.h>
#include <ImageMagick-6/Magick++/Pixels.h>
#include <ImageMagick-6/Magick++/STL.h>
#include<iostream>
#include<string>

using namespace Magick;

int main(){
  InitializeMagick(NULL);
  C_matriz mi_matriz = iluminancia();

  Image mi_imagen("uno.jpg");
  ColorRGB pixelrgb;

  for (int i = 1; i < mi_matriz.getFilas(); i++){
    for(int j = 1; j < mi_matriz.getColumnas();j++){
      pixelrgb = ColorRGB(mi_matriz.get(i,j), mi_matriz.get(i,j), mi_matriz.get(i,j));
      mi_imagen.pixelColor(j,i,pixelrgb);
    }
  }

  mi_imagen.write("tres.jpg");
  return 0;
}
