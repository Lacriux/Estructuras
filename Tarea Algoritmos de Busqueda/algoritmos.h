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

vector<int> percolateDown(vector<int> lista, int pos, int tam){

  int left = 2*pos+1;
  int right = 2*pos+2;
  if(left < tam){
    if(lista[pos] < lista[left] && lista[left]!= -1){
      int temp = lista[pos];
      lista[pos] = lista[left];
      lista[left] = temp;
      if(left < tam){
        percolateDown(lista, left, tam);
      }
    }
  }
  if(right < tam){
    if(lista[pos] < lista[right] && lista[right] != -1){
      int temp = lista[pos];
      lista[pos] = lista[right];
      lista[right] = temp;
      if(right < tam){
        percolateDown(lista, right, tam);
      }
    }
  }

  return lista;
}

vector<int> heapSort(vector<int>lista){
  int n = lista.size();
  int temp;
  for (int i = n / 2 - 1; i >= 0; i--){
    lista = percolateDown(lista, i, n);
  }

  for (int i=n-1; i>=0; i--){
    temp = lista[0];
    lista[0] = lista[i];
    lista[i] = temp;

    lista = percolateDown(lista, 0, i);
  }

  return lista;
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

vector<int> quickSort(vector<int> lista, int left, int right) {
  int i = left, j = right;
  int tmp;
  int pivot = lista[(left + right) / 2];

  while (i <= j) {
    while (lista[i] < pivot){
      i++;
    }
    while (lista[j] > pivot){
      j--;
    }
    if (i <= j) {
      tmp = lista[i];
      lista[i] = lista[j];
      lista[j] = tmp;
      i++;
      j--;
    }
  };

  if (left < j){
    lista = quickSort(lista, left, j);
  }
  if (i < right){
    lista = quickSort(lista, i, right);
  }

  return lista;
}

vector<int> quickSort(vector<int> lista){
  lista = quickSort(lista, 0, lista.size()-1);
  return lista;
}
