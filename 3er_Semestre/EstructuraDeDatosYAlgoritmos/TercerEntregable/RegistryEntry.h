//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;



map<string, int> months; //map para los codigos de mes y numero de mes
map<int, string> monthsReversed; //mapa con key value invertidas al map original

int monthDuration[12] = {31,28,29,31,30,31,30,31,31,30,30,31}; //duracion maxima de cada mes

//--------------------------------Struct declaration---------------------------------

//Estructura de datos de registro
struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string port;
    string error;
    
    //Funcion para verificar igualdades de fecha
    bool dateIsEqual(RegistryEntry const & entry) const {
        if( (months[month] == months[entry.month] && day==entry.day) && hour == entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar menor fecha y hora
    bool dateIsMinor(RegistryEntry const & entry) const{
        if(months[month] < months[entry.month]){
            return true;
        }
        if(months[month] == months[entry.month] && day < entry.day){
            return true;
        }
        if(months[month] == months[entry.month] && day == entry.day && hour < entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar menor hora
    bool hourIsMinor(RegistryEntry const & entry) const{
        if(hour<=entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar mayors hora
    bool hourIsMajor(RegistryEntry const & entry) const{
        if(hour>=entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar igualdad de hora
    bool hourIsEqual(RegistryEntry const & entry) const{
        if(hour == entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

};

//-----------------------------Struct helper functions---------------------------------

//Funcion para llenar valores del map de meses
void populateMonths(){
    months.insert(pair<string, int>("Jan", 1)); 
    months.insert(pair<string, int>("Feb", 2)); 
    months.insert(pair<string, int>("Mar", 3)); 
    months.insert(pair<string, int>("Apr", 4)); 
    months.insert(pair<string, int>("May", 5)); 
    months.insert(pair<string, int>("Jun", 6)); 
    months.insert(pair<string, int>("Jul", 7));
    months.insert(pair<string, int>("Aug", 8)); 
    months.insert(pair<string, int>("Sep", 9)); 
    months.insert(pair<string, int>("Oct", 10)); 
    months.insert(pair<string, int>("Nov", 11)); 
    months.insert(pair<string, int>("Dic", 12));
}

//Funcion para invertir key y value de mapa de meses
void populateMonthsReversed(){ //
    for (auto i=months.begin(); i!=months.end(); ++i)
    monthsReversed[i->second] = i->first;
}

//Funcion para desplegar entry 
void printEntry(RegistryEntry entry){
    cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    //cout<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<<endl;
}

//Funcion para convertir en string un entry formateado
string stringEntry(RegistryEntry entry){
    //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    stringstream ss;
    //ss<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<< "\n";
    ss<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<< "\n";
    return ss.str();
}