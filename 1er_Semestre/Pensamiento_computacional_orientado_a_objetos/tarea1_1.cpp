#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void gradosf(){
    double gradosc,gradosf,increment;
    int conversions;
    bool continueask = true;
    while(continueask){
        cout<<"Ingresar temperatura inicial en grados C: ";cin>>gradosc;
        cout<<"Ingresar numero de conversiones: ";cin>>conversions;
        cout<<"Ingresar el valor del incremento: ";cin>>increment;
        if (gradosc>=0 && conversions >0 && conversions <10000 && increment>=2 && increment<=10){
            continueask = false;
        }
        else{
            cout<<"Valores no validos"<<endl;
        }
    }
    cout<<"\nConversion de grados Celsius a Farenheit"<<endl;
    cout<<"FARENHEIT        CELSIUS"<<endl;
    for (int i = 0; i < conversions; i++){
        gradosf = ((9.0/5.0)*gradosc)+32;  
        cout<<gradosf;
        cout.width(17);cout<<gradosc<<endl;
        gradosc+=increment;
    }

}

int seriearitmetica(){
    int a,d,n,numb,sum;
    a = 1;
    d = 3;
    n = 25;
    numb = a;
    for(int i=0;i<n;i++){
        numb = 3*i+a;
        cout<< "Termino "<< i+1 <<": "<<numb<<endl;
    }
    sum = ((a+numb)/2)*n;
    cout<<"\nValor total de la serie: > ";  
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
    cout<< "\n-*-*-*-*-*-*-*-*-*-*=Menu=*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<< "Selecciona una opcion:"<<endl;
    cout<< "a) Conversion Celsius Farenheit"<<endl;
    cout<< "b) Serie numerica"<<endl;
    cout<< "c) Media geometrica y armonica"<<endl;
    cout<< "d) Cerrar programa\n"<<endl;
}

int main(){
    char option;
    bool continuem = true;
    cout<<"Bienvenid@ a la tarea de estatutos condicionales"<<endl;
    while(continuem){
        menu();
        cout<<"> ";cin>>option;
        option = tolower(option);
        switch (option){
            case 'a':
                gradosf();
                break;
            case 'b':
                cout<< seriearitmetica()<<endl;
                break;
            case 'c':
                mediageometricaarmonica();
                break;
            case 'd':
                cout<<"\nGracias por utilizar la herramienta!"<<endl;
                continuem = false;
                break;
            default:
                cout<<"\nNo es una opcion valida, intenta de nuevo\n"<<endl;
                break;
        }    
    }
    return 0;
}