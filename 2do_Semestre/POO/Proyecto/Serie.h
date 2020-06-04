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
    vector<Video *> capitulos;
public:
    Serie();
    Serie(int id,string ti,string net,string run,float rating,vector<Video *> caps);

    void setTitle(string ti){title = ti;};
    void setNetwork(string net){network = net;};
    void setRunTime(string run){runtime = run;};
    void setRating(float rat){rating = rat;};
    void setCapitulos(vector<Video *> caps){capitulos = caps;};

    string getTitle(){return title;};
    string getNetwork(){return network;};
    string getRuntime(){return runtime;};
    float getRating(){return rating;};
    vector<Video *> getCapitulos(){return capitulos;};

    void mostrar();
};

Serie::Serie(){
    vector<Video *> cap(1);
    id = -1;
    title = "";
    network = "";
    runtime = "";
    runtime = "";
    rating = 0.0;
    capitulos = cap;
}

Serie::Serie(int iid,string ti,string net,string run,float ra,vector<Video *> caps){
    id = iid;
    title = ti;
    network = net;
    runtime = run;
    rating = ra;
    capitulos = caps;
}

void Serie::mostrar(){
    char esc_char = 27;
    string color3 = "\x1B[31m";
    string color4 = "\033[0m";

    string color1 = "\x1B[36m";
    string color2 = "\033[0m"; 
    cout <<color3<< esc_char << "[1m" <<"ID: "<< esc_char << "[0m" <<color4<<id<<endl;
    cout <<color1<< esc_char << "[1m" <<"Titulo de la serie: "<< esc_char << "[0m" <<color2<<title<<endl;
    cout <<color1<< esc_char << "[1m" <<"Rating: "<< esc_char << "[0m" <<color2<<rating<<endl;
    cout <<color1<< esc_char << "[1m" <<"Network: "<< esc_char << "[0m" <<color2<<network<<endl;
    int i;
    //se cuenta la cantidad de capitulos de la serie
    for(i=0;i<capitulos.size();i++){
        i++;
    }
    cout <<color1<< esc_char << "[1m" <<"Cantidad de capitulos: "<< esc_char << "[0m" <<color2<<i<<endl;
    cout <<color1<< esc_char << "[1m" <<"Duracion promedio de los capitulos: "<< esc_char << "[0m" <<color2<<runtime;
}

#endif