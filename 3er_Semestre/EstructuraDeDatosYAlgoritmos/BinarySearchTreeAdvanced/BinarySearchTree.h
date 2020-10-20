//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "Node.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

//clase Binary search tree
template<class T>
class BinarySearchTree{
private:
	Node<T> *root; //nodo raiz
	//int children;
	//int height;
public:
	BinarySearchTree();

	bool find(T data); 
	bool isEmpty(){return root == NULL;};

	void insert(T data);
	void deletes(T data);

	void preOrder(Node<T> *aux);
	void inOrder(Node<T> *aux);
	void postOrder(Node<T>* aux);
	void levelByLevel();


	int height(Node<T>* node);
	void ancestors(T data);

	int countChildren(Node<T>* aux);
	void printTree(Node<T> *node, int level);
	void print();
};

//Constructor
template<class T>
BinarySearchTree<T>::BinarySearchTree(){
	root = NULL; //inicializa el nodo como nulo
	//children = 0;
	//height = 0;
}

//countChildren
//Funcion para contar el numero de hijos del arbol
//itera por la rama izquierda y derecha
template<class T>
int BinarySearchTree<T>::countChildren(Node<T>* aux){
	int cont = 0;//contador para los hijos
	aux -> left != NULL ? cont ++:cont = cont;//suma si encuentra a la izquierda
	aux -> right != NULL ? cont ++:cont = cont;//suma si encuentra a la derecha
	return cont;//regresa total
}

//find
//Funcion para verificar si el dato se encuentra en el binary tree
//itera en el arbol y regresa un valor booleano
template<class T>
bool BinarySearchTree<T>::find(T data){
	Node<T> *aux = root;
	bool found = false;
	while (!found && aux!=NULL){
		if(data== aux->data){
			found = true;
		}else{
			data<aux->data?aux=aux->left:aux=aux->right;
		}
	}
	return found;
	
}

//insert
//funcion para insertar en el arbol el valor dado
//hace add al valor al checar en que rama debe de ir y de que nodo
//debe de ser hijo
template<class T>
void BinarySearchTree<T>::insert(T data){
    if(!isEmpty()){
        Node<T> *aux = root;
        while(aux != NULL){
            if(aux->data > data){
                if(aux->left == NULL){
                    aux->left = new Node<T>(data);
                    return;
                } else{
                    aux = aux->left;
                }
            } else{
                if(aux->right == NULL){
                    aux->right = new Node<T>(data);
                    return;
                } else{
                    aux = aux->right;
                }
            }
        }
    } else{
        root = new Node<T>(data);
    }
}


//delete
//Toma un dato de entrada y lo elimina del nodo
//checa que este presente y que no este vacia
// una vez realizado esto mueve los nodos dependiendo del valor
//convirtiendo algun nodo en padre de otros
template<class T>
void BinarySearchTree<T>::deletes(T data){
	if(isEmpty() ){
		throw runtime_error("Binary tree is empty\n");
	}
	Node<T> *father = root;
	Node<T> *aux = father;
	bool found = false;
	while (!found && aux!=NULL){
		if(data== aux->data){
			found = true;
		}else{
			father = aux;
			data < aux->data?aux = aux->left : aux = aux->right;
		}
	}
	if(found){
		switch (countChildren(aux)){
			case 0:
				if(aux == root){
					delete aux;
					root = NULL;
				}
				else{
					cout<<father->data<<endl;
					data< father -> data ? father -> left = NULL: father->right = NULL;
					delete aux;
				}
				break;
			case 1: //un hijo
				if(aux == NULL){
					root ->left != NULL ? root = root -> left : root = root ->right;
				}
				else{
					if(data<father->data){
						aux->left != NULL ? father -> left = aux->left : father->left = aux->right;
					}else{
						aux->left != NULL ? father -> right = aux->left : father->right = aux->right;
					}
				}
				delete aux;
				break;
			case 2://dos hijos
				Node<T> *father = aux;
				Node<T> *max = aux->left;
				if(max->right ==NULL){
					aux->data = max->data;
					father->left = max ->left;
					delete max;
				}
				else{
					bool found = false;
					while (!found){
						if (max->right==NULL){
							found = true;
						}else{
							father = max;
							max = max ->right;
						}
					}
					aux -> data = max ->data;
					father -> right = max->left;
					delete max;
				}
				break;
		}
	}
	else{
		cout<<"EL VALOR NO ESTA EN EL ARBOL!"<<endl;
	}
}

//printTree
//Funcion para imprimir el arbol
//lo hace de manera horizontal, toma el nodo y el nivel
template<class T>
void BinarySearchTree<T>::printTree(Node<T> *node, int level){
    if(node != NULL){
        printTree(node->right, level + 1);
        for(int i = 0; i < level; i ++){
            cout << " ";
        }
        cout << node->data << "\n";
        printTree(node->left, level + 1);
    }
}

//print
//Funcion para imprimir el arbol de manera completa
//lo hace de manera horizontal
template<class T>
void BinarySearchTree<T>::print(){
	if(!isEmpty()){
		int level = 0;
		cout << endl;
		printTree(root,level);
		cout<<endl;
	}
	else{
		cout<<endl<<"Tree is empty"<<endl<<endl;
	}
}

//Avanzado-----------------------------------------

template<class T>
void BinarySearchTree<T>::preOrder(Node<T> *aux){
	if(aux!=NULL){
		cout<<aux->data<<" ";
		preOrder(aux->left);
		preOrder(aux->right);
	}
}

template <class T>
void BinarySearchTree<T>::inOrder(Node<T>* aux){
	if(aux!=NULL){
		inOrder(aux->left);
		cout<<aux->data<<" ";
		inOrder(aux->right);
	}
}

template <class T>
void BinarySearchTree<T>::postOrder(Node<T>* aux){
	if(aux!=NULL){
		postOrder(aux->left);
		postOrder(aux->right);
		cout<<aux->data<<" ";
	}
}

template <class T>
void BinarySearchTree<T>::levelByLevel(){
	if(!isEmpty()){
		Queue<Node<T>*> queue;
		queue.enqueue(root);
		while (!queue.isEmpty()){
			Node<T> *aux = queue.dequeue();
			cout<<aux->data<<" ";
			if(aux->left !=NULL){
				queue.enqueue(aux->left);
			}
			if(aux->right !=NULL){
				queue.enqueue(aux->right);
			}
		}
		
	}
}

template <class T>
int BinarySearchTree<T>::height(Node<T> *node){
	int h = 0;
	int l,r;
	if(node != NULL){
		h++;
		l = height(node->left);
		r = height(node->right);
		(l>r)? h+=l:h+=r;
	}
	return h;

}

template <class T>
void BinarySearchTree<T>::ancestors(T data){
	if(!isEmpty()){
		Node<T>  *aux = root;
		Stack<T> stack;
		if(aux->data !=data){
			bool notFound = false;
			while (aux->data != data && !notFound){
				stack.push(aux->data);
				if(data<-aux->data){
					if(aux->left == NULL){
						notFound = true;
					}else{
						aux = aux->left;
					}
				}else{
					if(aux->right == NULL){
						notFound = true;
					}else{
						aux = aux->right;
					}
				}
			}
			if(!notFound){
				while (!stack.isEmpty()){
					try{
						T data = stack.pop();
						cout<<data<<" ";
					}catch(runtime_error& e){
						cout<<e.what()<<endl;
					}
				}
				
			}else{
				cout<<"No tiene ancestros"<<endl;
			}
		}
	}else{
		cout<<"EL ARBOL ESTA VACIO"<<endl;
	}
}