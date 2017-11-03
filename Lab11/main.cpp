#include<iostream>
#include<vector>
#include"grafo.h"

using namespace std;

int main(){
  Grafo miGrafo(6);

  miGrafo.edge(0,1);
  miGrafo.edge(0,2);
  miGrafo.edge(1,3);
  miGrafo.edge(2,1);
  miGrafo.edge(2,3);
  miGrafo.edge(2,4);
  miGrafo.edge(3,5);
  miGrafo.edge(4,3);

  vector<vector<int> > miVector = miGrafo.shortPath(2);

  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 3; j++){
      cout << miVector[i][j] << "\t";
    }
    cout << endl;
  }

}
