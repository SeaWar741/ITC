//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 06/11/2019
//| Descripcion: Programa con menu para conversiones de grados c a f en incrementos,obtencion de serie aritmetica(con sumatoria),
//|              media geometrica y armonica de un conjunto de numeros dados
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//Nombre:Gradosf
//Descripcion: Metodo para realizar una conversion de grados c a f con una temperatura inicial
//              numero de incrementos y valor de incrementos
//Entrada:
//          Ninguna como parametro. Dentro de el se asignan las variables de temperatura inicial, numero de incrementos
//          el valor del incremento
//Salida:
//          imprime n numero de conversiones
void Gradosf(){
    double gradosc,gradosf,increment;
    int conversions;
    bool continueask = true;
    while(continueask){ //El programa preguntara los valores mientras no sean validos los valores
        cout<<"Ingresar temperatura inicial en grados C (Solo positivos): ";cin>>gradosc;
        cout<<"Ingresar numero de conversiones (Menor a 10000): ";cin>>conversions;
        cout<<"Ingresar el valor del incremento (Entre 2 y 10): ";cin>>increment;
        if (gradosc>=0 && conversions >0 && conversions <10000 && increment>=2 && increment<=10){
            continueask = false; //se rompera el loop al cumplir con las condiciones
        }
        else{
            cout<<"Valores no validos"<<endl;
        }
    }
    cout<<"\nConversion de grados Celsius a Farenheit"<<endl;
    cout<<"FARENHEIT        CELSIUS"<<endl;
    for (int i = 0; i < conversions; i++){ //Para cada valor en el incremento se realizara la conversion
        gradosf = ((9.0/5.0)*gradosc)+32;  
        cout<<gradosf;
        cout.width(17);cout<<gradosc<<endl; //se imprime en formato de 17 espacios para continuidad
        gradosc+=increment; //se realiza el incremento
    }

}
//Nombre: Seriearitmetica
//Descripcion: Metodo para obtener la serie aritmetica a partir de el valor inicial(1),diferencia entre valores(3) y posicion/numero(25) 
//Entrada:
//      Ninguna
//Salida:
//      Imprime todos los terminos de la serie hasta el 25 y la sumatoria/valor total de la serie, regresa el valor de la suma
int Seriearitmetica(){
    int a,d,n,numb,sum;
    a = 1;
    d = 3;
    n = 25;
    numb = a;
    for(int i=0;i<n;i++){ //se realiza un ciclo para obtener cada termino
        numb = 3*i+a;
        cout<< "Termino "<< i+1 <<": "<<numb<<endl; 
    }
    sum = ((a+numb)/2)*n; //se realiza la operacion para calcular la suma
    cout<<"\nValor total de la serie: > ";  
    return sum;
}

//Nombre: Mediageometricaarmonica
//Descripcion: Metodo para obtener la media geometrica y armonica de un conjunto de numeros
//Entrada:
//      Ninguna como parametro. Dentro del metodo se pide ingresar numeros o 0 para terminar de anexar
//Salida:
//      Imprime los valores de media geometrica y media armonica
void Mediageometricaarmonica(){
    double mgeometrica,marmonica,numb;
    double counter = 0;
    bool continueop = true;
    mgeometrica = 1;
    cout<<"Ingresar valores, en caso de desear salir escribir 0"<<endl;
    while(continueop){ //loop que se rompera cuando el usuario escriba 0
        cout<<"Ingresar numero: >";cin>>numb;
        if (numb !=0){
            mgeometrica = mgeometrica *numb; //se realiza el calculo de la geometrica
            marmonica += (1.0/numb); //se reañoza el calculo de la armonica
            counter++;    
        }
        else{
            continueop = false; //se rompe cuando escribe 0
        }
    }
    if(counter>0){ //se imprimiran los valores si el contador es mayor a 0 es decir que si el usuario escribe 0 no se calcula nada
        mgeometrica = pow(mgeometrica,(double)(1.0/counter));  //formula geometrica
        marmonica = counter/marmonica; //formula armonica
        cout<<"\nEl resultado de la media geometrica es: > ";
        cout<<mgeometrica<<endl;
        cout<<"El resultado de la media armonica es: > ";
        cout<<marmonica<<endl;
    }
    else{
        cout<<"\nCero es un numero invalido"<<endl; //en caso de que solo escriba 0 el usuario
    }
}

//Nombre: Menu
//Descripcion: Metodo para desplegar el menu de opciones
//Entrada:
//      Ninguna
//Salida:
//      Imprime las opciones a seleccionar
void Menu(){
    cout<< "\n-*-*-*-*-*-*-*-*-*-*=Menu=*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<< "Selecciona una opcion:"<<endl;
    cout<< "a) Conversion Celsius Farenheit"<<endl;
    cout<< "b) Serie numerica"<<endl;
    cout<< "c) Media geometrica y armonica"<<endl;
    cout<< "d) Cerrar programa\n"<<endl;
}

//Nombre: Main
//Descripcion: Metodo principal, llama a los metodos o cierra el programa hasta que el usuario lo desee
//Entrada:
//      Ningun parametro. Dentro del main se pide que el usuario ingrese un caracter(char) como opcion de menu
//Salida:
//      Llama a los metodos o cierra el programa
int main(){
    char option;
    bool continuem = true;
    cout<<"Bienvenid@ a la tarea de estatutos condicionales"<<endl;
    while(continuem){ //mientras que el usuario no seleccione la opcion de salir
        Menu(); //lamada al metodo de menu (desplegar menu)
        cout<<"> ";cin>>option;
        option = tolower(option); //se pasa el char a lowercase para evitar problemas de compatibilidad
        switch (option){ //switch para cada opcion del menu
            case 'a':
                Gradosf(); //llamada de metodo
                break;
            case 'b':
                cout<< Seriearitmetica()<<endl; //llamada de metodo e impresion del valor
                break;
            case 'c':
                Mediageometricaarmonica(); //llamada de metodo
                break;
            case 'd':
                cout<<"\nGracias por utilizar la herramienta!"<<endl;
                continuem = false; //Se termina el ciclo, deja de preguntar opciones del menu
                break;
            default:
                cout<<"\nNo es una opcion valida, intenta de nuevo\n"<<endl; //para cualquier otro caso
                break;
        }    
    }
    return 0; //termina el programa
}