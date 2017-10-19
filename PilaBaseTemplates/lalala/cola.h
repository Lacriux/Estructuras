
#include "base.h"

#ifndef CLASEcola
#define CLASEcola

template <typename T>
class C_cola : public C_base<T>{
	public:
		C_cola(void);
		~C_cola(void);
		bool agregar(T);
		T quitar(void);
		bool agregar(T,int);
		T quitar(int);

};

template <typename T>
C_cola<T>::C_cola(void) : C_base<T>()
{
//	primer_elemento = NULL;
}

template <typename T>
C_cola<T>::~C_cola(void)
{
   cout << "Destructor de cola" << endl;
  // while(this->primer_elemento != NULL)
   // quitar();
}

template <typename T>
bool C_cola<T>::agregar(T mi_dato, int posicion)
{

	if(this->count()<posicion){

	}

	else{
		S_celda<T> *paux;
		S_celda<T> *paux2;
		paux2=this->primer_elemento;
		paux = new S_celda<T>;
		paux->dato = mi_dato;

		for(int i= 0;i<posicion-1;i++){
			paux2 = paux2->proximo;
		}
		paux2->anterior->proximo=paux;
		paux2->anterior=paux;
		paux->proximo=paux2;
		paux->anterior=paux2->anterior;
	}
	return true;
}

template <typename T>
T C_cola<T>::quitar(int posicion)
{
	if(this->count()<posicion){
	}
	else{
		S_celda<T> *paux;
		S_celda<T> *paux2;
		paux = this->primer_elemento;
		for(int i=0; i<posicion-1;i++){
			paux = paux->proximo;
		}
		T dato = paux->dato;
		paux->anterior->proximo=paux->proximo;
		paux->proximo->anterior=paux->anterior;

		return dato;
	}

}

template <typename T>
bool C_cola<T>::agregar(T mi_dato)
{
	S_celda<T> *paux;
	paux = new S_celda<T>;
	paux->dato=mi_dato;


	if(this->primer_elemento==NULL){
		this->primer_elemento=paux;
		paux->proximo=paux;
		paux->anterior=paux;

	}
	else{
		paux->anterior=this->primer_elemento->anterior;
		this->primer_elemento->anterior->proximo=paux;
		this->primer_elemento->anterior=paux;

		paux->proximo=this->primer_elemento;
	}

	return true;
}

template <typename T>
T C_cola<T>::quitar(void)
{
	int tdato=0;
	S_celda<T> *paux;

	if(this->primer_elemento!=NULL){
		tdato=this->primer_elemento->dato;
		paux=this->primer_elemento;
		this->primer_elemento=this->primer_elemento->proximo;
		this->primer_elemento->anterior=paux->anterior;
		this->primer_elemento->anterior->proximo=paux->anterior->proximo;
	}
	else{

	}

	return tdato;
}

#endif
