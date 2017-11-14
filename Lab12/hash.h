#include<iostream>
#include<vector>

using namespace std;

struct Node{
  int key;
  Node* next;
};


#ifndef CLASEHASH
#define CLASEHASH

class Hash{
  protected:
    vector<Node*> hash;
  public:
    Hash(){
      hash.resize(83, NULL);
    }
    ~Hash(){
      for(int i = 0; i< hash.size(); i++){
        Node*aux = hash[i];
        while(aux){
          if(aux->next){
            aux = aux->next;
          }
          else{
            delete aux;
            aux = NULL;
          }
        }
        hash[i] = NULL;
      }
    }
    void hashInsert(int key){
      Node*aux = new Node();
      Node*aux2;
      aux->key = key;
      aux->next = NULL;
      int indice = 0;
      for(int i = 1; i <= 100000000; i *= 10){
        indice += (key/i)%10;
      }
      aux2 = hash[indice];
      if(!hash[indice]){
        aux->key = key;
        aux->next = NULL;
        hash[indice] = aux;
      }
      else{
        while(aux2->next){
          aux2 = aux2->next;
        }
        aux2->next = aux;
      }
    }
    bool hashSearch(int key){
      int indice = 0;
      bool is = false;
      for(int i = 1; i <= 100000000; i *= 10){
        indice += (key/i)%10;
      }
      if(hash[indice]!=NULL){
        Node*aux=hash[indice];
        while(aux->next){
          if(aux->key = key){
            is = true;
          }
          aux = aux->next;
        }
        if(aux->key = key){
          is = true;
        }
      }
      return is;
    }
    void hashDelete(int key){
      int indice = 0;
      for(int i = 1; i <= 100000000; i *= 10){
        indice += (key/i)%10;
      }
      if(hash[indice]){
        Node*aux=hash[indice];
        Node*aux2;
        if(aux->next){
          aux2=aux->next;
          if(aux->key=key){
            aux->next = aux2->next;
            delete aux2;
          }
          else{
            while(aux->next){
              if(aux2->key = key){
                aux->next = aux2->next;
                delete aux2;
              }
              aux = aux->next;
              aux2 = aux->next;
            }
          }
        }
        else{
          if(aux->key=key){
            hash[indice] = NULL;
            delete aux;

          }
        }

      }
    }

};
#endif
