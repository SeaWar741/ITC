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
#include "RegistryEntry.h"
//#include "IPRegistry.h"
#include "DoublyLinkedList.h"
using namespace std;

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

//exists



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

int main(){
    DoublyLinkedList<IPRegistry> lista;
    populateMonths();//se llenan los meses
    populateMonthsReversed();

    ifstream file("./bitacora2.txt"); //abre el archivo
    vector <RegistryEntry> entries; //vector para registry

    if(file.is_open()){
        string line;
        vector<string> words; //vector para almacenar palabras de entry
        vector<string> time;    //vector para el tiempo
        string errorString = "";    //string para el error
        vector<string> ipString;

        int i =0;
        while(getline(file,line)/* && i<=20*/){ //Se leen todos las entries por linea
            words = split(line," ");
            //print(words);
            RegistryEntry entry; //se crea entry y se hace split de elementos para llener el struct
            /*
            entry.month = words[0];
            entry.day = stoi(words[1]);
            time = split(words[2],":");
            entry.hour = stoi(time[0]);//
            entry.minute = stoi(time[1]);
            entry.second = stoi(time[2]);
            entry.ip = words[3];
            for (int i = 4; i < words.size(); i++){ //todos los elementos posteriores son parte del error de login
                if(i !=4 && i !=words.size()){
                    errorString= errorString+ " " + words[i];
                }
                else{
                    errorString+=words[i];
                };
            }
            */

            ipString = split(words[3],":");
            int tempFrequency;
            string tempIp;

            IPRegistry ipreg;
            IPRegistry ipreg2;

            ipreg.ip = ipString[0];
            


            if(lista.existsIn(ipreg)){
                
                
                int pos = lista.getIndex(ipreg);
                tempIp = lista.getData(pos).ip;
                tempFrequency = lista.getData(pos).frequency;
                tempFrequency++;
                
               
                ipreg2.ip = ipString[0];
                ipreg2.frequency = tempFrequency;
                lista.updateData(ipreg,ipreg2);
                
                
                //cout<<"updated"<<endl;
            }
            else{
                ipreg.ip = ipString[0];
                ipreg.frequency = 1;
                lista.addLast(ipreg);
                //cout<<"inserted"<<endl;
            }

            entry.error = errorString;
            entries.push_back(entry);//se inserta en vector
            

            errorString = "";
            words.clear();
            time.clear();

            i++;
        }
        file.close();
        cout<<lista.getSize()<<endl;
        lista.sort();
        lista.print();

        HeapSort(lista,"descending");
        lista.print();

    }

    return 0;
}