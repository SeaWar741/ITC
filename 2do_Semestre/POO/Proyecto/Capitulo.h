#ifndef Capitulo_h
#define Capitulo_h

class Capitulo : public Video{
private:
    string stitle;//titulo de la serie a la que pertenece
    int season;//temporada
    int chapter;//capitulo
    string airDate;//fecha de estreno
    string chapterDescription;//descripcion del capitulo
public:
    Capitulo();
    Capitulo(string,int,bool,string,float,string,string,string,float,int,int,string,string);
    
    void setSTitle(string ti){stitle = ti;};
    void setSeason(int s){season = s;};
    void setChapter(int c){chapter = c;};
    void setAirDate(string d){airDate = d;};
    void setChapterDescription(string des){chapterDescription = des;};

    string getSTitle(){return stitle;};
    int getSeason(){return season;};
    int getChapter(){return chapter;};
    string getAirDate(){return airDate;};
    string getChapterDescription(){return chapterDescription;};

    void mostrar();
};

Capitulo::Capitulo(){
    stitle = "";
    season = -1;
    chapter = -1;
    airDate ="";
    chapterDescription ="";
}

Capitulo::Capitulo(string ti,int iid,bool iadult,string ilanguage,float iduration,string ititle,string idescription,string igenre,float irating,int s,int c,string d,string des) : Video(iid, iadult, ilanguage, iduration, ititle, idescription, igenre, irating){
    stitle = ti;
    season = s;
    chapter = c;
    airDate = d;
    chapterDescription = des;
}

void Capitulo::mostrar(){
    char esc_char = 27; 
    string color3 = "\x1B[31m";
    string color4 = "\033[0m";

    string color1 = "\x1B[36m";
    string color2 = "\033[0m";

    string ad = "";
    if(adult){
        ad = "Si";
    }else{
        ad = "No";
    }
    cout <<color3<< esc_char << "[1m" <<"ID: "<< esc_char << "[0m" <<color4<<id<<endl;
    cout <<color1<< esc_char << "[1m" <<"Serie: "<< esc_char << "[0m" <<color2<<stitle<<endl;
    cout <<color1<< esc_char << "[1m" <<"Temporada: "<< esc_char << "[0m" <<color2<<season<<endl;
    cout <<color1<< esc_char << "[1m" <<"No. capitulo: "<< esc_char << "[0m" <<color2<<chapter<<endl;
    cout <<color1<< esc_char << "[1m" <<"Titulo del capitulo: "<< esc_char << "[0m" <<color2<<title<<endl;
    cout <<color1<< esc_char << "[1m" <<"Rating: "<< esc_char << "[0m" <<color2<<rating<<endl;
    cout <<color1<< esc_char << "[1m" <<"Fecha de estreno:"<< esc_char << "[0m" <<color2<<airDate<<endl;
    cout <<color1<< esc_char << "[1m" <<"+18: "<< esc_char << "[0m" <<color2<<ad<<endl;
    cout <<color1<< esc_char << "[1m" <<"Idioma: "<< esc_char << "[0m" <<color2<<language<<endl;
    cout <<color1<< esc_char << "[1m" <<"Duracion: "<< esc_char << "[0m" <<color2<<duration<<endl;
    cout <<color1<< esc_char << "[1m" <<"Genero: "<< esc_char << "[0m" <<color2<<genre<<endl;
    cout <<color1<< esc_char << "[1m" <<"Descripcion: "<< esc_char << "[0m" <<color2<<description<<endl;
}
#endif
