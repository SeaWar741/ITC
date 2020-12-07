//Juan Carlos Garfias Tovar, A01652138

#include "Hash.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//---------------------------------------------------------------------Funciones auxiliares----------------------------------------------------------------------

//split
//parte en sub elementos un string
void split(vector<string> &vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    while(end >= 0){
        end = int(str.find(pattern, beg));
        vect.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }
}


//getAmountErrors
//obtiene los errores de cada ip
//o(n)
int getAmountErrors(){
    ifstream registry("bitacora.txt");
    if(registry){
        string error;
        getline(registry, error);
        vector<string> lengths;
        split(lengths, error, " ");
        return stoi(lengths[0]);
    }
    return 0;
}


//menu
//despliega menu
void menu(){
    cout<<"1) Cargar datos"<<endl;
    cout<<"2) Buscar por IP"<<endl;
    cout<<"3) Salir"<<endl;
    
}


//---------------------------------------------------------------------Funciones principales----------------------------------------------------------------------

//getErrors
//obtiene errores
//o(1)
void getErrors(string &str, vector<string> errorValue){
    str = errorValue[4];
    for(int i = 5; i < errorValue.size(); i++){
        str = str + " " + errorValue[i];
    }
}

//getIps
//obtiene ips del archivo
//o(n)
void getIps(Hash<string> &hash){
    ifstream registry("bitacora.txt");
    if(registry){
        string txt;
        vector<string> lengths;
        int count = 0;  
        while(getline(registry, txt) && count < hash.getSize()){
            if(count != 0){
                hash.insert(txt);
            }
            count++;
        }
    } else{
        throw runtime_error("registry NOT FOUND");
    }
    registry.close();
}

//getErrorsEdges
//obtiene los edges
void getErrorEdges(Hash<string> &hash){
    ifstream registry("bitacora.txt");
    if(registry){
        string line, ip, addresses;
        vector<string> values;
        vector<string> ipErrors;
        int count = 0;
        while(getline(registry, line)){
            if(count > hash.getSize()){
                split(values, line, " ");
                split(ipErrors, values[3], ":");
                ip = ipErrors[0];
                ipErrors.clear();

                split(ipErrors, values[4], ":");
                addresses = ipErrors[0];
                hash.insertEdge(ip, addresses); 
                values.clear();
                ipErrors.clear();
            }
            count++;
        }
    }
}



int main(){
    Hash<string> hash(getAmountErrors());
    string ip;

    bool continues = true;
    int selection;
    try{
        cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
        cout<<endl<<R"(
            ______ _____  _____   ____  _____    ______ _           _           
            |  ____|  __ \|  __ \ / __ \|  __ \  |  ____(_)         | |          
            | |__  | |__) | |__) | |  | | |__) | | |__   _ _ __   __| | ___ _ __ 
            |  __| |  _  /|  _  /| |  | |  _  /  |  __| | | '_ \ / _` |/ _ \ '__|
            | |____| | \ \| | \ \| |__| | | \ \  | |    | | | | | (_| |  __/ |   
            |______|_|  \_\_|  \_\\____/|_|  \_\ |_|    |_|_| |_|\__,_|\___|_|   
        )"<<endl;

        cout<<endl;

        while(continues){
            cout<<"-------------------------------------------------------------------------------------------------------"<<endl;
            menu();
            cout<<endl;
            cout<<"Ingresar seleccion >";cin>>selection;

            switch (selection){
            case 1:
                /* code */
                getIps(hash);
                getErrorEdges(hash);
                break;
            case 2:
                cout<<"Ingresar IP a buscar >";cin>>ip;
                hash.printEdges(ip);
                break;
            case 3:
                continues = false;
                break;
            default:
                cout<<"OPCION INVALIDA"<<endl;
                break;
            }
        }

    } catch(runtime_error &e) {
        cout << e.what();
    }
    
    cout<<endl<<"HASTA LUEGO"<<endl;
    return 0;
}