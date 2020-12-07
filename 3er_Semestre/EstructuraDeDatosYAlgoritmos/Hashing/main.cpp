//Juan Carlos Garfias Tovar, A01652138
#include "HashQ.h"
#include "HashC.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//menu
//funcion para imprimir el menu
//O(1)
void menu(){
    cout<<"1) Mostrar elementos"<<endl;
    cout<<"2) Quadratic hash"<<endl;
    cout<<"3) Chaining hash"<<endl;
    cout<<"4) Salir"<<endl;
}

int main(){
    HashQ<string> hashTableQ;//Inicializar hashes
    HashC<string> hastTableC;
    int selection;
    bool continues = true;
    char values[59] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','%','$','#','@','!','*','~'};
    string words[50];

    srand(time(0));//se hace un valor aleatorio
    for(int i = 0; i < 50; i++){
        string data = "";
        for(int j = 0; j < 2; j++){//se insetan 4 elementos en el string
            data += values[rand() % 58];//inserta valor
            data += to_string(rand() % 9);//inserta numero
        }
        hashTableQ.insert(data);//se insertan al hash
        hastTableC.insert(data);
        words[i] = data;
    }

    cout<<endl<<"---------------------------------------------------"<<endl;
    cout<<R"(
         _    _           _____ _    _ 
        | |  | |   /\    / ____| |  | |
        | |__| |  /  \  | (___ | |__| |
        |  __  | / /\ \  \___ \|  __  |
        | |  | |/ ____ \ ____) | |  | |
        |_|  |_/_/    \_\_____/|_|  |_|
    )"<<endl;
    cout<<endl;
    cout<<"Juan Carlos Garfias Tovar"<<endl;
    cout<<"---------------------------------------------------"<<endl<<endl;
    while (continues){
        menu();
        cout<<"---------------------------------------------------"<<endl<<endl;
        cout<<"Ingresar seleccion >";cin>>selection;
        switch (selection){
        case 1:
            cout << "ELEMENTOS A HASHEAR"<<endl;
            for(int i = 0; i<50; i++){
                cout<<"["<<i<<"] \t"<<words[i]<<endl;
            }
            break;
        case 2:
            cout << "HASH QUADRATIC"<<endl;
            hashTableQ.print();
            break;
        case 3:
            cout << "HASH CHAINING"<<endl;
            hastTableC.print();
            break;
        case 4:
            continues = false;
            break;
        default:
            cout<<"OPCION NO VALIDA!"<<endl;
            break;
        }
        cout<<endl<<"---------------------------------------------------"<<endl;
    }
    cout<<"HASTA LUEGO!"<<endl<<endl;

    return 0;
}
