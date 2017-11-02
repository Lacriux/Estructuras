#include<iostream>
#include<vector>
#include<cstdlib>
#include"algoritmos.h"

using namespace std;

int main(){
  srand(0);
  vector<int> lista;
  lista.resize(10000);
  for(int i = 0; i < lista.size(); i++){
    lista[i]=rand()%10000;
  }
  lista = insertionSort(lista);

  // for(int i = 0; i < lista.size(); i++){
  //   cout << i+1 << "-" << lista[i] << endl;
  // }
}
