/*Proyecto de Estructuras de datos
    Juan Pablo Andrade Gonzalez - B40375
    Prof. Roberto Rodriguez
  Descripcion Breve: Este proyecto consiste en la implementacion de un juego simple de "Snake"

  Se puede encontrar una descripcion mas detallada de algunas funciones en el archivo solid.h

  Este archivo de encarga de crear el juego yb de llamar a las distintas funciones necesarias
  para el funcionamiento de este, asi como crear el "loop" que permite llevar a cabo los movimientos
  del juego.
*/

#include<iostream>
#include<opencv2/opencv.hpp>//Biblioteca para el uso de interfaz gráfica
#include<unistd.h>//Biblioteca para el uso de la funcion usleep, qie se encarga de detener momentaneamente el tiempo de ejecucion
#include"solid.h"

using namespace std;

int main(){
  Solid snake;

  int dir;

  snake.gridToImage();
  snake.printImage();
  bool flag = true;
  /*El siguiente loop se encarga de que el juego continue mientras no se haya
  perdido, de lo contrario solo se mostraria una imagen y no se podria jugar*/
  while(flag){
    dir = waitKey(10); //Se busca si se ha presionado alguna tecla, leida en codigo ASCII

    snake.changeDirection(dir); //Si se ha presionado alguna tecla se envia para evaluar si esta supone un cambio de direccion

    snake.move();//Se mueve la serpiente una casilla en la direccion actual
    snake.gridToImage();//Se crea la imagen corrspondiente a este movimiemto anterior
    snake.printImage();//Se imprime la imagen creada

    //Si la serpiente ya no sigue viva(el jugador perdio), se rompe el ciclo del while
    if(!snake.isAlive()){
      flag = false;
    }
    /*Se espera el tiempo indicado para dar al jugador oportunidad de reaccionar
      este tiempo es medido en microsegundos, el tiempo de espera son 0,3s
    */
    usleep(300000);
  }

  snake.printScore();//Una vez se termina el ciclo, se imprime la puntuacion total de la ronda
  snake.destroyImage();//Se llama al destructor de la imagen
}
