#ifndef Pelicula_h
#define Pelicula_h

#include "Video.h"

class Pelicula : public Video{
private:
    vector<string> productionCompanies;//compañias productoras
    string releaseDate;//fecha de estreno
public:
    Pelicula();
    Pelicula(int,bool,string,float,string,string,string,float,vector<string>,string);
    
    void setProductionCompanies(vector<string> companies){productionCompanies=companies;};
    void setReleaseDate(string date){releaseDate = date;};
    
    vector<string> getProductionCompanies(){return productionCompanies;};
    string getReleaseDate(){return releaseDate;};
    
    void mostrar();
};

Pelicula::Pelicula() : Video(){
    vector<string> companies;//se crea un vector de un elemento
    productionCompanies = companies;
    releaseDate = "";
}

Pelicula::Pelicula(int iid,bool iadult,string ilanguage,float iduration,string ititle,string idescription,string igenre,float irating,vector<string> companies,string date) : Video(iid, iadult, ilanguage, iduration, ititle, idescription, igenre, irating){
    productionCompanies = companies;
    releaseDate = date;
}
void Pelicula::mostrar(){
    char esc_char = 27; 
    string color3 = "\x1B[31m";
    string color4 = "\033[0m";

    string color1 = "\x1B[36m";
    string color2 = "\033[0m";
    string ad;
    if(adult){
        ad = "Si";
    }else{
        ad = "No";
    }
    cout <<color3<< esc_char << "[1m" <<"ID: "<< esc_char << "[0m" <<color4<<id<<endl;
    cout <<color1<< esc_char << "[1m" <<"Pelicula: "<< esc_char << "[0m" <<color2<<title<<endl;
    cout <<color1<< esc_char << "[1m" <<"Fecha de estreno: "<< esc_char << "[0m" <<color2<<releaseDate;
    cout <<color1<< esc_char << "[1m" <<"+18: "<< esc_char << "[0m" <<color2<<ad<<endl;
    cout <<color1<< esc_char << "[1m" <<"Idioma: "<< esc_char << "[0m" <<color2<<language<<endl;
    cout <<color1<< esc_char << "[1m" <<"Duracion: "<< esc_char << "[0m" <<color2<<duration<<" minutos"<<endl;
    cout <<color1<< esc_char << "[1m" <<"Genero: "<< esc_char << "[0m" <<color2<<genre<<endl;
    cout <<color1<< esc_char << "[1m" <<"Rating: "<< esc_char << "[0m" <<color2<<rating<<endl;
    cout <<color1<< esc_char << "[1m" <<"Productores: "<< esc_char << "[0m" <<color2;
    //se itera para mostrar en forma de lista todos los productores
    for(int i = 0;i<productionCompanies.size();i++){
        if(productionCompanies[i]!="-"){
            if(i == productionCompanies.size()-1){
                cout<<productionCompanies[i]<<endl;
            }else{
                cout<<productionCompanies[i]<<",";
            }
        }
        else{
            cout<<endl;
        }
    }
    cout <<color1<< esc_char << "[1m" <<"Descripcion: "<< esc_char << "[0m" <<color2<<description<<endl;
    
}
#endif