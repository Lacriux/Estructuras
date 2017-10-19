/*********************************************************************
*
C_cola.h
*********************************************************************
*/

#include "base.h"

#ifndef CLASEcola
#define CLASEcola

template <typename T>
class C_cola : public C_base<T>{
	public:
		C_cola(void);
		~C_cola(void);
		bool agregar(T,int);
		bool agregar(T);
		T quitar(void);
		T quitar(int);
};

template <typename T>
C_cola<T>::C_cola(void) : C_base<T>()
{
	this->primer_elemento = NULL;
}

template <typename T>
C_cola<T>::~C_cola(void)
{
	cout << "Destructor de cola" << endl;
	// while(this->count()!=0){
	//  quitar();
	// }
}

template <typename T>
bool C_cola<T>::agregar(T mi_dato)
{
	S_celda<T> *paux;
	paux = new S_celda<T>;

	paux->dato=mi_dato;
	if(this->count()== 0){
		this->primer_elemento=paux;
		paux->proximo=paux;
		paux->anterior=paux;
	}
	if (this->count() == 1){
		S_celda<T> *paux3 = this->primer_elemento;
		paux3->proximo=paux;
		paux3->anterior=paux;
		paux->proximo= paux3;
		paux->anterior=paux3;
	}
	if(this->count() > 1){
		S_celda<T> *paux2, *paux3;
		paux2 = this->primer_elemento;
		paux3 = this->primer_elemento;
		paux2 = paux2->anterior;
		paux2->proximo=paux;
		paux->anterior=paux2;
		paux->proximo=this->primer_elemento;
		paux3->anterior = paux;
	}

	return true;
}

template <typename T>
bool C_cola<T>::agregar(T mi_dato, int pos)
{
	S_celda<T> *paux, *paux2;
	paux = new S_celda<T>;
	int cont = 1;
	int size;

	size = this->count();

	paux->dato=mi_dato;
	paux2 = this->primer_elemento;

	if(size == 0 && pos == 1){
		this->primer_elemento = paux;
		paux->proximo = this->primer_elemento;
		paux->anterior = this->primer_elemento;
	}
	else{
		if(size < pos){
			cout<<"ERROR: El tamaño de la cola es menor a la posicion deseada"<<endl;
		}

		else{
			while(cont<pos-1){
				paux2 = paux2->proximo;
				cont++;
			}
			paux->proximo = paux2->proximo;
			paux->anterior = paux2;
			paux2->proximo = paux;
			paux2 = paux->proximo;
			paux2->anterior = paux;

		}
	}

	return true;
}

template <typename T>
T C_cola<T>::quitar(void)
{
	if(this->primer_elemento != NULL)
	{
		S_celda<T> *paux, *paux2;
		T temp;
		paux=this->primer_elemento;
		paux2=paux->anterior;
		this->primer_elemento=paux->proximo;
		temp=paux->dato;
		delete paux;
		paux = this->primer_elemento;
		paux->anterior = paux2;
		return temp;
	}
	else{
		return 0;
	}
}

template <typename T>
T C_cola<T>::quitar(int pos)
{
	T tdato;
	S_celda<T> *paux, *paux2, *paux3;
	int cont = 1, size;
	size = this->count();

	paux = this->primer_elemento;
	paux2 = paux->proximo;

	if(size < pos){
		cout<<"ERROR: El tamaño de la cola es menor a la posicion deseada"<<endl;
	}
	else{
		for(int i = 1; i < pos-1; i++){
			paux = paux->proximo;
		}
		paux2 = paux->proximo;
		paux3 = paux2->proximo;
		paux->proximo = paux3;
		paux3->anterior = paux;
		tdato = paux2->dato;
		delete paux2;
	}
	return tdato;
}
#endif
