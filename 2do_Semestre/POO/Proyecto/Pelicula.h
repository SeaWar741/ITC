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
    cout<<"ID: "<<id<<endl;
    cout<<"Pelicula: "<<title<<endl;
    cout<<"Fecha de estreno: "<<releaseDate<<endl;
    cout<<"+18: "<<adult<<endl;
    cout<<"Idioma: "<<language<<endl;
    cout<<"Duracion: "<<duration<<" minutos"<<endl;
    cout<<"Genero: "<<genre<<endl;
    cout<<"Rating: "<<rating<<endl;
    cout<<"Productores: ";
    //se itera para mostrar en forma de lista todos los productores
    for(int i = 0;i<productionCompanies.size();i++){
        if(i == productionCompanies.size()-1){
            cout<<productionCompanies[i]<<endl;
        }else{
            cout<<productionCompanies[i]<<",";
        }
    }
    cout<<"Descripcion: "<<description<<endl;
    
}
#endif