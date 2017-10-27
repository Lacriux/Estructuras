#include<iostream>
#include"cola.h"

using namespace std;

int main(){
  Cola cola1;

  for(int i = 1; i < 11; i++){
    cout << i << "\t";
    cola1.insertar(i);
  }
  cout << endl;

  for(int i = 1; i < 11; i++){
    cout << i << ") " << cola1.quitar() << endl;
  }

}
