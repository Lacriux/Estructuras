#ifndef MATRIZ_H
#define MATRIZ_H

class C_matriz{
  public:
    C_matriz(int=1, int=1);//parámetros por defecto, estos son fila, columna
    C_matriz(const C_matriz &);//constructor de copia
    ~C_matriz();

    float get(int fila, int columna) const; //retorna un elemento de la matriz
    void set(int fila, int columna ,float dato); //graba un elemento en una posición de la matriz
    C_matriz &operator=(const C_matriz &); //Operador de asignación
    float operator()(int, int); //Operador para seleccionar un elemento en la matriz, similar a get
    void desplegar(void); //método para desplegar toda la matriz, por filas y columnas
    C_matriz operator+(const C_matriz &); //suma dos matrices
    C_matriz operator*(const float &); //multiplica una matriz por un flotante
    int getFilas(void);
    int getColumnas(void);

  private:
    int filas;
    int columnas;
    float *ptr_data;
};
#endif
