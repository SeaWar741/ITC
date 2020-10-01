//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <limits>
#include "LinkedList.h"

using namespace std;

//inLimits
//verificar que esta en el rango
//o(1)
bool inLimits(int input,int min,int max){
    if(input >= min || input <= max){
        return true;
    }
    else{
        return false;
    }
}

//menu
//desplegar opciones
//o(1)
void menu(){
    cout<<"------------------------"<<endl;
    cout<<"1) addFirst"<<endl;
    cout<<"2) addLast"<<endl;
    cout<<"3) deleteData"<<endl;
    cout<<"4) deleteAt"<<endl;
    cout<<"5) updateAt"<<endl;
    cout<<"6) updateData"<<endl;
    cout<<"7) getData"<<endl;
    cout<<"8) findData"<<endl;
    cout<<"9) insertAt"<<endl;
    cout<<"10) clear"<<endl;
    cout<<"11) sort"<<endl;
    cout<<"12) duplicate"<<endl;
    cout<<"13) removeDuplicates"<<endl;
    cout<<"14) reverse"<<endl;
    cout<<"15) EXIT"<<endl;
    cout<<"------------------------"<<endl;
}


int main(){
    LinkedList<int> lista; //se crea la lista
    int num,selection,index,val;
    bool continues = true; //variable del loop

    cout<<endl<<"Bienvenid@!"<<endl;

    cout<<endl<<"Ingresar cantidad de elementos deseados >";cin>>num;cout<<endl;

    for(int i = num; i>0;i--){//ingresa la cantidad de elementos a la lista
        lista.addFirst(i);
    }

    cout<<"Lista creada!"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    lista.print();
    cout<<"--------------------------------------------------------------------"<<endl;
    
    while (continues){
        menu();
        cout<<endl<<"Ingresar seleccion >";cin>>selection;cout<<endl;
        switch (selection){
        case 1:
            cout<<endl<<"Ingresar valor a insertar >";cin>>val;cout<<endl;
            lista.addFirst(val);
            break;
        case 2:
            cout<<endl<<"Ingresar valor a insertar >";cin>>val;cout<<endl;
            lista.addLast(val);
            break;
        case 3:
            cout<<endl<<"Ingresar valor a borrar >";cin>>val;cout<<endl;
            try{
                lista.deleteData(val);
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 4:
            cout<<endl<<"Ingresar indice (1 en adelante) >";cin>>index;cout<<endl;
            if(inLimits(index,1,lista.getSize())){//si esta en el limite realizar operacion
                try{
                    lista.deleteAt(index);
                } catch(runtime_error& e){
                    cout << e.what();
                }
            }
            else{
                cout<<"INVALID"<<endl;
            }
            break;
        case 5:
            cout<<endl<<"Ingresar indice (1 en adelante) >";cin>>index;cout<<endl;
            if(inLimits(index,1,lista.getSize())){//si esta en el limite realizar operacion
                cout<<endl<<"Ingresar valor a actualizar >";cin>>val;cout<<endl;
                try{
                    lista.updateAt(index, val);
                } catch(runtime_error& e){
                    cout << e.what();
                }
            }
            else{
                cout<<"INVALID"<<endl;
            }
            break;
        case 6:
            cout<<endl<<"Ingresar valor a actualizar >";cin>>index;cout<<endl;
            cout<<endl<<"Ingresar valor deseado >";cin>>val;cout<<endl;
            try{
                    lista.updateData(index, val);
                } catch(runtime_error& e){
                    cout << e.what();
                }
            break;
        case 7:
            cout<<endl<<"Ingresar indice (1 en adelante) >";cin>>index;cout<<endl;
            if(inLimits(index,1,lista.getSize())){//si esta en el limite realizar operacion
                try{
                    cout << "Valor en el indice: " <<  lista.getData(index)<<endl;
                } catch(runtime_error& e){
                    cout << e.what();
                }
            }
            break;
        case 8:
            cout<<endl<<"Ingresar valor a encontrar >";cin>>val;cout<<endl;
            try{
                cout << "Indice del valor: " << lista.findData(val);
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 9:
            cout<<endl<<"Ingresar indice (1 en adelante) >";cin>>index;cout<<endl;
            cout<<endl<<"Ingresar valor deseado >";cin>>val;cout<<endl;
            if(inLimits(index,1,lista.getSize())){//si esta en el limite realizar operacion
                try{
                    lista.insertAt(index,val);
                } catch(runtime_error& e){
                    cout << e.what();
                }
            }
            break;
        case 10:
            lista.clear();
            break;
        case 11: //arreglar
            try{
               lista.sort();
               cout<<endl<<"Lista ordenada!"<<endl;
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 12:
            try{
               lista.duplicate();
               cout<<endl<<"Lista duplicada!"<<endl;
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 13:
            try{
               lista.removeDuplicates();
               cout<<endl<<"Duplicados removidos!"<<endl;
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 14:
            try{
               lista.reverse();
               cout<<endl<<"Lista invertida!"<<endl;
            } catch(runtime_error& e){
                cout << e.what();
            }
            break;
        case 15:
            continues = false;
            break;
        default:
            cout<<"INPUT INVALIDO"<<endl;
            break;
        }

        cout<<endl<<endl<<"LISTA:"<<endl;
        cout<<"--------------------------------------------------------------------"<<endl;
        lista.print();
        cout<<"--------------------------------------------------------------------"<<endl;
    }
    
    cout<<endl<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<"HASTA LUEGO!"<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    return 0;
}
