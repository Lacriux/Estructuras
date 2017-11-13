#include<iostream>
#include<opencv2/opencv.hpp>
#include<unistd.h>
#include"solid.h"

using namespace std;

int main(){
  Solid snake;

  int dir;

  snake.gridToImage();
  snake.printImage();
  bool flag = true;
  while(flag){
    dir = waitKey(10);

    snake.changeDirection(dir);

    snake.move();
    snake.gridToImage();
    snake.printImage();

    if(!snake.isAlive()){
      flag = false;
    }

    usleep(500000);
  }

  snake.printScore();
  snake.destroyImage();

  //Convertir a imagen
  //imprimir imagen
  //preguntar por cambio de direccion
  //esperar medio segundo
}
