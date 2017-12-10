#include<iostream>
#include<vector>
#include"boruvka.h"

using namespace std;

int main(){
  Grafo miGrafo(10, 18);

  miGrafo.crearEdge(0,6,7, 0);
  miGrafo.crearEdge(0,7,6, 1);
  miGrafo.crearEdge(0,9,2, 2);
  miGrafo.crearEdge(1,2,3, 3);
  miGrafo.crearEdge(1,5,2, 4);
  miGrafo.crearEdge(2,3,4, 5);
  miGrafo.crearEdge(2,5,2, 6);
  miGrafo.crearEdge(2,6,8, 7);
  miGrafo.crearEdge(3,4,2, 8);
  miGrafo.crearEdge(3,6,10, 9);
  miGrafo.crearEdge(3,7,5, 10);
  miGrafo.crearEdge(4,7,1, 11);
  miGrafo.crearEdge(5,6,3, 12);
  miGrafo.crearEdge(5,8,1, 13);
  miGrafo.crearEdge(5,9,2, 14);
  miGrafo.crearEdge(6,7,4, 15);
  miGrafo.crearEdge(6,9,10, 16);
  miGrafo.crearEdge(8,9,3, 17);

  cout<<"Matriz de adyacencia del grafo inicial"<<endl;
  miGrafo.matAdyacencia();
  cout<<endl;

  vector< vector<int> > mst;
  mst = miGrafo.boruvka();

  cout<<"Matriz de adyacencia del grafo que resulta de aplicar al algoritmo DJP"<<endl;
  miGrafo.matAdyacencia(mst);
}
