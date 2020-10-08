#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <map>

#include "DLinkedList.h"


using namespace std;

int main() {
	DLinkedList<RegistryEntry> entries;
	populateMonths();//se llenan los meses
    populateMonthsReversed();

    ifstream file("./bitacora.txt"); //abre el archivo
	if(file.is_open()){
        string line;
        vector<string> words; //vector para almacenar palabras de entry
        vector<string> time;    //vector para el tiempo
        string errorString = "";    //string para el error

        int i =0;
        while(getline(file,line) && i<=20){ //Se leen todos las entries por linea
            words = split(line," ");
            //print(words);
            RegistryEntry entry; //se crea entry y se hace split de elementos para llener el struct
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
            
            entry.error = errorString;
            
			entries.insertAtTail(entry);//se inserta en vector

			//printEntry(entry);

            errorString = "";
            words.clear();
            time.clear();
            i++;
        }
        file.close();
    }

	//entries.print();
	
}	