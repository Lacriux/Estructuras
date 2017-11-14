/*Proyecto de Estructuras de datos
    Juan Pablo Andrade Gonzalez - B40375
    Prof. Roberto Rodriguez
  Descripcion Breve: Este proyecto consiste en la implementacion de un juego simple de "Snake"

  Descripcion detellada de algunos conceptos:
    En la matriz grid:
      Si hay un 0 es una posicion vacía
      Si hay un 1 es parte del cuerpo del Snake
      Si hay un 2 es el punto que hay que recoger
      Si hay un 3 es una pared

    Para controlar la direccion se usa un pair en el que las posiciones son el incremento en la direccion Y,x.
    Estos pueden tomar 3 valores:
      Si el valor es -1 se mueve para arriba o para la izquierda
      Si el valor es 0 no se mueve en ese eje
      Si el valor es 1 se mueve para abajo o la derecha
    Por ejemplo:
      Si la direccion es (-1,0) se esta moviendo hacia arriba
      Si la direccion es (0,1) se esta moviendo hacia la derecha
      Se excluyen los movimientos diagonales (-1,-1),(1,1),(-1,1),(1,-1) y el "no movimiento" (0,0)

    El cuerpo de la serpiente esta construido con un vector de pairs que representan las posiciones de la matriz
    en los que se encuentra la serpiente en ese momento.
    Para moverse la nueva posicion dada por la direccion en la que se esta moviendo es evaluada para conocer si
    es una casilla valida a la que se puede mover, de ser asi esta casilla se agrega al frente del vector y se procede
    a eliminar la ultima posicion del vecto para crear el "movimiemto" de la serpiente. Si la casilla a evaluar
    es la casilla marcada como "punto" entonces no se elimima la ultima entrada del vector para asi hacer crecer la
    serpiente y eumentar la dificultad. Por ultimo si la casilla a evaluar es una pared o es parte del cuerpo de
    la serpiente el juego se da por concluido y se procede a imprimir la puntuacion total obtenida.

    Para el manejo de la interfaz grafica se utiliza OpenCV (https://opencv.org/) debido a que se tiene previo
    conocimento de esta biblioteca y por lo tanto resulta mas facil su uso. Esta biblioteca  se puede descargar
    de https://opencv.org/releases.html.
    Guia para instalacion https://docs.opencv.org/trunk/d7/d9f/tutorial_linux_install.html

    La interfaz grafica consiste en una imagen en la que cada pixel corresponde a una entrada de la matriz grid
    de manera que dependiendo de que haya en cada entrada de la matriz, se asocie un color a este pixel para poder
    mostrar el juego al usuario.
*/

#include<iostream>
#include<vector> //Para el uso de vectores
#include<cstdlib>
#include<time.h>
#include<utility> //Para el uso de Pairs
#include<opencv2/opencv.hpp> //Biblioteca para el uso de interfaz gráfica

using namespace cv;
using namespace std;

#ifndef CLASESOLID
#define CLASESOLID

class Solid{
  protected:
    vector<vector<int> > grid; //Matriz encargada de almacenar toda la informacion del juego
    pair<int,int> direction; //Este par indica la direccion en la que se mueve la serpiente
    vector<pair<int,int> > snaku; //Vector en el que se guardan las casillas que forman parte del cuerpo de la serpiente
    pair<int,int> prize; //Casilla objetivo que tiene que recoger la serpiente
    int score; //Puntuacion
    bool live; //Booleano encargado de decir si la serpiente esta viva (No ha perdido)
    Mat img; //Imagen que se utiliza como interfaz grafica

  private:
    /*Funcion encargada de escoher una nueva casilla para el objetivo.
      Excluye las casillas que sean paredes o parte del cuerpo de la serpiente*/
    void setRandomPoint(void){
      srand(time(NULL));
      pair<int,int> point;
      pair<int,int> aux;
      bool flag = true;
      while(flag){
        flag = false;
        point = make_pair(rand()%8+1,rand()%15+1);
        for(int i = 0; i < snaku.size(); i++){
          aux = snaku[i];
          if(point.first == aux.first && point.second == aux.second){
            flag = true;
          }
        }
      }
      prize = point;
    }

    //Funcion encargada de reconstruir la matriz despues de cada movimiento
    void constructGrid(void){
      if(live){
        for(int i = 1; i < 17; i++){
          for(int j = 1; j < 31; j++){
            grid[i][j] = 0;
          }
        }

        grid[prize.first][prize.second] = 2;

        pair<int,int> aux;
        for(int i = 0; i < snaku.size(); i++){
          aux = snaku[i];
          grid[aux.first][aux.second] = 1;
        }
      }
    }

  public:
    //Constructor de la clase, en este se incializan todas las variablesnecesarias para el funcionamiento del juego
    Solid(void){
      img = Mat(18, 32, CV_8UC3, Scalar(0,0, 0));
      score = 0;
      live = true;
      grid.resize(18);
      for(int i = 0; i < 18; i++){
        grid[i].resize(32,0);
      }
      for(int i = 0; i < 18; i++){
        for(int j = 0; j < 32; j++){
          if(i == 0 || j == 0 || i == 17 || j == 31){
            grid[i][j] = 3;
          }
        }
      }
      pair<int,int> vertebra;
      vertebra = make_pair(1,0);
      for(int i = 1; i < 6; i++){
        vertebra.second = i;
        snaku.insert(snaku.begin(),1, vertebra);
      }
      direction.first = 0;
      direction.second = 1;

      setRandomPoint();

      grid[prize.first][prize.second] = 2;

      pair<int,int> aux;
      for(int i = 0; i < snaku.size(); i++){
        aux = snaku[i];
        grid[aux.first][aux.second] = 1;
      }

    }

    //Destructor: No es necesario debido a que cada elemento usado posee se propio destructor implementado
    ~Solid(){
      cout<<"Gracias por Jugar"<<endl;
    }

    //Funcion encargada de realizar los movimientos constantes de la serpiente
    void move(void){
      pair<int,int> newPosition;
      pair<int,int> aux = snaku.front();
      newPosition = make_pair(aux.first + direction.first, aux.second + direction.second);

      if(grid[newPosition.first][newPosition.second] == 0){
        snaku.insert(snaku.begin(),1,newPosition);
        snaku.pop_back();
      }
      else if(grid[newPosition.first][newPosition.second] == 1){
        live = false;
      }
      else if(grid[newPosition.first][newPosition.second] == 2){
        snaku.insert(snaku.begin(),1, newPosition);
        setRandomPoint();
        score++;
      }
      else if(grid[newPosition.first][newPosition.second] == 3){
        live = false;
      }
      constructGrid();
    }

    //Funcion encargada de modificar la direccion en la que se mueve la serpiente
    void changeDirection(int newDirection){
      if(newDirection == 119){
        direction = make_pair(-1,0);
      }
      else if(newDirection == 115){
        direction = make_pair(1,0);
      }
      else if(newDirection == 97){
        direction = make_pair(0,-1);
      }
      else if(newDirection == 100){
        direction = make_pair(0,1);
      }
    }

    //Funcion encargada de convertir la matriz grid a la imagen que se le va a presentar al usuario
    void gridToImage(void){
      img = Mat(18, 32, CV_8UC3, Scalar(0,0, 0));
      Vec3b white(255,255,255);
      Vec3b blue(255,0,0);

      if(live){
        for(int i = 0; i < grid.size(); i++){
          for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == 1 || grid[i][j] == 2){
              img.at<Vec3b>(Point(j,i)) = white;
            }
            if(grid[i][j] == 3){
              img.at<Vec3b>(Point(j,i)) = blue;
            }
          }
        }
      }
    }

    //Funcion encargada de imprimir la imagen en pantalla
    void printImage(void){
      resize(img, img, Size(), 25, 25, INTER_NEAREST);
      imshow("Snaku", img);
    }

    //Funcion encargada de regresar si todavia no se ha perdido
    bool isAlive(void){
      return live;
    }

    //Funcion encargada de imprimir la puntuacion final del jugador
    void printScore(void){
      cout<<"Score: "<<score<<endl;
    }

    //Destructor de la imagen
    void destroyImage(void){
      destroyWindow("Snaku");
    }
};
#endif
