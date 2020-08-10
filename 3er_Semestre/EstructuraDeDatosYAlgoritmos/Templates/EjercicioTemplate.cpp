//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "Lista.h"

using namespace std;

void selectionMenu(){
    cout<<"Selecciona el tipo de dato a almacenar: "<<endl;
    cout<<"1) int"<<endl;
    cout<<"2) double"<<endl;
    cout<<"3) string"<<endl;
    cout<<"4) char"<<endl;
    cout<<"5) bool"<<endl;
}

template <class T>
void menu(Lista<T> arry){
    
    T insertion;
    int selection,index;
    bool continues = true;
    while(continues){
        cout<<"1) Insert"<<endl;
        cout<<"2) Erase"<<endl;
        cout<<"3) Get Data"<<endl;
        cout<<"4} Get Size"<<endl;
        cout<<"5) Print"<<endl;
        cout<<"6) Exit"<<endl<<endl;
        cout<<"Ingresa tu seleccion: ";cin>>selection;cout<<endl;
        switch (selection){
            case 1:
                cout<<"Ingresar elemento: ";cin>>insertion;cout<<endl;
                try{
                    arry.insert(insertion);
                }catch(runtime_error& e){
                    cout<<e.what()<<endl;
                }
                break;
            case 2:
                try{
                    cout<<arry.erase()<<endl;
                }catch(runtime_error& e){
                    cout<<e.what()<<endl;
                }
                break;
            case 3:
                cout<<"Ingresar indice: ";cin>>index;cout<<endl;
                try{
                    cout<<arry.getData(index)<<endl;
                }catch(runtime_error& e){
                    cout<<e.what()<<endl;
                }
                break;
            case 4:
                cout<<arry.getSize()<<endl;
                break;
            case 5:
                arry.print();
                break;
            case 6:
                continues = false;
                break;
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        }
        cout<<endl;
    }
    
}


int main(){
    
    int selection;
    Lista<int> lista1; 
    Lista<double> lista2; 
    Lista<string> lista3; 
    Lista<char> lista4; 
    Lista<bool> lista5;

    selectionMenu();

    cout<<"Ingresar seleccion: ";cin>>selection;cout<<endl;
    try{
         switch (selection){
            case 1:
                menu(lista1);
                break;
            case 2:
                menu(lista2);
                break;
            case 3:
                menu(lista3);
                break;
            case 4:
                menu(lista4);
                break;
            case 5:
                menu(lista5);
                break;
            
            default:
                cout<<"Opcion no valida"<<endl;
                break;
        } 
    }
    catch(const std::exception& e){
        cout<<"Error de ejecución, verificar inputs y volver a iniciar el programa"<<endl;
    }
}
