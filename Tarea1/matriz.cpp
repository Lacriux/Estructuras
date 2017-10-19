#include"matriz.h"
#include<iostream>

using namespace std;

C_matriz::C_matriz(int n, int m){
  this->filas = n;
  this->columnas = m;
  this->ptr_data = new float[n*m];
}

C_matriz::C_matriz(const C_matriz &matriz){
  this->filas = matriz.filas;
  this->columnas = matriz.columnas;
  this->ptr_data = new float [matriz.filas*matriz.columnas];

  for(int i=0; i<filas*columnas; i++){
    this->ptr_data[i] = matriz.ptr_data[i];
  }
}

C_matriz::~C_matriz(){
  delete [] ptr_data;
}

void C_matriz::set(int fila, int columna, float dato){
  int pos = (columna-1) + (fila-1)*columnas;
  ptr_data[pos] = dato;
}

float C_matriz::get(int fila, int columna) const{
  int pos = (columna-1) + (fila-1)*columnas;
  return ptr_data[pos];
}

void C_matriz::desplegar(){
  for(int i=1;i<=this->filas;i++){
    for(int j=1;j<=this->columnas;j++){
      cout<<get(i,j)<<"\t";
    }
    cout<<endl;//próxima fila
  }
}

float C_matriz::operator() (int fila,int columna){
  return get(fila,columna);
}

C_matriz &C_matriz::operator=(const C_matriz &mi_matriz){
  if(this->filas == mi_matriz.filas && this->columnas == mi_matriz.columnas){
    for(int i = 0; i<=this->filas*this->columnas; i++){
      this->ptr_data[i]=mi_matriz.ptr_data[i];
    }
  }
  else{
    delete [] ptr_data;
    this->filas = mi_matriz.filas;
    this->columnas = mi_matriz.columnas;
    this->ptr_data = new float[this->filas*this->columnas];
    if(this->filas == mi_matriz.filas && this->columnas == mi_matriz.columnas){
      for(int i = 0; i<=this->filas*this->columnas; i++){
        this->ptr_data[i]=mi_matriz.ptr_data[i];
        }
    }
  }
  return *this;
}

// C_matriz C_matriz::operator+(const C_matriz &mi_matriz){
//   if(this->filas == mi_matriz.filas && this->columnas == mi_matriz.columnas){
//     int n = this->filas;
//     int m = this->columnas;
//     C_matriz nueva_matriz (n,m);
//     for(int i=0; i < this->filas*this->columnas; i++){
//       nueva_matriz.ptr_data[i] = this->ptr_data[i]+mi_matriz.ptr_data[i];
//     }
//   return nueva_matriz;
//   }
//   else{
//     cout<<"Error. Las matrices no poseen el mismo tamaño"<<endl;
//     return mi_matriz;
//   }
// }

C_matriz C_matriz::operator*(const float &escalar){
  C_matriz nueva_matriz (this->filas, this->columnas);
  for(int i=0; i<this->filas*this->columnas; i++){
    nueva_matriz.ptr_data[i] = this->ptr_data[i] * escalar;
  }
  return nueva_matriz;
}

int C_matriz::getFilas(){
  return this->filas;
}

int C_matriz::getColumnas(){
  return this->columnas;
}
