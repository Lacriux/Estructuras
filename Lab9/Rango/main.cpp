#include<iostream>
#include"arbol.h"
#include<cstdlib>

using namespace std;

int main(){
  C_BinTree arbolito;

  for(int i = 0; i < 10; i++){
    int dato = rand() % 100;
    cout << dato << endl;
    arbolito.insertBTS(dato);
  }

  arbolito.preOrder();
  arbolito.eliminarRango(20, 40);
  arbolito.preOrder();
}
