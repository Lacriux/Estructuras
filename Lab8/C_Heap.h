#import<vector>
#import<iostream>

using namespace std;

#ifndef CLASEHEAP
#define CLASEHEAP

class C_Heap{
  protected:
    vector<int> heap;
    int tipo;

  private:
    int leftChild(int pos, vector lista){
      return lista[2 * i + 1];
    }
    int rightChild(int pos, vector lista){
      return lista[2 * i + 2];
    }
    void percolateDown(){
      if(this->tipo == 0){
        
      }
    }

    comprobar(void){}

  public:
    C_Heap(){
      this->heap = new vector<int>(1);
      this->heap[0] = -1;
      this->tipo = 0;
    }

    C_Heap(int size, int type){
      this->heap= new vector<int>(size);
      this->tipo = type;
      for(int i = 0; i < this->heap.size(); i++){
        this->heap[i] = -1;
      }
    }

    ~C_Heap(){
      cout << "Desctructor" << end;
      del this->heap;
      del this->tipo;
    }

    int getMax(void){
      return this->heap[0];
    }

    int delMax(void){}

    void insert(int dato){
      bool flag = true;
      int i = 0;
      while(flag){
        if(this->heap[i] == -1){}
        else{
          flag = false;
          this->heap[i] = dato;
        }
        i++;
      }
      //Comprobar que el heap se cumple
    }

    capacity(){}
    resizeHeap(){}
    count(){}
}
