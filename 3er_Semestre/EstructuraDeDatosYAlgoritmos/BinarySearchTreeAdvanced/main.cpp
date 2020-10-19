//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

//funcion para desplegar el menu
void menu(){
    cout<<endl;
    cout<<"1)Insert"<<endl;
    cout<<"2)delete"<<endl;
    cout<<"3)find"<<endl;
    cout<<"4)print"<<endl;
    cout<<"5)exit"<<endl;
    cout<<endl;
}

int main(){
    BinarySearchTree<int> tree;
	bool continues = true;
    int selection,value;
    bool found;
    cout<<endl<<"Bienvenido a BST tester!"<<endl;
    while (continues){//mientras continues sea verdadero
        menu();
        cout<<endl<<"Ingresa una opcion del menu: >";cin>>selection;
        switch (selection){//switch basado en la seleccion del usuario
            case 1:
                cout<<endl<<"Ingresa el valor a insertar: >";cin>>value;
                tree.insert(value);
                break;
            case 2:
                cout<<endl<<"Ingresar el valor a borrar: >";cin>>value;
                tree.deletes(value);
                break;
            case 3:
                cout<<endl<<"Ingresar el valor a buscar: >";cin>>value;
                found = tree.find(value);
                if(found){
                    cout<<endl<<"El valor se encuentra en el arbol!"<<endl;
                }else{
                    cout<<endl<<"El valor no esta en el arbol"<<endl;
                }
                break;
            case 4:
                tree.print();
                break;
            case 5:
                continues = false;
                break;
            default:
                cout<<"------------------------------------"<<endl;
                cout<<endl<<"Valor invalido!"<<endl;
                cout<<"------------------------------------"<<endl;
                break;
        }
        cout<<endl<<endl<<"------------------------------------"<<endl;
        tree.print();
        cout<<"------------------------------------"<<endl<<endl;
    }
    cout<<endl<<endl<<"GRACIAS POR USAR BST TESTER!"<<endl<<endl;
    return 0;
}
