//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include "PriorityQueue.h"
//#include "IPRegistry.h"
//#include "DoublyLinkedList.h"
using namespace std;

void line(){
    cout<<"-----------------------------------------------------------------------------"<<endl;
}

//HeapSort
//se ordena a partir de remover el top de la lista y ahace add
template<class T>
void HeapSort(DoublyLinkedList<T>& list, string order ){
    PriorityQueue<T> heapAux(list);
    list.clear();
    while (!heapAux.isEmpty()){
        if(order == "ascending"){
            list.addFirst(heapAux.remove());//se insertan al inicios
        }
        if(order == "descending"){
            list.addLast(heapAux.remove());//se insertan al final
        }
    }
    
}


//O(n)
//Funcion para dividir string por token o separador
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

void welcome(){
    line();
    std::cout<<R"(

██╗██████╗     ██╗   ██╗███████╗██████╗ ██╗███████╗██╗███████╗██████╗ 
██║██╔══██╗    ██║   ██║██╔════╝██╔══██╗██║██╔════╝██║██╔════╝██╔══██╗
██║██████╔╝    ██║   ██║█████╗  ██████╔╝██║█████╗  ██║█████╗  ██████╔╝
██║██╔═══╝     ╚██╗ ██╔╝██╔══╝  ██╔══██╗██║██╔══╝  ██║██╔══╝  ██╔══██╗
██║██║          ╚████╔╝ ███████╗██║  ██║██║██║     ██║███████╗██║  ██║
╚═╝╚═╝           ╚═══╝  ╚══════╝╚═╝  ╚═╝╚═╝╚═╝     ╚═╝╚══════╝╚═╝  ╚═╝
                                                                      

    )"<<endl;
    line();
}

//menu
//funcion para mostrar el menu
void menu(){
    cout<<endl;
    line();
    cout<<"1) Imprimir las IPs"<<endl;
    cout<<"2) Mostrar las IPs con mas accesos"<<endl;
    cout<<"3) Mostrar las IPs con menos accesos"<<endl;
    cout<<"4) Exportar lista de IPs a JSON"<<endl;
    cout<<"5) Salir"<<endl;
    line();
    cout<<endl;
}



void optionMenu(DoublyLinkedList<IPRegistry> &lista){
    int selection;
    bool continues = true;

    ofstream out("IPLogger.json");
    

    cout<<endl;
    welcome();
    cout<<endl<<"Bienvenid@ a IP Verifier, donde podras conocer informacion sobre tus usuarios"<<endl;
    cout<<"sus accesos y como entran a tu sitio!"<<endl<<endl;
    while (continues){
        menu();
        cout<<"Ingresar seleccion: >";cin>>selection;
        switch (selection){
            case 1:
                HeapSort(lista,"descending");
                lista.print();
                break;
            case 2:
                HeapSort(lista,"descending");
                lista.printTop();
                break;
            case 3:
                HeapSort(lista,"ascending");
                lista.printTop();
                break;
            case 4:
                out << lista.stringify();
                out.close();
                cout<<endl;
                line();
                cout<<"ARCHIVO CREADO!"<<endl;
                line();
                cout<<endl;
                system("code ./data.json");
                break;
            case 5:
                continues = false;
                break;
            default:
                cout<<endl;
                line();
                cout<<"OPCION NO VALIDA"<<endl;
                line();
                cout<<endl;
                break;
        }
    }
    cout<<endl;
    line();
    cout<<"GRACIAS POR USAR IP VERIFIER"<<endl;
    line();
    cout<<endl;
    
}

int main(){
    DoublyLinkedList<IPRegistry> lista;

    ifstream file("./bitacora2.txt"); //abre el archivo

    if(file.is_open()){
        string line;
        vector<string> words; //vector para almacenar palabras de entry
        string errorString = "";    //string para el error
        vector<string> ipString;

        int i =0;
        while(getline(file,line)/* && i<=20*/){ //Se leen todos las entries por linea
            words = split(line," ");
            //print(words);ss
            /*
            entry.month = words[0];
            entry.day = stoi(words[1]);
            time = split(words[2],":");
            entry.hour = stoi(time[0]);//
            entry.minute = stoi(time[1]);
            entry.second = stoi(time[2]);
            entry.ip = words[3];
            */
            for (int i = 4; i < words.size(); i++){ //todos los elementos posteriores son parte del error de login
                if(i !=4 && i !=words.size()){
                    errorString= errorString+ " " + words[i];
                }
                else{
                    errorString+=words[i];
                };
            }

            ipString = split(words[3],":");
            int tempFrequency;
            int tempFrequencyE;
            string tempIp;

            vector<string> errorsTemp;
            vector<string> portsTemp;

            IPRegistry ipreg;
            IPRegistry ipreg2;

            ipreg.ip = ipString[0];

            if(lista.existsIn(ipreg)){
                
                int pos = lista.getIndex(ipreg);
                int posE;
                tempIp = lista.getData(pos).ip;
                tempFrequency = lista.getData(pos).frequency;
                tempFrequency++;


                errorsTemp = lista.getData(pos).errors;
                portsTemp = lista.getData(pos).ports;
                /*
                for (int i=0; i<errorsTemp.size(); i++) 
                    cout << errorsTemp[i] << " "; 
                cout << endl; 
                */
                errorsTemp.push_back(errorString);
                portsTemp.push_back(ipString[1]);
               
                //dar atributos a la IPRegistry
                ipreg2.ip = ipString[0];
                ipreg2.frequency = tempFrequency;
                ipreg2.errors = errorsTemp;
                ipreg2.ports = portsTemp;
                
                
                lista.updateData(ipreg,ipreg2);
                
            }
            else{
                ipreg.ip = ipString[0];
                ipreg.frequency = 1;
                errorsTemp.push_back(errorString);
                portsTemp.push_back(ipString[1]);
                //cout<<errorsTemp.size()<<endl;
                ipreg.errors = errorsTemp;
                ipreg.ports = portsTemp;
                lista.addLast(ipreg);
                //cout<<"inserted"<<endl;
            }

            errorString = "";
            words.clear();

            i++;
        }
        file.close();
        //cout<<lista.getSize()<<endl;
        lista.sort();

        HeapSort(lista,"descending");

        optionMenu(lista);

        /*

        //lista.print();

        lista.printTop();

        ofstream out("IPLogger.json");
        out << lista.stringify();
        out.close();

        */
    }

    return 0;
}