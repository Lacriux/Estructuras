#include "cola2.h"


C_cola2::C_cola2(void) : C_base()
{
	ultimo_elemento = NULL;
}

C_cola2::~C_cola2(void)
{
   cout << endl;
//   while(primer_elemento != NULL)
//   	quitar();
}

bool C_cola2::agregar(int mi_dato)
{
	T_celda *paux;
	paux = new T_celda;

	paux->dato=mi_dato;
	paux->proximo=NULL;

	if(primer_elemento==NULL){
		primer_elemento=paux;
		ultimo_elemento=paux;
	}

	else{
		ultimo_elemento->proximo=paux;
		ultimo_elemento=paux;
	}

	return true;
}

int C_cola2::quitar(void)
{
	int tdato=0;
	T_celda *paux;

	if(primer_elemento!=NULL){
		paux=primer_elemento;

		tdato=primer_elemento->dato;
		primer_elemento=primer_elemento->proximo;
		delete paux;
	}
	return tdato;
}
