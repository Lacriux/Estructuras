#include<iostream>
#include<vector>

using namespace std;

struct subset{
  int padre;
  int rango;
};

struct Edge{
  int v1;
  int v2;
  int peso;
};

class Grafo{
  public:
    Grafo();
    Grafo(int nodos, int edges);
    void crearEdge(int v1, int v2, int peso, int i);//Funcion que crea conexiones entre los nodos para construir el grafo
    vector< vector<int> > boruvka(void);//Funcion que aplica el algoritmo Boruvka
    void matAdyacencia(void);//Imprime la matriz de adyacencia
    void matAdyacencia(vector< vector<int> > matriz);//Imprime la matriz que recibe
  private:
    int cn; //cantidad de nodos
    int ed; //cantidad de edges
    Edge *edge;//Vector de Edges que almacena las conexiones del Grafo;
    Edge *edge2;//Vector de Edges que almacena las conexiones del MST correspondiente al grafo;
    vector< vector<int> > ady; //matriz de adyacencia
    int buscar(struct subset subsets[], int i);
    void unir(struct subset subsets[], int x, int y);
    vector< vector<int> > matAdyMST(void);
};

Grafo::Grafo(){}

Grafo::Grafo(int nodos, int edges){
  this->cn = nodos;
  this->ed = edges;
  this->ady = vector< vector<int> > (cn);
  for(int i = 0; i < cn; i++){
    ady[i] = vector<int> (cn, 0);
  }
  this->edge = new Edge[edges];
  this->edge2 = new Edge[nodos];
  Edge*aux = new Edge;
  aux->v1 = 0;
  aux->v2 = 0;
  aux->peso = 0;
  for(int i = 0; i < cn; i++){
    edge2[i] = *aux;
  }
}

void Grafo::crearEdge(int v1, int v2, int peso, int i){
  this->edge[i].v1 = v1;
  this->edge[i].v2 = v2;
  this->edge[i].peso = peso;
  this->ady[v1][v2] = peso;
  this->ady[v2][v1] = peso;
}

vector< vector<int> >Grafo::boruvka(void){
  //Se crea una copia del grafo que se seta utilizando
  int V = cn, E = ed;
  Edge *edge = this->edge;

  //Se pide memoria para la cantidad de subsets necesarios(uno por cada nodo);
  struct subset *subsets = new subset[V];

  //Array para guardar el peso minimo de cada subset
  int *minPeso = new int[V];

  //Se crean un subset para cada nodo
  for (int v = 0; v < V; ++v){
    subsets[v].padre = v;
    subsets[v].rango = 0;
    minPeso[v] = -1;
  }

  //Inicialmente hay V diferentes grafos, cada uno consiste en un nodo individual
  //Finalmente habra solo un grafo que corresponde al MST del grafo original
  int numGrafos = V;

  //Se continua combinando subsets hasta que solo quede uno
  while (numGrafos > 1){
    //Se recorre todos los edges y se actualiza el minimo peso de cada uno
    for (int i=0; i<E; i++){
      //Se encuentran los nodos que corresponden al edge actual
      int set1 = buscar(subsets, edge[i].v1);
      int set2 = buscar(subsets, edge[i].v2);

      //Si los dos nodos del edge actual pertenecen al mismo set, se ignora el edge
      if (set1 == set2)
        continue;
      //Si no comprueba si el edge actual tiene menor peso que el anterior peso del set1 y set2
      if (minPeso[set1] == -1 || edge[minPeso[set1]].peso > edge[i].peso){
        minPeso[set1] = i;
      }
      if (minPeso[set1] == -1 || edge[minPeso[set2]].peso > edge[i].peso){
       minPeso[set2] = i;
      }
    }

    //Se agrega el edge de peso minimo al MST
    for (int i=0; i<V; i++){
      //Se comprueba si existe el nodo correspondiente a este peso minimo
      if (minPeso[i] != -1){
        int set1 = buscar(subsets, edge[minPeso[i]].v1);
        int set2 = buscar(subsets, edge[minPeso[i]].v2);
        if(set1 == set2){}
        else{
          Edge *aux = new Edge;
          aux->v1 = edge[minPeso[i]].v1;
          aux->v2 = edge[minPeso[i]].v2;
          aux->peso = edge[minPeso[i]].peso;

          this->edge2[i] = *aux;
          //Une el set1 y el set2. Y se decrece el numero de Grafos
          unir(subsets, set1, set2);
        }
        numGrafos--;
      }
    }
  }
  return matAdyMST();
}

//Funcion que busca el set correspondiente al elemento i
int Grafo::buscar(struct subset subsets[], int i){
  if (subsets[i].padre != i){
    subsets[i].padre = buscar(subsets, subsets[i].padre);
  }
  return subsets[i].padre;
}

//Funcion que crea la union de dos sets x, y
void Grafo::unir(subset subsets[], int x, int y){
  int xroot = buscar(subsets, x);
  int yroot = buscar(subsets, y);

  if (subsets[xroot].rango < subsets[yroot].rango){
  subsets[xroot].padre = yroot;
  }
  else if (subsets[xroot].rango > subsets[yroot].rango){
    subsets[yroot].padre = xroot;
  }

  else{
    subsets[yroot].padre = xroot;
    subsets[xroot].rango++;
  }
}

//Esta Funcion convierte el array de Edges en la matriz de adyacencia correspondiente al MST del grafo
vector< vector<int> > Grafo::matAdyMST(void){
  vector< vector<int> > MST;
  MST = vector< vector<int> > (cn);

  for(int i = 0; i < cn; i++){
    MST[i] = vector<int> (cn, 0);
  }

  for(int i = 0; i < cn; i++){
    MST[edge2[i].v1][edge2[i].v2] = edge2[i].peso;
    MST[edge2[i].v2][edge2[i].v1] = edge2[i].peso;
  }

  return MST;
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
