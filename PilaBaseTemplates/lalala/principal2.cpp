#include "cola.h"

int main (void)
{

  C_cola<int> vcola;
  C_base<int> *pCola;

  pCola = &vcola;

  for (int i=100; i<110; ++i)
  {
    pCola->agregar(i);
  }

  pCola->invert();
  pCola->agregar(1,3);
  pCola->quitar(2);

  cout <<"\n Resultado para la cola"<<endl;
  for (int i=1; i<11; ++i)
  {
     cout << i <<"-) " << pCola->quitar() << endl;
  }

}
