#include<iostream>
#include<vector>
#include"grafo.h"

using namespace std;

int main(){
  Grafo miGrafo(7);

  miGrafo.edge(0,2,4);
  miGrafo.edge(0,3,1);
  miGrafo.edge(1,0,2);
  miGrafo.edge(1,4,5);
  miGrafo.edge(1,6,2);
  miGrafo.edge(2,1,1);
  miGrafo.edge(2,3,3);
  miGrafo.edge(2,5,2);
  miGrafo.edge(3,5,2);
  miGrafo.edge(5,4,2);

  vector<vector<int> > miVector = miGrafo.shortWeightPath(0);

  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 3; j++){
      cout << miVector[i][j] << "\t";
    }
    cout << endl;
  }

}
