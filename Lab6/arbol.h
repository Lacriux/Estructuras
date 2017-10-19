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
            nuevo_nodo->height = height(nuevo_nodo);
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
            nuevo_nodo->height = height(nuevo_nodo);
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

    int height(Node *aux){
      if(aux == NULL){
        return 0;
      }
      else{
        int lHeight = height(aux->left);
        int rHeight = height(aux->right);
        if(lHeight > rHeight){
          return lHeight + 1;
        }
        else{
          return rHeight + 1;
        }
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

    Node * insertAVL(Node * root, int dato){
      if(!root){
        root= new Node;
        if(!root){
          cout<<"Memoria no asignada, se la comieron los gatitos"<< endl;
          return NULL;
        }
        else{
          root->dato=dato;
          root-> height = 0;
          root ->left = root->right = NULL;
        }
      }
      else if(dato < root->dato){
        root->left=insertAVL(root->left, dato);
        if((heightNode(root->left)-heightNode(root->right))==2){
          if(dato<root->left->dato){
            root=rotateLeft(root);
          }
          else{
            root=doubleRotateLeft(root);
          }
        }
      }
      else if(dato > root->dato){
        root->right=insertAVL(root->right, dato);
        if((heightNode(root->left)-heightNode(root->right))==2){
          if(dato<root->right->dato){
            root=rotateRight(root);
          }
          else{
            root=doubleRotateRight(root);
          }
        }
      }
      root->height=max(heightNode(root->left),heightNode(root->right))+1;
      return root;
    }

    int max(int dato1, int dato2){
      if (dato1 < dato2){
        return dato2;
      }
      else{
        return dato1;
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
        nuevo_nodo->height = height(nuevo_nodo);
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

    int height(void){
      if(this->root == NULL){
        return 0;
      }
      else{
        int lHeight = height(this->root->left);
        int rHeight = height(this->root->right);
        if(lHeight > rHeight){
          return lHeight + 1;
        }
        else{
          return rHeight + 1;
        }
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

    int heightNode(Node* aux){
      if(aux){
        return aux->height;
      }
      else{
        return -1;
      }
    }

    Node* rotateLeft(Node* aux){
      Node* aux2 = aux->left;
      aux->left = aux2->right;
      aux2->right = aux;
      aux->height = height(aux);
      aux2->height = height(aux2);
      return aux2;
    }

    Node* rotateRight(Node* aux){
      Node* aux2 = aux->right;
      aux->right = aux2->left;
      aux2->left = aux;
      aux->height = height(aux);
      aux2->height = height(aux2);
      return aux2;
    }

    Node* doubleRotateLeft(Node* aux){
      aux->left = rotateRight(aux->left);
      return rotateLeft(aux);
    }

    Node* doubleRotateRight(Node* aux){
      aux->right = rotateLeft(aux->right);
      return rotateRight(aux);
    }

    void insertAVL(int dato){
      this->root = insertAVL(this->root, dato);
    }

    void imprimir(Node* root, int height, int profundidad)        {
      vector<int> vector;
      linea(root,profundidad, vector);
      cout << setw((height-profundidad)*2);
      bool lado = true;
      if (vector.size() > 1) {
          for (int i=0 ;i<vector.size();i++) {
              if (vector[i] != '_') {
                  if (lado){
                      cout << "/" << " ";
                  }
                  else{
                      cout << "\\" << " ";
                  }
              }
              else{
                  std::cout << "    " ;
              }
              lado = !lado;
          }
      cout << endl;
      cout << setw((height-profundidad)*1.9);
      }
      for (int i=0 ; i<vector.size();i++) {
          if (vector[i] != '_'){
            cout << vector[i];
              cout << "  ";
          }
          else{
              std::cout << "   " ;
          }
      }
      cout << endl;
    }

    void printTree(void){
      for (int i = 0 ; i < height(); i ++) {
        imprimir(this->root, height(), i);
      }

    }

    void linea(Node* root,int profundidad,vector<int>& numeros){
      if (profundidad == 0 && root != NULL) {
        numeros.push_back(root->dato);
        return;
      }
       if (root->left != NULL){
        linea(root->left, profundidad-1, numeros);
      }
       else if (profundidad-1 == 0){
        numeros.push_back('_');
      }
       if (root->right != NULL){
        linea(root->right, profundidad-1, numeros);
      }
      else if (profundidad-1 == 0){
        numeros.push_back('_');
      }
    }

};

#endif
