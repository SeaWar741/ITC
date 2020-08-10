//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include "Lista.h"

using namespace std;

//Funcion la cual imprime el menu de seleccion de tipo de dato
void selectionMenu(){
    cout<<"Selecciona el tipo de dato a almacenar: "<<endl;
    cout<<"1) int"<<endl;
    cout<<"2) double"<<endl;
    cout<<"3) string"<<endl;
    cout<<"4) char"<<endl;
    cout<<"5) bool"<<endl;
}


//Se llama a template para establecer la variable T
//Esta funcion se encarga del funcionamiento general del programa
template <class T>
void menu(Lista<T> arry){
    
    T insertion;//variable para insertar datos
    int selection,index;//variable para los indices
    bool continues = true;//variable para cerrar programa
    while(continues){ //Mientras que no se seleccione salir, el programa continuara en loop
        cout<<"1) Insert"<<endl;
        cout<<"2) Erase"<<endl;
        cout<<"3) Get Data"<<endl;
        cout<<"4} Get Size"<<endl;
        cout<<"5) Print"<<endl;
        cout<<"6) Exit"<<endl<<endl;
        cout<<"Ingresa tu seleccion: ";cin>>selection;cout<<endl;
        switch (selection){ //se hace un switch a partir de la seleccion de usuario
            case 1:
                try{ //se hace un try catch para insertar datos
                    cout<<"Ingresar elemento: ";cin>>insertion;cout<<endl;
                    arry.insert(insertion);
                }catch(runtime_error& e){
                    cout<<e.what()<<endl; //se imprime el error dado
                }
                break;
            case 2:
                try{
                    cout<<arry.erase()<<endl; //se hace try catch
                }catch(runtime_error& e){
                    cout<<e.what()<<endl; //se muestra error en caso de fallo
                }
                break;
            case 3:
                try{//try catch para el indice a obtener
                    cout<<"Ingresar indice: ";cin>>index;cout<<endl;
                    cout<<arry.getData(index)<<endl;
                }catch(runtime_error& e){
                    cout<<e.what()<<endl;
                }
                break;
            case 4:
                cout<<arry.getSize()<<endl; //se imprime el tamaño
                break;
            case 5:
                arry.print(); //se imprime el array
                break;
            case 6:
                continues = false; //se cancela el loop y termina programa
                break;
            default:
                cout<<"Opcion no valida"<<endl;//caso default/ no valido
                break;
        }
        cout<<endl;
    }
    
}


int main(){
    
    int selection; //seleccion base 
    Lista<int> lista1; //lista de ints
    Lista<double> lista2; //lista de doubles
    Lista<string> lista3; //lista de strings
    Lista<char> lista4; //lista de chars
    Lista<bool> lista5; //lista de bools

    selectionMenu(); //se llama al menu base

    cout<<"Ingresar seleccion: ";cin>>selection;cout<<endl;
    try{//try catch general para el programa
         switch (selection){ //switch para hacer operaciones a partir de lista
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
    catch(const std::exception& e){ //se imprime el error y cierra programa
        cout<<"Error de ejecución, verificar inputs y volver a iniciar el programa"<<endl;
    }
}
