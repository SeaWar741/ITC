//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 10/11/2019
//| Descripcion: Programa para jugar loteria con imagenes
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <string>
#include <fstream>
using namespace std;

//Nombre:PrintA
//Descripcion: Metodo para imprimir array de ints
//Entrada:
//          array de dimension n
//Salida:
//          imprime n numero de elementos
void PrintA(int arry[]){ 
    cout<<"["; //imprime corchetes entre todos los elementos
    for (int i=0; i<54; i++) {//formato estilo array to string
        if(i != 53){
            cout<<arry[i]<<",";
        }
        else{ //si el elemento es el ultimo omite la coma
            cout<<arry[i];
        }
    }
    cout<<"]"<<endl;
}

//Nombre:PrintA
//Descripcion: Metodo para imprimir array de strings
//Entrada:
//          array de dimension n
//Salida:
//          imprime n numero de elementos
void PrintA(string arry[]){
    cout<<"[";//imprime corchetes entre todos los elementos
    for (int i=0; i<54; i++) { //formato estilo array to string
        if(i != 53){
            cout<<arry[i]<<",";
        }
        else{//si el elemento es el ultimo omite la coma
            cout<<arry[i];
        }
    }
    cout<<"]"<<endl;
}

//Nombre:Barajea
//Descripcion: Metodo para hacer suffle a los elementos de un array
//Entrada:
//          array de dimension n
//Salida:
//          hace suffle al array de manera aleatoria mezclando los elementos
void Barajea(int card[]){
    int n =54;
    int counter = 0;
    srand(time(0));   //se inicializa el random
    for (int i=0; i<54; i++) { //se llena el array con numeros
        card[i] = i;
    }
    //cout<<"Array mezclar"<<endl;
    //PrintA(card);    
    for (int i = n-1; i > 0; i--){ //se hace un randomize y suffle al array
        int j =rand()%(i+1);
        swap(card[i],card[j]); //hace un swap entre los indices
    }
    //cout<<"ya mezclado"<<endl;
    //PrintA(card);
}

//Nombre:openimage
//Descripcion: Metodo para abrir imagen de carta
//Entrada:
//          nombre de la carta
//Salida:
//          ejecuta un comando en cmd para abrir la imagen desde el path
void Openimage(string name){
    name = name.substr(1, name.size() - 2);
    string str = "\"./loteria_img/"+name+".jpg\"";
    const char *cstr = str.c_str(); //se convierte a un char para ser utilizado por CMD
    system(cstr); //ejecuta el comando de sistema
}

int main(){
    int card[54]; //se inicializa un array de 54 elementos para las cartas
    string carta,jugar,jugar2; //variables para nombre de carta, input de continuacion 1 e input de continuacion 2
    bool continueg = false; //variable controladora del loop 
    string nombres_cartas[] = {"'El gallo'", "'El diablito'", "'La dama'", "'El catrin'", "'El paraguas'", "'La sirena'", "'La escalera'", "'La botella'", "'El barril'", "'El arbol'", "'El melon'", "'El valiente'", "'El gorrito'",
    "'La muerte'", "'La pera'", "'La bandera'", "'El bandolon'", "'El violoncello'", "'La garza'", 
    "'El pajaro'", "'La mano'", "'La bota'", "'La luna'", "'El cotorro'", "'El borracho'", "'El negrito'",
    "'El corazon'", "'La sandia'", "'El tambor'", "'El camaron'", "'Las jaras'", "'El musico'", "'La arana'", "'El soldado'", "'La estrella'", "'El cazo'", "'El mundo'", "'El apache'", "'El nopal'",
    "'El alacran'", "'La rosa'", "'La calavera'", "'La campana'", "'El cantarito'", "'El venado'", "'El sol'", "'La corona'", "'La chalupa'", "'El pino'", "'El pescado'", "'La palma'", "'La maceta'",
    "'El arpa'", "'La rana'"};
    cout<<"\n-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ a loteria=-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<<"Las cartas:"<<endl;
    PrintA(nombres_cartas);
    cout<<"\nQuieres jugar? (si/no) >";cin>>jugar;cout<<endl;
    std::for_each(jugar.begin(), jugar.end(), [](char & c) { //se convierte el input del usuario a minusculas
		c = ::tolower(c);
	});
    Barajea(card); //se barajea(suffle) a las cartas 
    while(jugar !="no"){ //mientras que el jugador no escriba no, el juego continua
        for (int i = 0; i < 54; i++){ //loop para las 54 cartas
            carta =nombres_cartas[card[i]]; 
            cout<<carta<<endl;//se imprime la carta
            Openimage(carta); //se llama la carta
            if(i < 53){
                cout<<"\nPara terminar esta jugada teclea <loteria> y para continuar <continuar>: >";cin>>jugar2;cout<<endl;
                std::for_each(jugar2.begin(), jugar2.end(), [](char & c) { //se convierte a minusculas
                    c = ::tolower(c);
                });
                if (jugar2 == "loteria"){ //si escribe loteria el contador llega a 54, se termina el loop y el continueg pasa a falso
                    i = 54;
                    continueg = false;
                }
            }
            else{
                cout<<"*-*-*-*-*-*-*-*-*-*-*-*-*-=Termino la baraja=-*-*-*-*-*-*-*-*-*-*-*-*-*"<<endl; //si se acaban las cartas se imprime esta opcion
            }
        }
        cout<<"\nQuieres volver a jugar? (si/no) >";cin>>jugar;cout<<endl; //se pregunta si se quiere continuar
            std::for_each(jugar.begin(), jugar.end(), [](char & c) { //el input pasa a minusculas
		    c = ::tolower(c);
	    }); 
        if (jugar == "no"){ //si el jugador ingresa no se terminna el loop
            continueg = false;
        }
        else{ //si continua el juego, se vuelve a barajear, se imprime el array con las posiciones 
            Barajea(card);
            PrintA(card);
            cout<<"\n";   
        }
        
    }
    cout<<"\nHasta luego!"<<endl; //se imprime una despedida y termina el programa
    return 0;
}
