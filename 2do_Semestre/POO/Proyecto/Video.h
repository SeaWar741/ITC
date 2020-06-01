#include <iostream>
using namespace std;
#ifndef Video_h
#define Video_h

class Video{
private:
    int id;
    bool adult;
    string language;
    float duration;
    string title;
    string description;
    string genre;
    float rating;
public:
    Video();
    Video(int,bool,string,float,string,string,string,float);
    
    void setId(int in){id = in;};
    void setAdult(bool is){adult = is;};
    void setLanguage(string lan){language = lan;};
    void setDuration(float time){duration = time;};
    void setTitle(string ti){title = ti;};
    void setDescription(string des){description = des;};
    void setGenre(string g){genre = g;};
    void setRating(float r){rating = r;};
    
    int getId(){return id;};
    bool getAdult(){return adult;};
    string getLanguage(){return language;};
    float getDuration(){return duration;};
    string getTitle(){return title;};
    string getDescription(){return description;};
    string getGenre(){return genre;};
    float getRating(){return rating;};
    virtual void mostrar();
};

Video::Video(){
    id = 0;
    adult = false;
    language = "";
    duration = 0.0;
    title = "";
    description = "";
    genre = "";
    rating = 0.0;
}

Video::Video(int iid,bool iadult,string ilanguage,float iduration,string ititle,string idescription,string igenre,float irating){
    id = iid;
    adult = iadult;
    language = ilanguage;
    duration = iduration;
    title = ititle;
    description = idescription;
    genre = igenre;
    rating = irating;
}


#endif
