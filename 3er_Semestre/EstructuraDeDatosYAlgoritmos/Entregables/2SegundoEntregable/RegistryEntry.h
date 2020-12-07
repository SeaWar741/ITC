#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <map>

using namespace std;

map<string, int> months; //map para los codigos de mes y numero de mes
map<int, string> monthsReversed; //mapa con key value invertidas al map original

int monthDuration[12] = {31,28,29,31,30,31,30,31,31,30,30,31}; //duracion maxima de cada mes

//--------------------------------Super helper functions------------------------------

//Fncion para imprimir linea
void line(){
    cout<<"----------------------------------------------------"<<endl;
}


//--------------------------------Struct declaration---------------------------------

//Estructura de datos de registro
struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string error;
    
    //Funcion para verificar igualdades de fecha
    bool dateIsEqual(RegistryEntry const & entry) const {
        if( (months[month] == months[entry.month] && day==entry.day) && hour == entry.hour && minute == entry.minute && second== entry.second){
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
		if(months[month] == months[entry.month] && day == entry.day && hour == entry.hour && minute < entry.minute){
            return true;
        }
		if(months[month] == months[entry.month] && day == entry.day && hour == entry.hour && minute == entry.minute && second < entry.second){
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

    //sobrecarga de operador igual, permite declarar a partir de los nodos
    void operator=(RegistryEntry &first){
        month = first.month;
        day = first.day;
        hour = first.hour;
        minute = first.minute;
        second = first.second;
        ip = first.ip;
        error = first.error;
        //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    }


};

//-----------------------------Struct helper functions---------------------------------

RegistryEntry copy(RegistryEntry first){
        RegistryEntry entry;
        entry.month = first.month;
        entry.day = first.day;
        entry.hour = first.hour;
        entry.minute = first.minute;
        entry.second = first.second;
        entry.ip = first.ip;
        entry.error = first.error;
        //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
        return entry;
}


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

//Funcion para ver si una entry es previa a otra
bool isEarlier(RegistryEntry &first, RegistryEntry &last){
    if(months[first.month]>months[last.month]){
        //cout<<"comparison"<<endl;
        return true;
    }
    if(months[first.month]==months[last.month] && first.day>last.day){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour>last.hour){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour==last.hour && first.minute>last.minute){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour==last.hour && first.minute==last.minute && first.second>last.second){
        return true;
    }
    else{
        //cout<<"comparison failed"<<endl;
        return false;
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

//O(n)
//Funcion para pasar a lowercase string
string toLowerCase(string str) {

    int str_len = str.length();

    string final_str = "";

    for(int i=0; i<str_len; i++) {

        char character = str[i];

        if(character>=65 && character<=92) {

            final_str += (character+32);

        } else {

            final_str += character;

        }

    }

    return final_str;

}

//Funcion para formatear el string de una fecha para ser valido
string monthFormater(string txt){
    string txtMod = toLowerCase(txt);
    txtMod[0] = toupper(txtMod[0]);//se hace uppercase la primer letra
    return txtMod;
}

