#include<iostream>

using namespace std;

int main(){
  int key = 999999999;
  int aux = 0;
  for(int i = 1; i <= 100000000; i *= 10){
    cout<<(key/i)%10<<endl;
    aux += (key/i)%10;
  }
  cout<<aux<<endl;
}
