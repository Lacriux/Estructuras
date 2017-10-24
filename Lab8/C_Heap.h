#include<vector>
#include<iostream>

using namespace std;

#ifndef CLASEHEAP
#define CLASEHEAP

class C_Heap{
  protected:
    vector<int> heap;
    int tipo;

  private:
    int leftChild(int pos){
      int n = count()/2 - 1;
      int m = 2*pos + 1;
      if(pos < n){
        return this->heap[m];
      }
      else{
        return -1;
      }
    }

    int rightChild(int pos){
      int n = count()/2 - 1;
      int m = 2*pos + 2;
      if(pos < n){
        return this->heap[m];
      }
      else{
        return -1;
      }
    }

    void percolateDown(int pos){
      if(this->tipo == 0){
        int left = leftChild(pos);
        int right = rightChild(pos);
        if(this->heap[pos] < left && left!= -1){
          int temp = this->heap[pos];
          this->heap[pos] = left;
          this->heap[2*pos + 1] = temp;
          percolateDown(leftChild(pos));
        }
        if(this->heap[pos] < right && right != -1){
          int temp = this->heap[pos];
          this->heap[pos] = right;
          this->heap[2*pos+2] = temp;
          percolateDown(rightChild(pos));
        }
      }
      if(this->tipo == 1){
        int left = leftChild(pos);
        int right = rightChild(pos);
        if(this->heap[pos] > left && right != -1){
          int temp = this->heap[pos];
          this->heap[pos] = left;
          this->heap[leftChild(pos)] = temp;
          percolateDown(leftChild(pos));
        }
        if(this->heap[pos] > right && right != -1){
          int temp = this->heap[pos];
          this->heap[pos] = right;
          this->heap[rightChild(pos)] = temp;
          percolateDown(rightChild(pos));
        }
      }
    }


  public:
    C_Heap(){
      this->heap.resize(1, -1);
      this->tipo = 0;
    }

    C_Heap(int size, int type){
      this->heap.resize(size, -1);
      this->tipo = type;
    }

    ~C_Heap(){}

    int getMax(void){
      return this->heap[0];
    }

    int delMax(void){
      bool flag = true;
      int cont = 0;
      int temp;

      while(flag){
        if(this->heap[cont] == -1){
          flag = false;
        }
        cont++;
      }

      temp = this->heap[0];
      this->heap[0] = this->heap[cont-2];
      this->heap[cont-2] = -1;
      percolateDown(0);
      return temp;
    }

    void insert(int dato){
      bool flag = true;
      int i = 0;
      while(flag){
        if(this->heap[i] == -1){
          flag = false;
          this->heap[i] = dato;
        }
        i++;
      }

      int tam = count();
      int n = tam/2 - 1;

      for(int i = n; i >= 0; i--){
        percolateDown(i);
      }
    }

    int capacity(void){
      return this->heap.size();
    }

    void resizeHeap(int new_size){
      this->heap.resize(new_size, -1);
    }

    int count(void){
      int cont = 0;
      for(int i = 0; i < this->heap.size(); i++){
        if(this->heap[i] != -1){
          cont++;
        }
      }
      return cont;
    }
};

#endif
