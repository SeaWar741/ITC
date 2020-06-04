#ifndef Serie_h
#define Serie_h

#include "Capitulo.h"

class Serie{
private:
    int id;//identificador numerico
    string title;//titulo
    string network;//cadena o televisora
    string runtime;//duracion de la serie en años
    float rating;//calificacion
    vector<Capitulo> capitulos;
public:
    Serie();
    Serie(int id,string ti,string net,string run,float rating,vector<Capitulo> caps);

    void setTitle(string ti){title = ti;};
    void setNetwork(string net){network = net;};
    void setRunTime(string run){runtime = run;};
    void setRating(float rat){rating = rat;};
    void setCapitulos(vector<Capitulo> caps){capitulos = caps;};

    string getTitle(){return title;};
    string getNetwork(){return network;};
    string getRuntime(){return runtime;};
    float getRating(){return rating;};
    vector<Capitulo> getCapitulos(){return capitulos;};

    void mostrar();
};

Serie::Serie(){
    vector<Capitulo> cap(1);
    id = -1;
    title = "";
    network = "";
    runtime = "";
    capitulos = cap;
}

Serie::Serie(int id,string ti,string net,string run,float rating,vector<Capitulo> caps){
    title = ti;
    network = net;
    runtime = run;
    capitulos = caps;
}

void Serie::mostrar(){
    cout<<"ID: "<<id<<endl;
    cout<<"Titulo de la serie: "<<title<<endl;
    cout<<"Rating: "<<rating<<endl;
    cout<<"Network: "<<network<<endl;
    cout<<"Duracion promedio de los capitulos: "<<runtime<<endl;
    int i;
    //se cuenta la cantidad de capitulos de la serie
    for(i=0;i<capitulos.size();i++){
        i++;
    }
    cout<<"Cantidad de capitulos :"<<i<<endl;
}

#endif