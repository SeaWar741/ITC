#include <iostream>
#include <string>
#include <math.h>
using namespace std;

double gradosf(){
    double gradosc,gradosf;
    bool continueask = true;
    while (continueask == true){
        cout<< "Ingresar temperatura en grados C: ";cin>>gradosc;
        if (gradosc>=0){
            gradosf = ((9.0/5.0)*gradosc)+32;
            continueask = false;
        }
        else{
            cout<<"No se pudo convertir\nIngresar otro valor"<<endl;
        }
    }
    return gradosf;
}

int seriearitmetica(){ //Arreglar
    int a,d,n,numb,sum;
    a = 1;
    d = 3;
    n = 25;
    numb = a;
    for(int i=0;i<n;i++){
        cout<< numb << " ";
        numb +=d;
        sum +=numb;
    }
    cout<<"\nEl termino i es: > ";  
    return sum;
}

void mediageometricaarmonica(){
    double mgeometrica,marmonica,numb;
    double counter = 0;
    bool continueop = true;
    mgeometrica = 1;
    cout<<"Ingresar valores, en caso de desear salir escribir 0"<<endl;
    while(continueop){
        cout<<"Ingresar numero: >";cin>>numb;
        if (numb !=0){
            mgeometrica = mgeometrica *numb;
            marmonica += (1.0/numb);
            counter++;    
        }
        else{
            continueop = false;
        }
    }
    mgeometrica = pow(mgeometrica,(double)(1.0/counter));
    marmonica = counter/marmonica;
    cout<<"\nEl resultado de la media geometrica es: > ";
    cout<<mgeometrica<<endl;
    cout<<"El resultado de la media armonica es: > ";
    cout<<marmonica<<endl;
}

void menu(){
    cout<< "-*-*-*-*-*-*-*-*-*-*=Menu=*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<< "Selecciona una opcion:"<<endl;
    cout<< "a) Conversion Celsius Farenheit"<<endl;
    cout<< "b) Serie numerica"<<endl;
    cout<< "c) Medias geometrica armonica"<<endl;
    cout<< "d) Cerrar programa\n"<<endl;
}

int main(){
    char option;
    cout<<"Bienvenid@ a la tarea de estatutos condicionales"<<endl;
    menu();
    cout<<"> ";cin>>option;
    option = tolower(option);

    switch (option){
        case 'a':
            cout<< "La temperatura en grados F es: >";
            cout<< gradosf()<<endl;
            break;
        case 'b':
            cout<< seriearitmetica()<<endl;
            break;
        case 'c':
            mediageometricaarmonica();
            break;
        case 'd':
            break;
        default:
            break;
    }    
    return 0;
}
