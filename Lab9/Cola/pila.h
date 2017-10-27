/*********************************************************************
*
C_pila.h
*********************************************************************
*/

#include "base.h"

#ifndef CLASEPILA
#define CLASEPILA

template <typename T>
class C_pila : public C_base<T>{
	public:
		C_pila(void);
		~C_pila(void);
		bool push(T);
		T pull(void);
		bool agregar(T);
		T quitar(void);
};

template <typename T>
C_pila<T>::C_pila(void) : C_base<T>()
{
	this->primer_elemento = NULL;
}

template <typename T>
C_pila<T>::~C_pila(void)
{
   cout << "Destructor de pila" << endl;
   while(this->primer_elemento != NULL)
    pull();
}

template <typename T>
bool C_pila<T>::push(T mi_dato)
{
	S_celda<T> *paux;
	paux = new S_celda<T>;
	paux->dato=mi_dato;
	paux->proximo=this->primer_elemento;
	this->primer_elemento=paux;
	return true;
}

template <typename T>
T C_pila<T>::pull(void)
{
	if(this->primer_elemento != NULL)
	{
		S_celda<T> *paux;
		T temp;
		paux=this->primer_elemento;
		this->primer_elemento=paux->proximo;
		temp=paux->dato;
		delete paux;
		return temp;
	}
	else
		return 0;
}

template <typename T>
bool C_pila<T>::agregar(T mi_dato)
{
	return this->push(mi_dato);
}

template <typename T>
T C_pila<T>::quitar(void)
{
	return pull();
}

#endif
