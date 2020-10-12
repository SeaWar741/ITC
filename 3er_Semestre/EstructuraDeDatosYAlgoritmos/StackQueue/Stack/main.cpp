//Juan Carlos Garfias Tovar. A01652138
#include <iostream>

#include "Stack.h"

using namespace std;

//Menu
//Despliega las opciones 
void menu(){
    cout<<"=----------------="<<endl;
    cout<<"  1) pop"<<endl;
    cout<<"  2) push"<<endl;
    cout<<"  3) top"<<endl;
    cout<<"  4) getSize"<<endl;
    cout<<"  5) clear"<<endl;
    cout<<"  6) print"<<endl;
    cout<<"  7) EXIT"<<endl;
    cout<<"=----------------="<<endl;
}

//print
//Imprime el stack en un formato con delimitadores
void print(Stack<int> stacky){
    cout<<"=----------------="<<endl;
    stacky.print();
    cout<<"=----------------="<<endl;
}

//selectionMenu
//Realiza las preguntas al usuario y a partir del input
//ejecuta metodos de prueba sobre el stack
void selectionMenu(){
    Stack<int> stacky;//se inicializa el stack

    int initial;
    cout<<"Bienvenido a Stack Tester!"<<endl;
    cout<<endl<<"Ingresar cantidad de elementos iniciales: >";cin>>initial;

    for (int i = 0; i < initial; i++){//de cero al valor maximo ingresado
        stacky.push(i);//se insertan valores al stack
    }
    
    print(stacky);
    
    int selection;
    bool continues = true;
    int value;
    while (continues){//se realiza un loop hasta que el usuario decida salir y se cambia continues a false
        menu();
        cout<<"Ingresar seleccion: >";cin>>selection;//seleccion del usuario
        switch (selection){
            case 1:
                stacky.pop();
                break;
            case 2:
                cout<<"Ingresar valor: >";cin>>value;
                stacky.push(value);
                break;
            case 3:
                cout<<"Valor en top: "<<stacky.getTop()<<endl;//se obtiene el valor en top
                break;
            case 4:
                cout<<"El Stack es de size: "<<stacky.getSize()<<endl;//se obtiene el size
                break;
            case 5:
                stacky.clear();//se borran los elementos
                break;
            case 6:
                print(stacky);//se imprime el stack
                break;
            case 7:
                continues = false;//se termina el loop
                break;
            default:
                break;
        }
        print(stacky);
        
    }
    cout<<"Gracias por usar Stack Tester!"<<endl;//mensaje de despedida
    
}


int main(){
    selectionMenu();
    return 0;
}
