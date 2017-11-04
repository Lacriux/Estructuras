#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
#include"algoritmos.h"

using namespace std;

int main(){
  unsigned t0, t1;
  double tiempo;
  srand(0);
  vector<int> lista, copia;
  lista.resize(10000);
  for(int i = 0; i < lista.size(); i++){
    lista[i]=rand()%10000;
  }


  copia = lista;
  t0 = clock();
  copia = bubbleSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Bubble sort: " << tiempo << "s" << endl;

  t0 = clock();
  copia = insertionSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Insertion sort: " << tiempo << "s" << endl;

  t0 = clock();
  copia = countingSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Counting sort: " << tiempo << "s" << endl;

  t0 = clock();
  copia = heapSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Heap sort: " << tiempo << "s" << endl;

  t0 = clock();
  copia = radixSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Radix sort: " << tiempo << "s" << endl;

  t0 = clock();
  copia = quickSort(lista);
  t1 = clock();
  tiempo = (double(t1-t0)/CLOCKS_PER_SEC);
  cout << "Quick sort: " << tiempo << "s" << endl;
}
