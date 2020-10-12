
//struct node
//contiene un next y un data
template<class T>
struct Node{
    T data;
    Node<T> *next;
    Node(T data);
    Node(T data,Node<T> *next);
};

//constructor con data
//le asigna el dato y le pone null como apuntador a next
template <class T>
Node<T>::Node(T data){
    this->data = data;
    next = NULL;
}

//constructor con apuntador y data
//asigna data y next como apuntador
template <class T>
Node<T>::Node(T data, Node<T> *next){
    this->data = data;
    this->next = next;
}