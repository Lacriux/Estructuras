/*********************************************************************
*
C_base.h
*********************************************************************
*/
#include<string>
#include<iostream>

using namespace std;

#ifndef CLASEBASE
#define CLASEBASE

template <typename T>
struct S_celda{
	T dato;
	S_celda *proximo;
	S_celda *anterior;
};

template <typename T>
class C_base {
	protected:
		S_celda<T>* primer_elemento;
	public:
	C_base(void);
		virtual ~C_base(void){
			cout << "Destructor de base" << endl;
		}
		virtual bool agregar(T){
			return false;
		}
		virtual bool agregar(T, int){
			return false;
		}
		virtual T quitar(void){
			return 0;
		}
		virtual T quitar(int){
			return 0;
		}
		void clear(void){
			S_celda<T> *paux, *paux2;
			paux=this->primer_elemento;
			paux2=paux->anterior;
			while(this->primer_elemento != paux2){
				paux=this->primer_elemento;
		 		this->primer_elemento=paux->proximo;
		 		delete paux;
			}
			delete paux2;
			this->primer_elemento = NULL;
		}

		void invert(void){
			S_celda<T> *paux, *paux2;
			paux = this->primer_elemento;
			paux2 = this->primer_elemento->proximo;
			for(int i = 1; i < this->count(); i++){
				paux2 = paux->proximo;
				paux->proximo = paux->anterior;
				paux->anterior = paux2;
				paux = paux2;
			}
			}


		int count(void){
			S_celda<T> *paux;
			paux = this->primer_elemento;
			int cont;
			if (this->primer_elemento == NULL){
				cont = 0;
			}
			else{
				cont = 1;
				paux = paux->proximo;

				while(paux!= NULL){
					paux=paux->proximo;
					cont++;
				}
			}
			return cont;
		}

		void mostrar(void){
			S_celda<T> *paux;
			paux = this->primer_elemento;
			if(this->primer_elemento == NULL){
				cout<<"Error. La Lista esta vacia"<<endl;
			}
			else{
					int i = 0;
				cout<< "1" <<	"-) " << paux->dato << endl;
				paux = paux->proximo;
					i = 2;
				while(paux!=this->primer_elemento){
					cout << i <<"-) " << paux->dato << endl;
					paux = paux->proximo;
					i++;
				}
			}
		}

};

template <typename T>
C_base<T>::C_base(void)
{
	this->primer_elemento=NULL;
}
#endif
