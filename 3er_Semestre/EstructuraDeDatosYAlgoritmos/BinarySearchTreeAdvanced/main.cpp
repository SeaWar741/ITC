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
    cout<<"-----------------------"<<endl;
    cout<<"5)visit"<<endl;
    cout<<"6)height"<<endl;
    cout<<"7)ancestors"<<endl;
    cout<<"8)what level am I"<<endl;
    cout<<"9)exit"<<endl;
    cout<<endl;
}

//funcion para llenar el arbol binario con datos iniciales
void initializer(BinarySearchTree<int> &tree){
    tree.insert(10);
    tree.insert(5);
    tree.insert(20);
    tree.insert(3);
    tree.insert(8);
    tree.insert(20);
    tree.insert(15);
    tree.insert(25);
    tree.insert(28);
}

int main(){
    BinarySearchTree<int> tree;
    initializer(tree);
	bool continues = true;
    int selection,value,selection2;
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
                cout<<endl<<"1) Preorder"<<endl;
                cout<<"2) Inorder"<<endl;
                cout<<"3) Postorder"<<endl;
                cout<<"4) Level by level"<<endl<<endl;
                cout<<endl<<"Ingresa una opcion de visita: >";cin>>selection2;
                tree.visit(selection2);
                break;
            case 6:
                cout<<"Altura del arbol: "<<tree.getHeight()<<endl;
                break;
            case 7:
                cout<<endl<<"Ingresar el valor a buscar sus ancestros: >";cin>>value;
                tree.ancestors(value);
                break;
            case 8:
                cout<<endl<<"Ingresar el valor a encontrar su nivel: >";cin>>value;
                cout<<"El nivel en el que esta "<<value<<": "<<tree.whatLevelAmI(value);
                break;
            case 9:
                continues = false;
                break;
            default:
                cout<<"------------------------------------"<<endl;
                cout<<endl<<"Valor invalido!"<<endl;
                cout<<"------------------------------------"<<endl;
                break;
        }
        if(continues){
           cout<<endl<<endl<<"------------------------------------"<<endl;
            tree.print();
            cout<<"------------------------------------"<<endl<<endl; 
        }
    }
    cout<<"-----------------------"<<endl;
    cout<<endl<<endl<<"GRACIAS POR USAR BST TESTER!"<<endl<<endl;
    return 0;
}
