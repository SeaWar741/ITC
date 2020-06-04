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
    cout<<"ID: "<<id<<endl;
    cout<<"Temporada: "<<season<<endl;
    cout<<"No. capitulo: "<<chapter<<endl;
    cout<<"Titulo del capitulo: "<<title<<endl;
    cout<<"Fecha de estreno:"<<airDate;
    cout<<"+18 :"<<adult<<endl;
    cout<<"Idioma: "<<language<<endl;
    cout<<"Duracion: "<<duration<<endl;
    cout<<"Genero: "<<genre<<endl;
    cout<<"Rating: "<<rating<<endl;
    cout<<"Descripcion: "<<description<<endl;
}
#endif
