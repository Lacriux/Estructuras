#include<iostream>
#include<vector>

using namespace std;

vector<int> bubbleSort(vector<int> lista){
  for(int i = 0; i<lista.size()-1; i++){
    for(int j = 0; j<lista.size()-1; j++){
      if(lista[j] > lista[j+1]){
        int temp = lista[j];
        lista[j] = lista[j+1];
        lista[j+1] = temp;
      }
    }
  }

  return lista;
}

vector<int> insertionSort(vector<int> lista){
  for (int i = 0; i < lista.size(); i++){
    int temp = lista[i];
    int j = i-1;
    while(j >= 0 && lista[j] > temp){
      lista[j+1] = lista[j];
      j--;
    }
    lista[j+1] = temp;
  }

  return lista;
}

vector<int> countingSort(vector<int> lista){
  vector<int> aux;
  vector<int> aux2;
  int mayor = 0;
  for(int i = 0; i < lista.size(); i++){
    if(lista[i] > mayor){
      mayor = lista[i];
    }
  }
  aux.resize(mayor, 0);
  aux2.resize(lista.size(), 0);
  for(int i = 0; i < lista.size(); i++){
    aux[lista[i]]++;
  }
  int cont = 0;
  int cont2 = 0;
  while(cont2 < lista.size()){
    if(aux[cont] == 0){
      cont++;
    }
    else{
      aux2[cont2] = cont;
      aux[cont]--;
      cont2++;
    }
  }
  return aux2;
}

vector<int> radixSort(vector<int> lista){
  vector<vector<int> > matriz;
  vector<int> listaAux;
  matriz.resize(10);
  int mayor = 0;
  for(int i = 0; i < lista.size(); i++){
    if(lista[i] > mayor){
      mayor = lista[i];
    }
  }
  int aux;
  for(int l = 1; mayor/l > 1; l *=10){
    for(int i = 0; i < lista.size(); i++){
      aux = (lista[i]/l)%10;
      matriz[aux].push_back(lista[i]);
    }
    for(int i = 0; i < 10; i++){
      for(int j = 0; j < matriz[i].size(); j++){
        listaAux.push_back(matriz[i][j]);
      }
    }
    lista = listaAux;
    listaAux.clear();
    for(int i = 0; i < 10; i++){
      matriz[i].clear();
    }
  }
  return lista;
}
