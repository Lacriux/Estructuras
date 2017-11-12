/*En la matriz grid:
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
*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
#include<utility>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

#ifndef CLASESOLID
#define CLASESOLID

class Solid{
  protected:
    vector<vector<int> > grid;
    pair<int,int> direction;
    vector<pair<int,int> > snaku;
    pair<int,int> prize;
    int score;
    bool live;
    Mat img;

  private:
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
      // constructGrid();
      // gridToImage();
      // printImage();

    }

    ~Solid(){
      cout<<"Gracias por Jugar"<<endl;
    }

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

    void gridToImage(void){
      //Mat aux(18, 32, CV_8UC3, Scalar(0,0, 0));
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
      //img = aux;
    }

    void printImage(void){
      resize(img, img, Size(), 25, 25, INTER_NEAREST);
      //namedWindow("Snaku", CV_WINDOW_AUTOSIZE);
      imshow("Snaku", img);
    }

    bool isAlive(void){
      return live;
    }

    void printScore(void){
      cout<<"Score: "<<score<<endl;
    }

    void destroyImage(void){
      destroyWindow("Snaku");
    }
};
#endif
