#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "NodeD.h"
#include "Queue.h"
#include "IPRegistry.h"

using namespace std;

//Clase doubly linked list
template<class T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;
    void mergeSort(int ini, int fin);
    void merge(int ini, int mid, int fin);
public:
    DoublyLinkedList();
    void operator=(initializer_list<T> list);
    void operator=(DoublyLinkedList<T> list);
    T& operator[](int index);
    void addFirst(T data);
    void addLast(T data);
    bool deleteData(T data); 
    bool deleteAt(int index); 
    T getData(int index); 
    void updateAt(int index, T newData);
    void updateData(T data, T newData);
    void insertAt(int index, T newData);
    void duplicate();
    void removeDuplicates();
    int findData(T data);
    void sort();
    void clear();
    void print();
    void printReverse();
    bool isEmpty();
    int getSize();
    bool existsIn(IPRegistry registry);
    int getIndex(IPRegistry registry);
    string stringify();
    void printTop();
    /*
    bool existsErrorIn(Error er);
    int getErrorIndex(Error er);
    */
};

//constructor default
template<class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

//sorecarga para corchetes
//acceder al dato por indice
//O(n)
template<class T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {//va partiendo
            NodeD<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

//sobrecarga igual
//lista o vector a dlist
//o(n)
template<class T>
void DoublyLinkedList<T>::operator=(initializer_list<T> list) {
    if (isEmpty()) {
        for (T i : list) {
            addLast(i);
        }
    } else {
        throw runtime_error("Error: DoublyLinkedList no esta vacia");   
    }
}

//sobrecarga igual
//iguala una lista a otra
//o(n)
template<class T>
void DoublyLinkedList<T>::operator=(DoublyLinkedList<T> list) {
    clear();
    for (int i=1; i<=list.size; i++) {
        addLast(list[i]);
    }

}

//addFirst
//hace add a un elemento en el inicio de la lista
//O(1)
template<class T>
void DoublyLinkedList<T>::addFirst(T data) {
    if (!isEmpty()) {
        head->prev = new NodeD<T>(data, head, NULL); 
        head = head->prev;
    } else {
        head = new NodeD<T>(data);
        tail = head;
    }
    size++;
}

//addLast
//hace add a un elemento en el final de la lista
//O(1)
template<class T>
void DoublyLinkedList<T>::addLast(T data) {
    if (!isEmpty()) {
        tail->next = new NodeD<T>(data,NULL, tail);
        tail = tail->next;
    } else {
        tail = new NodeD<T>(data);
        head = tail;
    }
    size++;
}

//deleteData
//hace delete a un elemento a partir del dato
//O(n)
template<class T>
bool DoublyLinkedList<T>::deleteData(T data) {
    if (!isEmpty()) {
        if (head->data == data) {
            NodeD<T>* aux = head;
            head = aux->next;
            head->prev = NULL;
            delete aux; // Libera espacio de memoria
            size--;
            if (head == NULL) {
                tail = NULL;
            }
            return true;
        } else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                while (aux != NULL) {
                    if (aux->data == data) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                }
            }
        }
    }
    return false;
}

//deleteAt
//borra por indice
//O(n)
template<class T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            NodeD<T>* aux = head;
            head = aux->next;
            if (head == NULL) {
                tail = NULL;
            } else {
                head->prev = NULL;
            }
            delete aux;
            size--;
            return true;
        } else {
            if (head->next != NULL) {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while (aux != NULL) {
                    if (i == index) {
                        prev->next = aux->next;
                        if (aux->next != NULL) {
                            aux->next->prev = prev;
                        } else {
                            tail = prev;
                        }
                        delete aux;
                        size--;
                        return true;
                    } else {
                        prev = aux;
                        aux = aux->next;
                    }
                    i++;
                }
            }
        }
    }
    return false;
}


//getData
//obtiene data por indice
//O(n)
template<class T>
T DoublyLinkedList<T>::getData(int index) {
    if (index >= 1 && index <= size) {
        if (index <= size / 2) {
            NodeD<T>* aux = head;
            int i = 1; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size; // The list starts with 1
            while (aux != NULL) {
                if (i == index) {
                    return aux->data;
                }
                aux = aux->prev;
                i--;
            }
            
        }
    }
    throw out_of_range("Invalid position");
}

//updateAt
//actualiza por indice
//O(n)
template<class T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index <= size/2) {
            NodeD<T>* aux = head;
            int i = 1;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->next;
                i++;
            }
        } else {
            NodeD<T>* aux = tail;
            int i = size;
            while(aux != NULL) {
                if (i == index) {
                    aux->data = newData;
                    return;
                }
                aux = aux->prev;
                i--;
            }
        }
    }
    throw out_of_range("Invalid position");
}

//updateData
//actualiza por dato
//O(n)
template<class T>
void DoublyLinkedList<T>::updateData(T data, T newData) {
    NodeD<T>* aux = head;
    while(aux != NULL) {
        if (aux->data == data) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
    throw out_of_range("Data not found");
}

//insertAt
//actualiza por indice
//O(n)
template<class T>
void DoublyLinkedList<T>::insertAt(int index, T newData) {
    if (index >= 1 && index <= size) {
        if (index == 1) {
            head->prev = new NodeD<T>(newData,head,NULL);
            head = head->prev;
            size++;
            return;
        } else {
            if (index == size) {
                tail->next = new NodeD<T>(newData, NULL, tail);
                tail = tail->next;
                size++;
                return;
            } else {
                NodeD<T>* aux = head->next;
                NodeD<T>* prev = head;
                int i = 2;
                while(aux->next != NULL) {
                    if (i == index) {
                        prev->next = new NodeD<T>(newData,aux,prev);
                        size++;
                        return;
                    }
                    prev = aux;
                    aux = aux->next;
                    i++;
                }
            }
        }
    }
    throw out_of_range("Invalid position");
}

//merge
//funcion helper para sort
//O(n)
template<class T>
void DoublyLinkedList<T>::merge(int ini, int mid, int fin) {
    Queue<T> listL;
    Queue<T> listR;
    int pos,f1,f2,i,j;
    pos = ini;
    f1 = mid - ini + 1;
    f2 = fin - mid;   
    for (i=1;i<=f1;i++) {
        listL.enqueue(getData(ini+i-1));
    }
    for (j=1;j<=f2;j++) {
        listR.enqueue(getData(mid+1+j-1));
    }
    i = 1;
    j = 1;
    while (i<=f1 && j<=f2) {
        if (listL.front()<=listR.front()) {
            updateAt(pos,listL.dequeue());
            i++;
        } else {
            updateAt(pos,listR.dequeue());
            j++;
        }
        pos++;
    }
    while (i<=f1) {
        updateAt(pos,listL.dequeue());
        i++;
        pos++;
    }
    while (j<=f2) {
        updateAt(pos,listR.dequeue());
        j++;
        pos++;
    }
}

//mergeSort
//funcion helper para sort
//O(n log n)
template<class T>
void DoublyLinkedList<T>::mergeSort(int ini, int fin) {
    if (ini < fin) {
        int mid = (ini + fin) / 2;
        mergeSort(ini,mid);
        mergeSort(mid+1,fin);

        merge(ini,mid,fin);
    }
}

//sort
//funcion para hacer sort a la lista
//O(n log n)
template<class T>
void DoublyLinkedList<T>::sort() {
    mergeSort(1,size);
}

//findData
//funcion para buscar datos en la lsita
//O(n)
template<class T>
int DoublyLinkedList<T>::findData(T data) {
    int posI = 1;
    int posF = size;
    int posM = (posI + posF) / 2;
    bool found = false;
    sort();
    while (posI <= posF && !found) {
        if (data < getData(posM)) {
            posF = posM - 1;
            
        } else {
            if (data > getData(posM)) {
                posI = posM + 1;
                
            } else {
                if (data == getData(posM)) {
                    found = true;
                }
            }
        }
        posM = (posI + posF) / 2;
        
    }
    if (found) {
        return posM;
    } else {
        //throw runtime_error("Not found in list");
        
        return -1;
    }
}


//findData
//funcion para buscar datos en la lsita
//O(n)
template<class T>
void DoublyLinkedList<T>::duplicate() {
    // NodeD<T>* aux = head;
    // while (aux != NULL) {
    //     aux->next = new NodeD<T>(aux->data,aux->next);
    //     size++;
    //     aux = aux->next->next;
    // }
}

template<class T>
void DoublyLinkedList<T>::removeDuplicates() {
    // NodeD<T>* aux = head;
    // DoublyLinkedList<T> list = *this;
    // clear();
    // for (int i=1; i<list.size; i++) {
    //     if (!findData(aux->data)) {
    //         addLast(aux->data);
    //     }
    // }
}


//print
//funcion para imprimir lista
//O(n)
template<class T>
void DoublyLinkedList<T>::print() {
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        cout << aux->data<<endl;
        aux = aux->next;
    }
}

//printTop
//funcion para imprimir top 5
template<class T>
void DoublyLinkedList<T>::printTop() {
    NodeD<T>* aux = head;
    for (int i=1; i<=5; i++) {
        cout << aux->data<<endl;
        aux = aux->next;
    }
}


//stringify
//funcion para convertir lista en string json
//O(n)
template<class T>
string DoublyLinkedList<T>::stringify() {
    string output ="";
    output+=string("{")+'\u0022'+"IP-Registry"+'\u0022'+":[";
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        output+= aux->data.stringify();
        if(i<size){
            output+=",";
        }
        aux = aux->next;
    }
    output+="]}\n";
    return output;
}

//existsIn
//funcion para verificar si existe en la lista
//O(n)
template <class T>
bool DoublyLinkedList<T>::existsIn(IPRegistry registry){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data == registry){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

//getIndex
//funcion para obtener indice
//O(n)
template <class T>
int DoublyLinkedList<T>::getIndex(IPRegistry registry){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data.ip == registry.ip){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}

/*
template <class T>
bool DoublyLinkedList<T>::existsErrorIn(Error er){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data == er){
            return true;
        }
        aux = aux->next;
    }
    return false;
}

template <class T>
int DoublyLinkedList<T>::getErrorIndex(Error er){
    NodeD<T>* aux = head;
    for (int i=1; i<=size; i++) {
        if(aux->data.errorType == er.errorType){
            return i;
        }
        aux = aux->next;
    }
    return -1;
}

*/

//printReverse
//funcion para imprimir invertido
//O(n)
template<class T>
void DoublyLinkedList<T>::printReverse() {
    NodeD<T>* aux = tail;
    for (int i=size; i>=1; i--) {
        cout << aux->data << " ";
        aux = aux->prev;
    }
    cout << endl;
}

//clear
//funcion para borrar lista
//O(n)
template<class T>
void DoublyLinkedList<T>::clear() {
    int i = 1;
    while (i<=size) {
        NodeD<T>* aux = head;
        head = aux->next;
        delete aux;
        i++;
    }
    size = 0;
    tail = NULL;
}

//clear
//funcion para verificar si esta vacia
//O(1)
template<class T>
bool DoublyLinkedList<T>::isEmpty() {
    return size == 0;
}

//getSize
//funcion para obtener size
//O(1)
template<class T>
int DoublyLinkedList<T>::getSize() {
    return size;
}
#endif