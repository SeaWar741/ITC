//Juan Carlos Garfias Tovar, A01652138
template<class T>
struct Node{
    T data;//contiene un data y un apuntador como indice al siguiente nodo, conectandolos entre si
    Node<T> *next;
    Node(T data);
    Node(T data,Node<T> *next);
};

//constructor for only data
template <class T>
Node<T>::Node(T data){
    this->data = data;
    next = NULL;
}

//constructor data and next 
template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}