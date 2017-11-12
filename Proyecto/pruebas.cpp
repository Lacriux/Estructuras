#include<iostream>
#include<vector>
#include<utility>
#include<opencv2/opencv.hpp>
#include"solid.h"

using namespace cv;
using namespace std;

int main(){
  Mat img(18, 32, CV_8UC3, Scalar(0,0, 0));
  if (img.empty()){
    cout << "\n Image not created. You" << " have done something wrong. \n";
    return -1;	// Unsuccessful.
  }
  Vec3b blue(255,0,0);
  Vec3b white(255,255,255);


  vector<vector<int> > grid;
  grid.resize(18);
  for(int i = 0; i < 18; i++){
    grid[i].resize(32,0);
  }
  for(int i = 0; i < 18; i++){
    for(int j = 0; j < 32; j++){
      if(i == 0 || j == 0 || i == 16 || j == 30){
        grid[i][j] = 3;
      }
    }
  }

  vector<pair<int,int> > snaku;
  pair<int,int> vertebra;
  vertebra = make_pair(1,0);
  for(int i = 1; i < 6; i++){
    vertebra.second = i;
    snaku.insert(snaku.begin(),1, vertebra);
  }

  pair<int,int> aux;
  for(int i = 0; i < snaku.size(); i++){
    aux = snaku[i];
    grid[aux.first][aux.second] = 1;
  }

  for(int i = 0; i < grid.size(); i++){
    for(int j = 0; j < grid[i].size(); j++){
      if(grid[i][j] == 1 || grid[i][i] == 2){
        img.at<Vec3b>(Point(j,i)) = white;
      }
      else if(grid[i][j] == 3){
        img.at<Vec3b>(Point(j,i)) = blue;
      }
    }
  }


  resize(img, img, Size(), 25, 25, INTER_NEAREST);

  //namedWindow("A_good_name", CV_WINDOW_AUTOSIZE);

  bool lalala = true;
    imshow("A_good_name", img);

    int dir = waitKey(0);

    if(dir = 119){

    }

    destroyWindow("A_good_name");




  return 0;
}
