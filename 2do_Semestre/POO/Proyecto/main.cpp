//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <typeinfo>
#include <stdlib.h>
#include <random>

#include "Pelicula.h"
#include "Capitulo.h"
#include "Serie.h"

using namespace std;

vector<Video *> videos; //vector de apuntadores para videos(peliculas/capitulos)
vector<Serie *> series; //vector de apuntadores para series

vector<int> indexP; //indices de peliculas
vector<int> indexC; //indices de capitulos

int cPeliculas = 0; //cantidad de peliculas
int cCapitulos = 0; //cantidad de capitulos
int cSeries = 0;    //cantidad de series

/*FUNCIONES HELPER */
bool to_bool(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::istringstream is(str);
    bool b;
    is >> std::boolalpha >> b;
    return b;
}

//busqueda adelante/atras/contraccion
int search(string arr[], int n, string x) { 
    int front = 0, back = n - 1; 
    while (front <= back) { 
        if (arr[front] == x){
            return front;
        }
        else if(arr[back] == x){
            return back;
        } 
        front++; 
        back--; 
    } 
    return -1; 
} 

//obtener posiciones de los capitulos de la serie
vector<int> positionsSerie(string title){
    vector<int> pos;
    int front = 0, back = videos.size() - 1; 
    while (front <= back) { 
        if (videos[front]->getTitle() == title){
            pos.push_back(front);
        }
        else if(videos[back]->getTitle() == title){
            pos.push_back(back);
        } 
        front++; 
        back--; 
    } 
    return pos;
}

//funcion para titulos de menus
void textTitle(string txt){
    char esc_char = 27; 
    string color3 = "\x1B[31m";
    string color4 = "\033[0m";
    cout <<color3<< esc_char << "[1m" <<txt <<esc_char <<"[0m" <<color4<<endl;
}
//funcion para numeros de menus
void numb(string txt){
    char esc_char = 27; 
    string color3 = "\x1B[31m";
    string color4 = "\033[0m";
    cout <<color3<< esc_char << "[1m" <<txt <<esc_char <<"[0m" <<color4;
}
//funcion para bold
void bold(string txt){
    char esc_char = 27; 
    cout << esc_char << "[1m" <<txt <<esc_char <<"[0m";
}


/*LECTURA DE DATOS */
//leer datos de los archivos TSV 👍
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

    //variables capitulos
    string stitle;//titulo de la serie a la que pertenece
    int season;//temporada
    int chapter;//capitulo
    string airDate;//fecha de estreno
    string chapterDescription;//descripcion del capitulo

    //variables series
    string network;//cadena o televisora
    string runtime;//duracion de la serie en años
    vector<Video *> capitulos;

    //Movies
    ifstream myFile;
    myFile.open("./Data/movies.txt");

    int counter = 0;
    
    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //id	adult	language	duration	title	description	genre	rating	companies	companies	companies	releasedate
        switch(counter){
            case 0:
                break;
            case 1:
                id = stoi(line);
                indexP.push_back(id);
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
                releaseDate = line.substr(0, line.size()-1);;
                videos.push_back(new Pelicula(id,adult,language,duration,title,description,genre,rating,productionCompanies,releaseDate));
                productionCompanies.clear();
                cPeliculas++;
                counter = 0;
                break;
            default:
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
            case 0:
                break;
            case 1:
                id = stoi(line);
                indexC.push_back(id);
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
                chapterDescription = line.substr(0, line.size()-1);
                videos.push_back(new Capitulo(stitle,id,adult,language,duration,title,description,genre,rating,season,chapter,airDate,chapterDescription));
                cCapitulos++;
                counter = 0;
                break;
            default:
                break;
        }
        counter++;
    }
    myFile.close();

    //Series-----------------------------------------------------------------------------------------------------
    myFile.open("./Data/series.txt");
    counter = 0;

    while(myFile.good()){
        string line;
        getline(myFile,line,'\t');
        //cout<<line<<endl;
        //tipo	id	title	network	rating	runtime
        switch (counter){
            case 0:
                break;
            case 1:
                id = stoi(line);
                break;
            case 2:
                title = line;
                break;
            case 3:
                network = line;
                break;
            case 4:
                rating = stof(line);
                break;
            case 5:
                runtime = line.substr(0, line.size()-1);
                for(auto i: indexC){
                    if(Capitulo* v = dynamic_cast<Capitulo*>(videos[i-1])) {
                        //se hace sobre carga con un cast dinamico para pasar de clase base a clase hija capitulo
                        if(v->getSTitle() == title){
                            capitulos.push_back(videos[i-1]);
                        }
                    }
                }
                series.push_back(new Serie(id,title,network,runtime,rating,capitulos));
                cSeries++;
                capitulos.clear();
                counter = 0;
            default:
                break;
        }
        counter++;
    }
    myFile.close();
}


/*REQUISITOS MINIMOS*/
//mostrar todas las peliculas👍🟩
void mostrarPeliculas(){
    for(auto i: indexP){
        videos[i-1]->mostrar();
        cout<<endl;
    }
}

//mostrar todas las series 👍🟩
void mostrarSeries(){
    for(int i = 0; i<series.size();i++){
        series[i]->mostrar();
        cout<<endl;
    }
}

//mostrar videos por calificacion a partir del input del usuario👍🟩
void mostrarPorCalificacion(float rating){
    for(int i = 0;i<videos.size();i++){
        if(videos[i]->getRating() >= rating){
            videos[i]->mostrar();
            cout<<endl;
        }
    }
}

//mostrar todos los videos de cierto genero ingresado por el usuario👍🟩
void mostrarPorGenero(string genre){
    for(int i = 0; i <videos.size();i++){
        if(videos[i]->getGenre() == genre){
            videos[i]->mostrar();
            cout<<endl;
        }
    }
}

//funcion para mostrar los episodios de una serie a partir del input del usuario👍🟩
void mostrarEpisodios(string serie){
    for(auto i: series){
        if(i->getTitle() == serie){
            for(auto i: i->getCapitulos()){
                i->mostrar();
                cout<<endl;
            }
        }
    }
}

//Funcion para mostrar las peliculas con cierta calificacion ingresada por el usuario  👍🟩
void mostrarPeliculasPorCalificacion(float rating){
    for(int i = 0;i<videos.size();i++){
        if(find(indexP.begin(), indexP.end(),i+1)!= indexP.end()){
            if(videos[i]->getRating()>=rating){
                videos[i]->mostrar();
                cout<<endl;
            }
        }
    }
}


/*FUNCIONES EXTRA*/

//busquedas
//Buscar un video en general 👍 
void searchVideo(string title){
    for(auto i:videos){
        if(i->getTitle() == title){
            i->mostrar();
            cout<<endl;
        }
    }
}

//Buscar una pelicula en especifico 👍🟩
void searchPelicula(string title){
    for(auto i: indexP){
        if(videos[i-1]->getTitle() == title){
            videos[i-1]->mostrar();
            cout<<endl;
        }
    }
}

//buscar una serie en especifico 👍🟩
void searchSerie(string title){
    for(auto i: series){
        if(i->getTitle() == title){
            i->mostrar();
             cout<<endl;
        }
    }
}

//mostrar series por calificacion 👍🟩
void mostrarSeriesPorCalificacion(float rating){
    for(auto i:series){
        if(i->getRating()>=rating){
            i->mostrar();
            cout<<endl;
        }
    }
}

//mostrar capitulos por calificacion👍🟩
void mostrarCapitulosPorCalificacion(float rating){
    for(int i = 0;i<videos.size();i++){
        if(videos[i]->getRating() >= rating){
            videos[i]->mostrar();
            cout<<endl;
        }
    }
}

//mostrar peliculas por genero 👍🟩
void mostrarPeliculasPorGenero(string genre){
    for(auto i: indexP){
        if(videos[i-1]->getGenre() == genre){
            videos[i-1]->mostrar();
            cout<<endl;
        }
    }
}

//mostrar capitulos por genero 👍🟩
void mostrarCapitulosPorGenero(string genre){
    for(auto i: indexC){
        if(videos[i-1]->getGenre() == genre){
            videos[i-1]->mostrar();
            cout<<endl;
        }
    }
}

//mostrar todos los videos 👍🟩
void mostrarVideos(){
    for(auto i: videos){
        i->mostrar();
    }
}

//Extras
//mostrar una recomendacion de peliculas/series de alta calidad(rating)👍🟩
void mostrarRecomendacion(){
    vector<int> highRating;
    for(int i = 0;i<videos.size();i++){
        if(videos[i]->getRating() >= 8.5){
            highRating.push_back(videos[i]->getId());
        }
    }
    int num = rand() % (highRating.size()-1) + 1;
    videos[highRating[num]]->mostrar();
    cout<<endl;
}

//mostrar una recomendacion aleatoria👍🟩
void mostrarAleatoria(){
    int num = rand() % (videos.size()-1) + 1;
    videos[num]->mostrar();
    cout<<endl;
}

//mensaje de bienvenida 👍
void home(){
std::cout<<"\x1B[33m" <<R"(

 ██████╗  █████╗ ██████╗ ███████╗██╗     ██╗██╗  ██╗
██╔════╝ ██╔══██╗██╔══██╗██╔════╝██║     ██║╚██╗██╔╝
██║  ███╗███████║██████╔╝█████╗  ██║     ██║ ╚███╔╝ 
██║   ██║██╔══██║██╔══██╗██╔══╝  ██║     ██║ ██╔██╗ 
╚██████╔╝██║  ██║██║  ██║██║     ███████╗██║██╔╝ ██╗
 ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝     ╚══════╝╚═╝╚═╝  ╚═╝
                                                    
)"<<"\033[0m" << '\n';   
textTitle("------------------------------------------------------------------------------------");cout<<endl;
textTitle("Bienvenid@ a Garflix, la mejor plataforma de streaming gratuita!");cout<<endl;
bold("Cantidad de Peliculas: ");cout<<cPeliculas<<endl;
bold("Cantidad de Series: ");cout<<cSeries<<endl;
bold("Cantidad de capitulos: ");cout<<cCapitulos<<endl;
textTitle("------------------------------------------------------------------------------------");cout<<endl;
}


void bye(){
    cout<<endl<<endl<<endl<<endl;
    textTitle("----------------------------------------------");cout<<endl;
    textTitle("Hasta Luego!");cout<<endl;
    textTitle("----------------------------------------------");cout<<endl;
    cout<<endl<<endl<<endl<<endl;
}



/*MENU DE OPERACION*/
//Menu de peliculas
void menuPelis(){
    bool continue1 = true;
    int selection1;
    float rating;
    string query;
    while (continue1){
        textTitle("-------=Menu Peliculas=--------");
        numb("1)");cout<<"Buscar una pelicula especifica"<<endl;
        numb("2)");cout<<"Ver catalogo de peliculas"<<endl;
        numb("3)");cout<<"Mostrar peliculas por calificacion"<<endl;
        numb("4)");cout<<"Buscar peliculas por genero"<<endl;
        numb("0)");cout<<"Regresar a menu principal"<<endl<<endl;
        bold("Ingresar seleccion >");cin>>selection1;
        switch (selection1){
        case 0:
            continue1 = false;
            break;
        case 1:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Titulo de la pelicula: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            searchPelicula(query);
            cout<<endl;
            break;
        case 2:
            cout<<endl<<endl;
            textTitle("-------=Catalogo de peliculas=--------");cout<<endl;
            mostrarPeliculas();
            cout<<endl;
            break;
        case 3:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Calificacion minima: >");cin>>rating;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarPeliculasPorCalificacion(rating);
            cout<<endl;
            break;
        case 4:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Genero: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarPeliculasPorGenero(query);
            cout<<endl;
            break;
        default:
            cout<<endl<<endl;
            textTitle("-------|||¡¡OPCION NO VALIDA!!|||-------");
            cout<<endl<<endl;
            break;
        }
    }    
}

//menu series
void menuSeries(){
    bool continue1 = true;
    int selection1;
    float rating;
    string query;
    while (continue1){
        textTitle("-------=Menu Series=--------");
        numb("1)");cout<<"Buscar una serie especifica"<<endl;
        numb("2)");cout<<"Ver catalogo de Series"<<endl;
        numb("3)");cout<<"Mostrar series por calificacion"<<endl;
        numb("4)");cout<<"Mostrar capitulos por calificacion"<<endl;
        numb("5)");cout<<"Mostrar capitulos de una serie"<<endl;
        numb("6)");cout<<"Buscar capitulos por genero"<<endl;
        numb("0)");cout<<"Regresar a menu principal"<<endl<<endl;
        bold("Ingresar seleccion >");cin>>selection1;
        switch (selection1){
        case 0:
            continue1 = false;
            break;
        case 1:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Titulo de la serie: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            searchSerie(query);
            cout<<endl;
            break;
        case 2:
            cout<<endl<<endl;
            textTitle("-------=Catalogo de series=--------");cout<<endl;
            mostrarSeries();
            cout<<endl;
            break;
        case 3:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Calificacion minima: >");cin>>rating;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarSeriesPorCalificacion(rating);
            cout<<endl;
            break;
        case 4:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Calificacion minima: >");cin>>rating;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarCapitulosPorCalificacion(rating);
            cout<<endl;
            break;
         case 5:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Titulo de la serie: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarEpisodios(query);
            cout<<endl;
            break;   
        case 6:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Genero: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarCapitulosPorGenero(query);
            cout<<endl;
            break;
        default:
            cout<<endl<<endl;
            textTitle("-------|||¡¡OPCION NO VALIDA!!|||-------");
            cout<<endl<<endl;
            break;
        }
    }    
}

void menuVideos(){
   bool continue1 = true;
    int selection1;
    float rating;
    string query;
    while (continue1){
        textTitle("-------=Menu Videos=--------");
        numb("1)");cout<<"Buscar un video especifico"<<endl;
        numb("2)");cout<<"Ver catalogo de videos"<<endl;
        numb("3)");cout<<"Mostrar videos por calificacion"<<endl;
        numb("4)");cout<<"Buscar videos por genero"<<endl;
        numb("0)");cout<<"Regresar a menu principal"<<endl<<endl;
        bold("Ingresar seleccion >");cin>>selection1;
        switch (selection1){
        case 0:
            continue1 = false;
            break;
        case 1:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Titulo del video: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            searchVideo(query);
            cout<<endl;
            break;
        case 2:
            cout<<endl<<endl;
            textTitle("-------=Catalogo de videos=--------");cout<<endl;
            mostrarVideos();
            cout<<endl;
            break;
        case 3:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Calificacion minima: >");cin>>rating;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarPorCalificacion(rating);
            cout<<endl;
            break;
        case 4:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Genero: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            mostrarPorGenero(query);
            cout<<endl;
            break;
        default:
            cout<<endl<<endl;
            textTitle("-------|||¡¡OPCION NO VALIDA!!|||-------");
            cout<<endl<<endl;
            break;
        }
    }     
}

//Menu principal
void menu(){
    bool continue1 = true;
    int selection1;
    string query;
    while (continue1){    
        textTitle("-------=Menu Principal=--------");
        numb("1)");cout<<"Busqueda"<<endl;
        numb("2)");cout<<"Recomendacion aleatoria"<<endl;
        numb("3)");cout<<"Recomendacion de los expertos"<<endl;
        numb("4)");cout<<"Peliculas"<<endl;
        numb("5)");cout<<"Series"<<endl;
        numb("6)");cout<<"Todos los videos"<<endl;
        numb("0)");cout<<"Salir"<<endl<<endl;
        bold("Ingresar seleccion >");cin>>selection1;
        switch (selection1){
        case 0:
            bye();
            continue1 = false;
            break;
        case 1:
            cout<<endl<<endl;
            bold("|---------------------------------------|");cout<<endl;
            bold("|Titulo del video: >");cin>>query;cout<<endl;
            bold("|---------------------------------------|");cout<<endl<<endl<<endl;
            textTitle("-------=Resultados de busqueda=--------");cout<<endl;
            searchVideo(query);
            cout<<endl;
            break;
        case 2:
            cout<<endl<<endl;
            textTitle("-------=Nuestra recomendacion=--------");cout<<endl;
            mostrarAleatoria();
            cout<<endl;
            break;
        case 3:
            cout<<endl<<endl;
            textTitle("-------=Recomendacion de expertos=--------");cout<<endl;
            mostrarRecomendacion();
            cout<<endl;
            break;
        case 4:
            cout<<endl<<endl;
            menuPelis();
            break;
        case 5:
            cout<<endl<<endl;
            menuSeries();
            break;
        case 6:
            cout<<endl<<endl;
            menuVideos();
            break;
        default:
            cout<<endl<<endl;
            textTitle("-------|||¡¡OPCION NO VALIDA!!|||-------");
            cout<<endl<<endl;
            break;
        }
    }
}


int main(){
    srand(time(NULL)); //numeros random constantemente
    fetchData();//se hace un fetch a los datos de los txt
    home(); //mensaje de bienvenida
    cout<<endl;
    menu();//Menu
    return 0;
}
