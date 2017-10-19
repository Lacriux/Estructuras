#include "pila.h"
#include "cola.h"

int main (void)
{

  // cout<<"************************Aqui se trabaja con pila************************"<<endl;
  // C_pila<int> vpila;
  // C_base<int> *pBase;
  //
  // pBase = &vpila;
  //
  // for (int i=100; i<110; ++i)
  // {
  // 	pBase->agregar(i);
  // }
  //
  // cout<<"Numero de elementos en la pila "<< pBase->count()<<endl;
  //
  // cout << "Se invierte la pila" << endl;
  //
  // pBase->invert();
  //
  // cout <<"\nResultado para la pila"<<endl;
  // pBase->mostrar();
  //
  // cout << "Se vacia la pila" << endl;
  // pBase->clear();
  //
  // cout << "\nSe rellena la pila con nuevos datos" << endl;
  // for (int i=1; i<11; ++i)
  // {
  // 	pBase->agregar(i);
  // }
  //
  // cout <<"\nResultado para la pila"<<endl;
  // pBase->mostrar();

  cout<<endl;
  cout<<"************************Aqui se trabaja con Lista************************"<<endl;
  C_cola<int> vcola;
  C_base<int> *pBase2;

  pBase2 = &vcola;

  for (int i=1; i<10; ++i)
  {
  	pBase2->agregar(i);
  }

  cout<<"Contenido de la cola"<<endl;
  pBase2->mostrar();

  cout<<"Se agrega el numero 25 en la posicion 8 de la cola"<<endl;
  pBase2->agregar(25, 8);

  cout<<"Contenido de la cola"<<endl;
  pBase2->mostrar();

  cout<<"Se elimina el quinto elemento de la cola"<<endl;
  pBase2->quitar(5);

  pBase2->mostrar();

  cout<<"Se invierte la lista"<<endl;

  pBase2->invert();

  cout<<"Nuevo contenido de la cola"<<endl;
  pBase2->mostrar();

}
