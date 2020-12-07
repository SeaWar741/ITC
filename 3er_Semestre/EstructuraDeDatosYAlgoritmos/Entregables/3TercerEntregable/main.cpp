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

//line
//funcion para imprimir linea divisoria
//O(1)
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

//welcome()
//imprime ascii art de bienvenida
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
//O(1)
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


//optionMenu
//funcion para las diferentes opciones del programa
void optionMenu(DoublyLinkedList<IPRegistry> &lista){
    int selection;
    bool continues = true;//variable para el loop

    ofstream out("IPLogger.json");//nombre del archivo json de salida
    

    cout<<endl;
    welcome();
    cout<<endl<<"Bienvenid@ a IP Verifier, donde podras conocer informacion sobre tus usuarios"<<endl;
    cout<<"sus accesos y como entran a tu sitio!"<<endl<<endl;
    cout<<"Se han detectado: "<<lista.getSize()<<" IPs"<<endl<<endl;
    while (continues){//mientras que sea verdadero
        menu();
        cout<<"Ingresar seleccion: >";cin>>selection;
        switch (selection){
            case 1:
                HeapSort(lista,"descending");//se hace un sort de la lista 
                lista.print();
                break;
            case 2:
                HeapSort(lista,"descending");//se hace un sort de la lista 
                lista.printTop();
                break;
            case 3:
                HeapSort(lista,"ascending");//se hace un sort de la lista invertido
                lista.printTop();
                break;
            case 4:
                out << lista.stringify();//se pasa el out a un print para insertarse en json
                out.close();
                cout<<endl;
                line();
                cout<<"ARCHIVO CREADO!"<<endl;
                line();
                cout<<endl;
                system("code ./data.json");//se ejecuta comando para abrir archivo json en vscode
                break;
            case 5:
                continues = false;//se termina el proceso
                break;
            default:
                cout<<endl;
                line();
                cout<<"OPCION NO VALIDA"<<endl;//opcion default
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
            words = split(line," "); //divide las palabras de la linea
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
                    errorString= errorString+ " " + words[i];//obtiene el string de error
                }
                else{
                    errorString+=words[i];
                };
            }

            ipString = split(words[3],":");//divide la ip del puerto
            int tempFrequency; //frecuencia temporal de ip
            int tempFrequencyE; //frecuencia temporal de errores
            string tempIp; //string de la ip temporal

            vector<string> errorsTemp; //vector temporal de errores
            vector<string> portsTemp; //vector temporal de puertos

            IPRegistry ipreg; //struct de ip temporal de entrada
            IPRegistry ipreg2; //struct de ip temporal de salida

            ipreg.ip = ipString[0]; //se asigna ip

            if(lista.existsIn(ipreg)){ //si se encuentra en la lista aumentar
                
                int pos = lista.getIndex(ipreg); //se obtiene el indice
                int posE;
                tempIp = lista.getData(pos).ip;//se obtiene dato de ip
                tempFrequency = lista.getData(pos).frequency; //se obtiene dato de frecuencia
                tempFrequency++;//se aumenta en uno la frecuencia


                errorsTemp = lista.getData(pos).errors; // se obtiene el vector de errores
                portsTemp = lista.getData(pos).ports; //se obtiene el vector de puertos
                /*
                for (int i=0; i<errorsTemp.size(); i++) 
                    cout << errorsTemp[i] << " "; 
                cout << endl; 
                */
                errorsTemp.push_back(errorString); //se inserta el error en el vector
                portsTemp.push_back(ipString[1]);  //se inserta el puerto en el vector
               
                //dar atributos a la IPRegistry
                ipreg2.ip = ipString[0];
                ipreg2.frequency = tempFrequency;
                ipreg2.errors = errorsTemp;
                ipreg2.ports = portsTemp;
                
                
                lista.updateData(ipreg,ipreg2); //se reemplaza el objeto en la lista
                
            }
            else{ //cuando no existe en la lista
                ipreg.ip = ipString[0]; //se asigna ip
                ipreg.frequency = 1; //se asigna frecuencia base
                errorsTemp.push_back(errorString); //se inserta error
                portsTemp.push_back(ipString[1]); //se inserta puerto
                //cout<<errorsTemp.size()<<endl;
                ipreg.errors = errorsTemp;
                ipreg.ports = portsTemp;
                lista.addLast(ipreg); //se hace add al struct en la lista
                //cout<<"inserted"<<endl;
            }

            errorString = ""; //reinicia valores
            words.clear();//limpia vector temporal de la linea

            i++;
        }
        file.close(); //cierra el archivo

        lista.sort();//aplica un sort

        HeapSort(lista,"descending");//aplica un heapsort a la lista

        optionMenu(lista); //llama al menu


    }

    return 0;
}