#include <ctime>
#include "cola2.h"
#include<cstdlib>

#define ITE 100000000

bool myFunc();

int main (void)
{
	int flag=1;
	while(flag){
		myFunc();
		cout << "\nDigite 0 para salir: ";
		cin >> flag;
	}
}

bool myFunc(){
	C_cola2 tCola;

	for(int i=0; i<ITE;i++){
		tCola.agregar(rand());
	}
	return true;
}

