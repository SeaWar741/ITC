//Nodo para Queue
template<class T>
struct Node2{
    T data;
    Node2<T> *next;//pointer siguiente
    Node2(T data);//nodo constructor
    Node2(T data, Node2<T> *next);//Nodo constructor
};

template <class T>
Node2<T>::Node2(T data){
    this->data = data;
    next = NULL;
}

template <class T>
Node2<T>::Node2(T data, Node2<T> *next){
    this->data = data;
    this->next = next;
}
