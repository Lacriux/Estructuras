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

typedef struct S_celda{
	int dato;
	S_celda *proximo;
}T_celda;

class C_base {
	protected:
		T_celda *primer_elemento;
	public:
	C_base(void);
		virtual ~C_base(void){
			cout << endl;
		}
		virtual bool agregar(int){
			return false;
		}
		virtual int quitar(void){
			return 0;
		}
};
#endif