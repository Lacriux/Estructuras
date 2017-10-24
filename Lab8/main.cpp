#include<iostream>
#include"C_Heap.h"

using namespace std;

int main(void){

  srand(874869);

  C_Heap nuevo_Heap(30, 0);

  for(int i = 0; i < 20; i++){
    int dato = rand() % 100;
    cout << dato << "\t";
    nuevo_Heap.insert(dato);
  }

  cout << endl;

  cout << "Capacidad del Heap: " << nuevo_Heap.capacity() << endl;

  cout << "Numero de elementos del Heap: " << nuevo_Heap.count() << endl;

  cout << "Numero mayor del Heap: " << nuevo_Heap.getMax() << endl;

  cout << "Se elimina el numero mayor del Heap" << endl;

  nuevo_Heap.delMax();

  cout << "Nuevo numero mayor del Heap: " << nuevo_Heap.getMax() << endl;

  cout << "se cambia la capacidad del Heap a 10" << endl;

  nuevo_Heap.resizeHeap(10);

  cout << "Nueva capacidad del Heap: " << nuevo_Heap.capacity() << endl;

  cout << "Nuevo numero de elementos del Heap: " << nuevo_Heap.count() << endl;

}
