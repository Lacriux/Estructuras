#include<iostream>
#include"grafo.h"

using namespace std;

int main(){
  Grafo miGrafo(6);

  miGrafo.edge(0,1);
  miGrafo.edge(1,0);
  miGrafo.edge(1,2);
  miGrafo.edge(1,3);
  miGrafo.edge(2,1);
  miGrafo.edge(2,4);
  miGrafo.edge(2,5);
  miGrafo.edge(3,1);
  miGrafo.edge(3,4);
  miGrafo.edge(4,2);
  miGrafo.edge(4,3);
  miGrafo.edge(5,2);

  cout << "DFS" << endl;
  miGrafo.DFS();

  cout << "BFS" << endl;
  miGrafo.BFS();
}
