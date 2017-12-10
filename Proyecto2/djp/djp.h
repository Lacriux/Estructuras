#include<vector>

using namespace std;

class Grafo{
  public:
    Grafo();
    Grafo(int nodos);
    void crearEdge(int v1, int v2, int peso);//Funcion que crea conexiones entre los nodos para construir el grafo
    vector< vector<int> > DJP(void);//Funcion que aplica el algoritmo DJP
    void matAdyacencia(void);//Imprime la matriz de adyacencia
    void matAdyacencia(vector< vector<int> > matriz);//Imprime la matriz que recibe
  private:
    int INF;//Mayor int que se puede utilizar
    int cn; //cantidad de nodos
    vector< vector<int> > ady; //matriz de adyacencia
};

Grafo::Grafo(){}

Grafo::Grafo(int nodos){
  this->cn = nodos;
  this->ady = vector< vector<int> > (cn);
  this->INF = 2147483647;

  for(int i = 0; i < cn; i++){
    ady[i] = vector<int> (cn, INF);
  }
}

void Grafo::crearEdge(int v1, int v2, int peso){
  this->ady[v1][v2] = peso;
  this->ady[v2][v1] = peso;
}

vector< vector<int> > Grafo :: DJP(){
   //Se utiliza una copia de la matriz de adyacencias por que es necesario modificarla sin perder la original
  vector< vector<int> > adyacencia = this->ady;
  vector< vector<int> > arbol(cn);//Matriz que va a contener el MST resusltante
  vector<int> visitado;//Vector que almacena los nodos visitados
  vector<int> :: iterator it;//Iterador para recorrer vectores

  // Inicializo las distancias del arbol en INF.
  for(int i = 0; i < cn; i++){
    arbol[i] = vector<int> (cn, INF);
  }

  int nodo1 = 0;
  int nodo2 = 0;
  while(visitado.size() + 1 < cn){
    nodo1 = nodo2;

    //Se agrega el nodo actual y se inicializa la distancia a este nodo como infinita
    visitado.push_back(nodo1);
    for(int i = 0; i < cn; i++){
      adyacencia[i][nodo1] = INF;
    }

    //Se encuentra la menor distancia al nodo que se esta trabajando
    int min = INF;
    for(it = visitado.begin(); it != visitado.end(); it++){
      for(int i = 0; i < cn; i++){
        if(min > adyacencia[*it][i]){
          min = adyacencia[*it][i];
          nodo1 = *it;
          nodo2 = i;
        }
      }
    }

    //Se agraga esa distancia al Grafo que contiene el MST
    arbol[nodo1][nodo2] = min;
    arbol[nodo2][nodo1] = min;
  }
  return arbol;
}

void Grafo::matAdyacencia(void){
  cout<<0<<"\t";
  for(int i = 0; i < 10; i++){
    cout<<i<<"\t";
  }
  cout<<endl;
  for(int i = 0; i < cn; i++){
    cout<<i<<"\t";
    for(int j = 0; j < cn; j++){
      if(this->ady[i][j] == 2147483647){
        cout<<0<<"\t";
      }
      else{
        cout<<this->ady[i][j]<<"\t";
      }
    }
    cout<<endl;
  }
}

void Grafo::matAdyacencia(vector< vector<int> > matriz){
  cout<<0<<"\t";
  for(int i = 0; i < 10; i++){
    cout<<i<<"\t";
  }
  cout<<endl;
  for(int i = 0; i < cn; i++){
    cout<<i<<"\t";
    for(int j = 0; j < cn; j++){
      if(matriz[i][j] == 2147483647){
        cout<<0<<"\t";
      }
      else{
        cout<<matriz[i][j]<<"\t";
      }
    }
    cout<<endl;
  }
}
