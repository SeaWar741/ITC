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
    cout<<"3) DFS"<<endl;
    cout<<"4) BFS"<<endl;
    cout<<"5) Salir"<<endl;
    cout<<"---------------------------------------------------"<<endl;
}

int main(){
    
    vector< vector<char> > list = {{'a', 'b'}, {'a', 'c'}, {'a', 'e'}, {'b', 'a'}, {'b', 'd'}, {'c', 'a'}, {'c', 'd'}, {'d', 'b'}, {'d', 'c'}, {'d', 'e'}, {'e', 'a'}, {'e', 'd'}};
    vector< vector<char> > list1 = {{'A','B'},{'A','E'},{'A','H'},{'B','A'},{'B','C'},{'B','E'},{'C','B'},{'C','D'},{'C','E'},{'C','F'},{'D','C'},{'E','A'},{'E','B'},{'E','C'},{'E','G'},{'E','H'},{'F','C'},{'F','J'},{'G','E'},{'G','J'},{'H','A'},{'H','E'},{'H','I'},{'H','J'},{'I','H'},{'J','F'},{'J','G'},{'J','H'}};
    Graph<char> graph(list,5,12);//creacion de objetos lista
    Graph<char> graph1(list1,10,26);
    
    GraphM<char> graphM(list,5,12);//creacion de objetos matriz
    GraphM<char> graphM1(list1,10,26);

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
        \_____|_|  \__,_|_| \___/|___/     2
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
                    cout<<"---------------------------------------------------"<<endl;
                    if(listSelection == 1){//verificar listas
                        graph.print();
                    }else{
                        graph1.print();
                    }
                    break;
                case 2:
                    cout<<"---------------------------------------------------"<<endl;
                    if(listSelection == 1){//verificar listas
                        graphM.print();
                    }else{
                        graphM1.print();
                    }
                    break;
                case 3:
                    cout<<"---------------------------------------------------"<<endl;
                    if(listSelection == 1){//verificar listas
                        cout<<"-------=Graph=-------"<<endl;
                        graph.dfs();
                        cout<<"-------=GraphM=-------"<<endl;
                        graphM.dfs();
                    }else{
                        cout<<"-------=Graph=-------"<<endl;
                        graph1.dfs();
                        cout<<"-------=GraphM=-------"<<endl;
                        graphM1.dfs();
                    }
                    break;
                case 4:
                    cout<<"---------------------------------------------------"<<endl;
                    if(listSelection == 1){//verificar listas
                        cout<<"-------=Graph=-------"<<endl;
                        graph.bfs();
                        cout<<"-------=GraphM=-------"<<endl;
                        graphM.bfs();
                    }else{
                        cout<<"-------=Graph=-------"<<endl;
                        graph1.bfs();
                        cout<<"-------=GraphM=-------"<<endl;
                        graphM1.bfs();
                    }
                    break;
                case 5:
                    continues=false;
                    break;
                default:
                    cout<<"OPCION NO VALIDA!"<<endl<<endl;
                    break;
            }
        }
        else if(listSelection == 5){
            continues=false;
        }
        else{
            cout<<"OPCION NO VALIDA!"<<endl<<endl;
        }
    }

    cout<<endl<<"GRACIAS POR USAR GRAFOS! HASTA LUEGO!"<<endl;//despedida
    
}
