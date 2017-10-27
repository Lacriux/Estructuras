#include<iostream>
#include"pila.h"

using namespace std;

#ifndef CLASECOLA
#define CLASECOLA

class Cola: public C_base<int>{
  protected:
    C_pila<int> pila;
    C_pila<int> pilaAux;

  public:
    Cola(){}

    ~Cola(){
      cout << "Destructor de cola" << endl;
      while(pila.count() != 0){
        pila.pull();
      }
    }

    void insertar(int dato){
      pila.push(dato);
    }

    int quitar(){
      while(pila.count() != 0){
        pilaAux.push(pila.pull());
      }
      int temp = pilaAux.pull();
      while(pilaAux.count() != 0){
        pila.push(pilaAux.pull());
      }
      return temp;
    }

};

#endif
