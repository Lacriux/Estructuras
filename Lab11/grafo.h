#include<iostream>
#include<vector>
#include<queue>
#include<utility>

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

    void edge(int v1, int v2, int weight){
      matriz[v1][v2] = weight;
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

    vector<vector<int> > shortPath(int nodo){
      vector<vector<int> > tabla;
      tabla.resize(matriz.size());
      for(int i = 0; i < matriz.size(); i++){
        tabla[i].resize(3, -1);
      }
      for(int i = 0; i < matriz.size(); i++){
        tabla[i][0] = i;
      }

      queue<int> cola;
      cola.push(nodo);
      tabla[nodo][1] = 0;
      while(!cola.empty()){
        int n = cola.front();
        cola.pop();
        for(int i = 0; i < matriz.size(); i++){
          if(matriz[n][i] == 1){
            if(tabla[i][1] == -1){
              tabla[i][1] = tabla[n][1] + 1;
              tabla[i][2] = n;
              cola.push(i);
            }
          }
        }
      }
      return tabla;
    }

    vector<vector<int> > shortWeightPath(int nodo){
      vector<vector<int> > tabla;
      tabla.resize(matriz.size());
      for(int i = 0; i < matriz.size(); i++){
        tabla[i].resize(3, -1);
      }
      for(int i = 0; i < matriz.size(); i++){
        tabla[i][0] = i;
      }

      priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > cola;
      pair<int,int> par;
      par = make_pair(0,nodo);
      cola.push(par);
      tabla[nodo][1] = 0;
      while(!cola.empty()){
        pair<int,int> aux = cola.top();
        int n = aux.second;
        cola.pop();
        for(int i = 0; i < matriz.size(); i++){
          if(matriz[n][i] != 0){
            int distancia;
            distancia = aux.first + matriz[n][i];
            if(tabla[i][1] == -1 || tabla[i][1] > distancia){
              tabla[i][1] = distancia;
              tabla[i][2] = n;
              par.first = distancia;
              par.second = i;
              cola.push(par);
            }
          }
        }
      }
      return tabla;
    }
};
#endif
