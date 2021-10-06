//Actividad 3.1 Implementación de "Tries"
//Juan Carlos Garfias Tovar, A01652138
//Abraham Cepeda Oseguera, A00827666
#include <iostream>
using namespace std;

#define CHAR_SIZE 128

//clase trie
class Trie{
    public:
        bool isLeaf;
        Trie* character[CHAR_SIZE];

        Trie(){
            this->isLeaf = false;
            for (int i = 0; i < CHAR_SIZE; i++){
                this->character[i] = nullptr;
            }
            
        }

        void insert(string);
        bool deletion(Trie*&, string);
        bool search(string, bool);
        bool haveChildren(Trie const*);
};

//funcion insert
//input: string
//output: n/a
//inserta en el trie la palabra
//o(n)
void Trie::insert(string key){
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++){
        /* code */
        if(curr->character[key[i]] == nullptr){
            //crear nuevo camino si no existe el camino
            curr->character[key[i]] = new Trie();
        }

        //iterar al nodo siguiente
        curr = curr -> character[key[i]];
    }
    //convertir el nodo en hoja
    curr -> isLeaf = true;
    
}

//funcion search
//input: string, bool (opcional para log/recorrido)
//output: booleano 
//busca la palabra en el trie, se muestra el recorrido (opcional)
//o(n)
bool Trie::search(string key, bool log = false){
    //checa si esta vacio el trie
    if (this == nullptr) {
        return false;
    }
 
    Trie* curr = this;
    for (int i = 0; i < key.length(); i++){
        // itera sobre el siguiente nodo
        curr = curr->character[key[i]];
        
        //si se quiere mostrar el recorrido
        if(log == true){
            cout<<key[i]<<"-> ";
        }
 
        //si se llega al final de la rama
        if (curr == nullptr) {
            return false;
        }
    }
 
    // checa si es hoja y si se llego al final del string
    return curr->isLeaf;
}


//funcion haveChildren
//input: current node
//output:bool
//checa si existe o no hijo para el nodo actual
//o(n)
bool Trie::haveChildren(Trie const* curr){
    for (int i = 0; i < CHAR_SIZE; i++){
        /* code */
        if(curr->character[i]){
            return true; //se ecnontro un hijo
        }
    }
    return false;
}

//funcion deletion
//input:current node, string
//output:bool si se borra o no
//borra del trie el string
//o(n)
bool Trie::deletion(Trie*& curr, string key){
    // Checa si el trie esta vacio
    if (curr == nullptr) {
        return false;
    }
 
    // verifica que no se llege al final del key
    if (key.length()){
        //checa el nodo correspondiente al siguiente caracter en la key
        //y si regrsa verdadero se borra el nodo actual
        //esto si no es una hoja
 
        if (curr != nullptr &&
            curr->character[key[0]] != nullptr &&
            deletion(curr->character[key[0]], key.substr(1)) &&
            curr->isLeaf == false)
        {
            if (!haveChildren(curr))
            {
                delete curr;
                curr = nullptr;
                return true;
            }
            else {
                return false;
            }
        }
    }
 
    //Checa si se llego al final del key
    if (key.length() == 0 && curr->isLeaf)
    {
        //si el nodo actual es una hoja y no tiene hijos
        if (!haveChildren(curr))
        {
            //borra el nodo actual
            delete curr;
            curr = nullptr;
 
            //borra los nodos padre no hoja
            return true;
        }
 
        // si el nodo actual es hoja y tiene hijos
        else {
            // se marca como no hoja y no se borra
            curr->isLeaf = false;
 
            // o se borran los nodos padres
            return false;
        }
    }
 
    return false;
}

//--------------------------------------------------------------------

int main(){
    
    Trie* head = new Trie();
    int n,m;

    cout<<endl<<"----------------------------------------------------------------------------------------\n";
    cout<<"Programa realizado por Juan Carlos Garfias Tovar y Abraham Cepeda Oseguera\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Programacion Trie\n";
    cout<<"----------------------------------------------------------------------------------------\n";

    cout<<"Ingresa el numero de palabras >";cin>>n;

    string words[n];

    //se almacenan las palabras
    for(int i = 0;i<n;i++){
        cout<<">";cin>>words[i];
    }

    //insertar en el trie
    for(int i = 0; i < sizeof(words)/sizeof(words[0]);i++){
        head->insert(words[i]);
    }

    cout<<"----------------------------------------------------------------------------------------\n";
    cout<<"Ingresar numero de palabras a buscar >";cin>>m;

    //se almacenan las palabras
    string searchWords[m];
    for(int i = 0;i<m;i++){
        cout<<">";cin>>searchWords[i];
    }
    
    //se buscan las palabras
    for(int i = 0;i<m;i++){
        cout<<head->search(searchWords[i],true)<<endl;
    }
    
    return 0;
}
