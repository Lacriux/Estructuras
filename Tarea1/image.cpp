#include<iostream>
#include<string>
#include<ImageMagick-6/Magick++/Include.h>
#include <ImageMagick-6/Magick++/Pixels.h>
#include <ImageMagick-6/Magick++/STL.h>
#include"matriz.h"

using namespace Magick;

C_matriz iluminancia(){
    Image mi_imagen("uno.jpg");
    C_matriz mi_matriz(mi_imagen.rows(), mi_imagen.columns());
    ColorRGB pixelrgb;
    for (int i = 1; i < mi_matriz.getFilas(); i++){
      for(int j = 1; j < mi_matriz.getColumnas();j++){
        pixelrgb = mi_imagen.pixelColor(j,i);
        float inf = pixelrgb.red()*0.299 + pixelrgb.green()*0.587 + pixelrgb.blue()*0.114;
        if(inf < 0.4){
          inf = 1;
        }else{
          inf = 0;
        }
        mi_matriz.set(i,j, inf);
      }
    }
    return mi_matriz;
}
