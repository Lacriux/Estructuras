#include<iostream>
#include<vector>
#include<queue>

using namespace std;

#ifndef CLASEGRAFO
#define CLASEGRAFO

class Grafo{

  private:
    vector<int> visitado;
    vector<vector<int>> matriz;
    queue<int> lista;

    void DFS(int fila){
      visitado[fila] = 1;
      cout << fila << endl;
      for(int i = 0; i < matriz.size(); i++){
        if(matriz[fila][i] == 1){
          if(visitado[i] == 0){
            DFS(i);
          }
        }
      }

    }

  public:
    Grafo(int vertices){
      matriz.resize(vertices);
      for(int i = 0; i < matriz.size(); i++){
        matriz[i].resize(vertices, 0);
      }
      visitado.resize(vertices, 0);
    }

    void edge(int v1, int v2){
      matriz[v1][v2] = 1;
    }

    void DFS(void){
      visitado.clear();
      visitado.resize(matriz.size(), 0);
      DFS(0);
    }

    void BFS(void){
      visitado.clear();
      visitado.resize(matriz.size(), 0);
      lista.push(0);
      int vertice;
      while(!lista.empty()){
        vertice = lista.front();
        if(visitado[vertice] == 0){
          cout << vertice << endl;
        }
        visitado[vertice] = 1;
        lista.pop();
        for(int i = 0; i < matriz.size(); i++){
          if(matriz[vertice][i] == 1){
            if(visitado[i] == 0){
              lista.push(i);
            }
          }
        }
      }
    }

};
#endif
