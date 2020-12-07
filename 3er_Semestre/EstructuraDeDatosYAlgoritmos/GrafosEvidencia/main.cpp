//Juan Carlos Garfias Tovar, A01652138

#include "Graph.h"
#include "Heap.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h> // for sleep()


using namespace std;

//----------------------complementarias-------------------------------

//split
//separa string a partir de delimitador
//o(n)
void split(vector<string> &vect, string input, string pattern){
    int start = 0; 
    int end = 0;
    string value;
    while(end >= 0){
        end = int(input.find(pattern, start));
        vect.push_back(input.substr(start, end - start));
        start = end + 1;
    }
}

//getErrorData
//obtiene el valor del error
void getErrorData(string &input, vector<string> inputValues){
    input = inputValues[4];
    for(int i = 5; i < inputValues.size(); i++){
        input = input + " " + inputValues[i];
    }
}

//heapSort
//ordena haciendo un heap y
//ordenandolo
//o(n)
void heapSort(Heap &heap){
    DoublyLinkedList list;
    for(int i = 0; i < 5; i++){
        list.addLast(heap[1]->ip, heap[1]->failedAttempts);
        heap.remove();
    }
    list.print();
}



//----------------------Principales-------------------------------------------------------------

//readRegistry
//obtiene los valores de cada ip
//o(n)
void readRegistry(Graph<string> &graph, int &qtyVertices){
    ifstream registry("bitacora.txt"); 
    if(registry){
        string txt;
        vector<string> lengths;
        int count = 0;
        while(getline(registry, txt) && count <= qtyVertices){//lectura de lineas
            if(count == 0){
                split(lengths, txt, " ");
                qtyVertices = stoi(lengths[0]);
            } else{
                graph.addVertex(txt);
            }
            count++;
        }
        registry.close();
        graph.setVertices(qtyVertices);
    } else{
        throw runtime_error("FILE NOT FOUND");
    }
}


//readAccess
//obtiene los valores de cada accesoo
//o(n)
void readAccess(Graph<string> &graph, int &qtyVertices){
    ifstream registry("bitacora.txt"); //open registry
    if(registry){
        vector<string> values;
        vector<string> data;
        vector<string> ipData;
        string ip, ipAd, line, month, hour, error;
        int count = 0, day;
        while(getline(registry, line)){
            if(count > qtyVertices){
                split(values, line, " ");
                month = values[0];
                day = stoi(values[1]);
                hour = values[2];

                split(ipData, values[3], ":");
                ip = ipData[0];
                ipData.clear();

                split(ipData, values[4], ":");
                ipAd = ipData[0];
                getErrorData(error, values); //get error (concatenate strings)
                
                graph.addEdge(ip, ipAd, month, day, hour, error);
                values.clear();
                data.clear();
                ipData.clear();
            }
            count++;
        }
        registry.close();
    } else{
        throw runtime_error("Error (readEdges): error opening registry (bitacora)");
    }
}

//heapCreate
//crea un heap
//o(1)
void heapCreate(Heap &ipHeap, Graph<string> &graph){
    vector<string> ips = graph.getVertices();
    for(auto ip: ips){
        ipHeap.insert(ip, graph.getAdjacenciesOfVertex(ip));
    }
}


int main(){
    Graph<string> graph;
    Heap failedAttemptsData;
    int qtyVertices = 0;

    cout<<endl<<"----------------------------------------------------------------------"<<endl;
    cout<<R"(
         ______    _ _          _   _                 _           
        |  ____|  (_) |        | | | |               (_)          
        | |__ __ _ _| | ___  __| | | |     ___   __ _ _ _ __  ___ 
        |  __/ _` | | |/ _ \/ _` | | |    / _ \ / _` | | '_ \/ __|
        | | | (_| | | |  __/ (_| | | |___| (_) | (_| | | | | \__ \
        |_|  \__,_|_|_|\___|\__,_| |______\___/ \__, |_|_| |_|___/
                                                __/ |            
                                                |___/             
    )"<<endl;
    cout<<"----------------------------------------------------------------------"<<endl<<endl;


    try{
        cout << "Cargando datos";
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        readRegistry(graph, qtyVertices);//
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        readAccess(graph, qtyVertices);//
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        heapCreate(failedAttemptsData, graph);//
        sleep(1);
        std::cout << "." << std::flush;
        sleep(1);
        std::cout << "." << std::flush;
        cout<<endl<<endl;

        cout<<"----------------------------------------------------------------------"<<endl<<endl;

        cout<<"IPS MAS SOSPECHOSAS"<<endl<<endl;

        heapSort(failedAttemptsData);//heapSort
    } catch(runtime_error &e) {
        cout << e.what();
    }
    
    return 0;
}
