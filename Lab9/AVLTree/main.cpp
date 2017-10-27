#include"AVLTree.h"
#include<cstdio>
#include<ctime>

int main(void){
	AVLTree myTree;
	int data;

	for (int i=0; i<10; i++){
		data=rand()%100;
		cout<<"\nite: "<<i <<" ,insertando: "<<data<<endl;
		myTree.insertAVL(data);
	}
	cout<<"\nFinal Tree"<<endl;
	myTree.printTree();
	cout<<myTree.distanceN(40)<<endl;

	return 0;
}
