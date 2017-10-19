/*********************************************************************
*
C_cola.h
*********************************************************************
*/

#include "base.h"

#ifndef CLASEcola2
#define CLASEcola2

class C_cola2 : public C_base{
	protected:
		T_celda *ultimo_elemento;	
	public:
		C_cola2(void);
		~C_cola2(void);
		bool agregar(int);
		int quitar(void);
};
#endif