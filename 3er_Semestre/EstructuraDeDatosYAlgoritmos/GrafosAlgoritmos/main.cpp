//Juan Carlos Garfias Tovar, A01652138
#include  "Graph.h"
#include <vector>

//menu
//funcion para imprimir el menu
//O(1)
void menu(){
    cout<<"1) Lista predefinida A"<<endl;
    cout<<"2) Lista predefinida B"<<endl;
    cout<<"3) Crear lista"<<endl;
    cout<<"4) Salir"<<endl;
}

//graphPrint
//funcion para desplegar todos los datos de un grafo
//O(1)
void graphPrint(vector< vector<int> > list){
    cout << "----=Graph=----\n";
    Graph<int> graph(list);
    graph.print();
    
    cout << "\n\n----=Grafo DFS=----\n";
    graph.dfsPrint(0);
    
    cout << "\n\n----=Grafo BFS=----\n";
    graph.bfsPrint(0);
    
    cout << "\n\n----=Shortest Path=----\n";
    graph.shortestPath(0);
    
    cout << "\n\n----=Topological sort=----\n";
    graph.topologicalSort();
    
    cout << "\n\n----=Es Bipartite=----\n";
    cout << (graph.isBipartite() ? "Es un grafo bipartite\n" : "No es un grafo bipartite\n");
}

//Lista
//funcion para crear una lista a partir del input de usuario
//o(n)
vector< vector<int> > lista(){
    vector< vector<int> > list;
    int vertex;
    int adjacent;
    int weight;
    int selection;
    bool continues = true;
    while(continues){
        cout<<"---------------------------------------------------"<<endl;
        cout << "Nuevo edge insertado"<<endl<<endl;
        vector<int> edge;
        cout << "Ingresar vertice >";
        cin>>vertex;
        cout << "Ingresar adyacencia >";
        cin>>adjacent;
        cout << "Ingresar peso >";
        cin>>weight;
        edge.push_back(vertex);
        edge.push_back(adjacent);
        edge.push_back(weight);
        list.push_back(edge);
        edge.clear();
        cout<<endl;
        cout << "Deseas insertar otro edge?"<<endl;
        cout << "1) Insertar otros"<<endl;
        cout << "2) Terminar"<<endl;
        cout<<"Ingresar seleccion >";cin>>selection;
        continues = selection == 1;
    }
    return list;
}

int main(){
    vector< vector<int> > list;
    bool continues = true;
    int selection;
    cout<<"---------------------------------------------------"<<endl;
    cout<<R"(
         _____            __          
        / ____|          / _|         
        | |  __ _ __ __ _| |_ ___  ___ 
        | | |_ | '__/ _` |  _/ _ \/ __|
        | |__| | | | (_| | || (_) \__ \
        \_____|_|  \__,_|_| \___/|___/     3
    )"<<endl;
    cout<<endl;
    cout<<"Juan Carlos Garfias Tovar"<<endl;
    cout<<"---------------------------------------------------"<<endl;
    while (continues){
        menu();
        cout<<"---------------------------------------------------"<<endl<<endl;
        cout<<"Ingresar seleccion >";cin>>selection;
        switch (selection){
            case 1:
                list = {{0,1,1},{0,3,2},{1,0,3},{1,2,4},{2,1,5},{2,3,6},{3,0,7},{3,2,8}}; 
                graphPrint(list);
                break;
            case 2:
                list = {{0,2,1},{0,3,7},{2,0,1},{2,1,1},{2,6,3},{1,2,1},{1,6,3},{1,5,4},{5,1,4},{5,6,4},{5,3,7},{3,0,7},{3,5,7},{3,7,1},{6,2,3},{6,1,3},{6,5,4},{6,4,6},{6,7,6},{7,6,6},{7,3,1},{4,6,6}};
                graphPrint(list);
                break;
            case 3:
                graphPrint(lista());
                break;
            case 4:
                continues = false;
                break;
            default:
                cout<<"OPCION NO VALIDA!"<<endl;
                break;
        }
        cout<<endl<<"---------------------------------------------------"<<endl;
    }
    cout<<"HASTA LUEGO!"<<endl<<endl;
    

}
