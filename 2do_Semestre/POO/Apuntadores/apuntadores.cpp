#include <iostream>
using namespace std;
int main(){
    int *p,n;
    p =&n; //direccion de memoria de n
    *p =10;

    cout<<*p<<endl; //ambos dan 10 
    cout<<n<<endl;
    
    cout<<"Parte 2, apuntadores nulos"<<endl;
    int x,y,*q;
    p = &x;
    *p = 5;
    q = &y;
    *q = 23;
    cout<<*p<<" "<<*q<<endl;
    q = p;
    *q = 35;
    cout<<*p<<" "<<*q<<endl;
    q=NULL;
    cout<<x<<" "<<y<<endl;

    //variable dinamica
        //variable = new tipo)=;

    p = new int(20);//p apunta a ese nuevo espacio de memoria
    q = new int(); //se crea espacio pero no esta inicializado

    //delete apuntador, libera el apuntador;

    delete p; //p se queda sin espacio de memoria, se libera
    
    p = new int(14);
    q =p;
    cout<<*p<<" "<<*q<<endl;
    delete q;
    q = new int(20);

    return 0;
}

