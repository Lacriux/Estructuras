#include<iostream>
#include"hash.h"

using namespace std;

int main(){
  int i = 123456789;
  int j = 987654321;
  int k = 234567890;
  int l = 587432956;
  int m = 659243765;
  int n = 759654070;

  Hash myHash;

  cout<<"Se insertan 5 datos al hash"<<endl;
  myHash.hashInsert(i);
  myHash.hashInsert(j);
  myHash.hashInsert(k);
  myHash.hashInsert(l);
  myHash.hashInsert(m);
  myHash.hashInsert(n);

  cout<<"Se pregunta si uno de ellos esta"<<endl;
  bool is = myHash.hashSearch(l);
  cout<<"Esta: ";
  if(is){
    cout<<"Si"<<endl;
  }
  else{
    cout<<"No";
  }

  cout<<"Se elimina el dato que se prengunto anteriormente"<<endl;
  myHash.hashDelete(l);
  cout<<"Se vuelve a preguntar si esta"<<endl;
  is = myHash.hashSearch(l);
  cout<<"Esta: ";
  if(is){
    cout<<"Si"<<endl;
  }
  else{
    cout<<"No";
  }
}
