#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

#ifndef CLASEARBOL
#define CLASEARBOL

struct Node{
  int dato;
	Node *left;
	Node *right;
  int height;
};

class C_BinTree{
  protected:
    Node *root;
  private:
    void insertBTS(int dato, Node *aux){
      if(aux){
        if (dato > aux->dato){
          if(aux->right){
            aux = aux->right;
            insertBTS(dato, aux);
          }
          else{
            Node *nuevo_nodo = new Node();
            nuevo_nodo->dato = dato;
            nuevo_nodo->left = NULL;
            nuevo_nodo->right = NULL;
            aux->right = nuevo_nodo;
          }
        }
        else{
          if (aux->left){
            aux = aux->left;
            insertBTS(dato, aux);
          }
          else{
            Node *nuevo_nodo = new Node();
            nuevo_nodo->dato = dato;
            nuevo_nodo->left = NULL;
            nuevo_nodo->right = NULL;
            aux->left = nuevo_nodo;
          }
        }
      }
    }

    void preOrder(Node *aux){
      if (aux){
        cout << aux->dato << endl;
      }
      if(aux->left){
        preOrder(aux->left);
      }
      if(aux->right){
        preOrder(aux->right);
      }
    }

    void inOrder(Node *aux){
      if(aux->left){
        inOrder(aux->left);
      }
      if(aux){
        cout << aux->dato << endl;
      }
      if(aux->right){
        inOrder(aux->right);
      }

    }

    void postOrder(Node *aux){
      if(aux->left){
        postOrder(aux->left);
      }
      if(aux->right){
        postOrder(aux->right);
      }
      if (aux){
        cout << aux->dato << endl;
      }
    }

    bool BuscarElemento(int dato, Node* aux){
      if(aux->dato == dato){
        return true;
      }
      else{
        bool esta = false;
        if(aux->left){
        esta = BuscarElemento(dato, aux->left);
        }
        if(esta){
          return esta;
        }
        else{
          if(aux->right){
          esta = BuscarElemento(dato, aux->right);
          }
          return esta;
        }
      }
    }

    int min(Node* aux){
      if(aux){
        if(aux->left){
          return min(aux->left);
        }
        else{
          return aux->dato;
        }
      }
    }

    int max(Node* aux){
      if(aux){
        if(aux->right){
          return max(aux->right);
        }
        else{
          return aux->dato;
        }
      }
    }

    void Destructor(Node* aux){
      if(aux->left){
        Destructor(aux->left);
      }
      if(aux->right){
        Destructor(aux->right);
      }
      delete aux;
    }

    int max(int dato1, int dato2){
      if (dato1 < dato2){
        return dato2;
      }
      else{
        return dato1;
      }
    }

    void borrarHojas(Node* aux, Node* aux2){
      if(!aux2->left && !aux2->right){
        if(aux2 = aux->left){
          aux->left = NULL;
          delete aux2;
        }
        else{
          aux->right = NULL;
          delete aux2;
        }
      }
      else{
        aux = aux2;
        borrarHojas(aux, aux->left);
        borrarHojas(aux, aux->right);
      }
    }

  public:
    C_BinTree(void){
      this->root = NULL;
    }

    ~C_BinTree(void){
      cout << "Destructor del arbol" << endl;
      Destructor(this->root);
    }

    void insertBTS(int dato){

      Node *nuevo_nodo = new Node();
      Node *aux = this->root;
      nuevo_nodo->dato = dato;
      nuevo_nodo->left = NULL;
      nuevo_nodo->right = NULL;
      if(this->root){
        insertBTS(dato, aux);
      }
      else{
        this->root = nuevo_nodo;
      }
    }

    void preOrder(void){
      if(this->root){
        preOrder(root);
      }
    }

    void inOrder(void){
      if(this->root){
        inOrder(root);
      }
    }

    void postOrder(void){
      if(this->root){
        postOrder(root);
      }
    }

    bool BuscarElemento(int dato){
      if(this->root->dato == dato){
        return true;
      }
      else{
        bool esta = false;
        if (this->root->left){
         esta = BuscarElemento(dato, this->root->left);
       }
       if(esta){
         return esta;
       }
       else{
         if(this->root->right){
           esta = BuscarElemento(dato, this->root->right);
         }
         return esta;
       }
     }
    }

    int min(void){
      return min(this->root);
    }

    int max(void){
      return max(this->root);
    }

    void borrarHojas(void){
      Node* aux = this->root->right;
      Node* aux2 = this->root->left;
      borrarHojas(this->root, aux);
      borrarHojas(this->root, aux2);
    }

};

#endif
