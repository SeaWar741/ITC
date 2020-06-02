//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <ostream>
#include <vector>
#include <string>
#include "Pelicula.h"
#include "Capitulo.h"
#include "Serie.h"
using namespace std;

//vector donde se almacenan todos los videos
vector<Video> *videos(){
    ifstream file;
    file.open("data.txt");
    char type;
    while (file >> type){
    }
}

//mostrar todas las peliculas
void mostrarPeliculas(){

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
    

    return 0;
}
