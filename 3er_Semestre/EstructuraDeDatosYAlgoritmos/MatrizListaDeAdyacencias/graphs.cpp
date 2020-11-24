//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <vector>

#include "Graph.h"
#include "GraphM.h"

using namespace std;

//menu
//funcion para mostrar el menu
//O(1)
void menu(){
    cout<<"---------------------------------------------------"<<endl;
    cout<<"1) Mostrar lista"<<endl;
    cout<<"2) Mostrar matriz"<<endl;
    cout<<"3) Salir"<<endl;
    cout<<"---------------------------------------------------"<<endl;
}

int main(){
    vector< vector<char> >    list = {{'a','b'},{'a','c'},{'a','e'},{'b','a'},{'b','d'},{'c','a'},{'c','d'},{'d','b'},{'d','c'},{'d','e'},{'e','a'},{'e','d'}};
    vector< vector<char> >    list1 = {{'a','b'},{'a','c'},{'b','c'},{'d','a'},{'d','b'},{'d','c'}};
    Graph<char> graph(list,5,12);//creacion de objetos lista
    Graph<char> graph1(list1,4,6);
    
    GraphM<char> graphM(list,5,12);//creacion de objetos matriz
    GraphM<char> graphM1(list1,4,6);

    bool continues = true;//variable continuar
    int listSelection;//variable para seleccion de lista
    int selection;//seleccion del menu

    

    cout<<"---------------------------------------------------"<<endl;
    cout<<R"(
         _____            __          
        / ____|          / _|         
        | |  __ _ __ __ _| |_ ___  ___ 
        | | |_ | '__/ _` |  _/ _ \/ __|
        | |__| | | | (_| | || (_) \__ \
        \_____|_|  \__,_|_| \___/|___/
    )"<<endl;
    cout<<endl;
    cout<<"Juan Carlos Garfias Tovar"<<endl;
    while (continues){
        menu();
        cout<<"Ingresar seleccion de datos (1/2) >";cin>>listSelection;
        cout<<"Ingresar seleccion menu >";cin>>selection;
        if(listSelection == 1 || listSelection == 2){//verificar que sea valida la seleccion lista
            switch (selection){//switch a partir de seleccion
            case 1:
                if(listSelection == 1){//verificar listas
                    graph.print();
                }else{
                    graph1.print();
                }
                break;
            case 2:
                if(listSelection == 1){//verificar listas
                    graphM.print();
                }else{
                    graphM1.print();
                }
                break;
            case 3:
                continues=false;
                break;
            default:
                cout<<"OPCION NO VALIDA!"<<endl<<endl;
                break;
            }
        }
        else{
            cout<<"OPCION NO VALIDA!"<<endl<<endl;
        }
    }

    cout<<endl<<"GRACIAS POR USAR GRAFOS! HASTA LUEGO!"<<endl;//despedida
    
    

    return 0;
}
