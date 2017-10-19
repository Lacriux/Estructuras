#include"arbol.h"
#include<iostream>
#include <ctime>

using namespace std;

int main(void){
  srand(874869);
  C_BinTree arbolito;

  for(int i = 0; i < 10; i++){
    int dato = rand() % 100;
    cout << dato << endl;
    arbolito.insertAVL(dato);
  }

  // cout << "Se imprime el arbol usando el metodo preOrder" << endl;
  // arbolito.preOrder();
  //
  // cout << "Se imprime el arbol usando el metodo inOrder" << endl;
  // arbolito.inOrder();
  //
  // cout << "Se imprime el arbol usando el metodo postOrder" << endl;
  // arbolito.postOrder();
  //
  //cout << "Altura del arbol: " << arbolito.height() << endl;

  // cout << "Esta el numero 10?" << endl;
  // bool esta = arbolito.BuscarElemento(10);
  // cout << esta << endl;
  //
  // cout << "Esta el numero 77?" << endl;
  // esta = arbolito.BuscarElemento(77);
  // cout << esta << endl;

  // cout << "Numero minimo: "<< arbolito.min() << endl;
  // cout << "Numero maximo: "<< arbolito.max() << endl;

  // arbolito.~C_BinTree();
  //
  // arbolito.preOrder();


  arbolito.printTree();

  return 0;
}
