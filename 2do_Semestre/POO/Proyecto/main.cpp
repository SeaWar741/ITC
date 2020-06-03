//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>

#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include "Pelicula.h"
#include "Capitulo.h"
#include "Serie.h"
using namespace std;

vector<Video *> videos;
vector<Serie *> series;
int cPeliculas = 0;
int cCapitulos = 0;

//Funciones helper
bool to_bool(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream is(str);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}

void fetchData(){
    //variables generales
    int id;//identificador
    bool adult;//pelicula para mayores de 18
    string language;//idioma original
    float duration;//duracion en minutos
    string title;//titulo del video
    string description;//descripcion del video
    string genre;//genero del video
    float rating;//calificacion del video

    //variables movies
    vector<string> productionCompanies;//compañias productoras
    string releaseDate;//fecha de estreno

    //variables series
    string stitle;//titulo de la serie a la que pertenece
    int season;//temporada
    int chapter;//capitulo
    string airDate;//fecha de estreno
    string chapterDescription;//descripcion del capitulo

    //Movies
    ifstream myFile;
    myFile.open("./Data/movies.txt");

    int counter = 0;
    
    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //tipo	id	adult	language	duration	title	description	genre	rating	companies	companies	companies	releasedate
        switch (counter){
            case 1:
                id = stoi(line);
                break;
            case 2:
                adult = to_bool(line);
                break;
            case 3:
                language = line;
                break;
            case 4:
                duration = stof(line);
                break;
            case 5:
                title = line;
                break;
            case 6:
                description = line;
                break;
            case 7:
                genre = line;
                break;
            case 8:
                rating = stof(line);
                break;
            case 9:
                productionCompanies.push_back(line);
                break;
            case 10:
                productionCompanies.push_back(line);
                break;
            case 11:
                productionCompanies.push_back(line);
                break;
            case 12:
                releaseDate = line;
                videos.push_back(new Pelicula(id,adult,language,duration,title,description,genre,rating,productionCompanies,releaseDate));
                productionCompanies.clear();
                counter = 0;
                break;
            default:
                cPeliculas++;
                break;
        }
        counter++;
    }
    myFile.close();

    //Capitulos--------------------------------------------------------------------------------------------------
    myFile.open("./Data/chapters.txt");

    counter = 0;

    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //tipo	id	adult	language	duration	title	description	genre	rating	companies	companies	companies	releasedate
        switch (counter){
            case 1:
                id = stoi(line);
                break;
            case 2:
                adult = to_bool(line);
                break;
            case 3:
                language = line;
                break;
            case 4:
                duration = stof(line);
                break;
            case 5:
                title = line;
                break;
            case 6:
                description = line;
                break;
            case 7:
                genre = line;
                break;
            case 8:
                rating = stof(line);
                break;
            case 9:
                stitle = line;
                break;
            case 10:
                season = stoi(line);
                break;
            case 11:
                chapter = stoi(line);
                break;
            case 12:
                airDate = line;
                break;
            case 13:
                chapterDescription = line;
                videos.push_back(new Capitulo(stitle,id,adult,language,duration,title,description,genre,rating,season,chapter,airDate,chapterDescription));
                counter = 0;
                break;
            default:
                cPeliculas++;
                break;
        }
        counter++;
    }
    myFile.close();


    
}

//mostrar todas las peliculas
void mostrarPeliculas(){
    for (int i = 0; i < videos.size(); i++){
        videos[i]->mostrar();
        cout<<endl;
    }
}

//mostrar todas las series 
void mostrarSeries(){

}

//mostrar videos por calificacion a partir del input del usuario
void mostrarPorCalificacion(int rating){

}

//mostrar todos los videos de cierto genero ingresado por el usuario
void mostrarPorGenero(string genre){

}

//funcion para mostrar los episodios de una serie a partir del input del usuario
void mostrarEpisodios(string serie){

}

//Funcion para mostrar las peliculas con cierta calificacion ingresada por el usuario
void mostrarPeliculasPorCalificacion(int rating){

}

int main(){
    fetchData();
    mostrarPeliculas();
    return 0;
}
