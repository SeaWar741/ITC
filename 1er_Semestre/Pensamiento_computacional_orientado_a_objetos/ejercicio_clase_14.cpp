#include <iostream>
using namespace std;

#include"Rectangulo.h"

int main(){
    Rectangulo rect;

    Rectangulo rect1(10,20);
    double dArea1,dArea;

    rect.setLargo(10);
    rect.setAncho(5);

    dArea = rect.calcArea();
    dArea1 = rect1.calcArea();

    cout<<"El area es "<<dArea<<endl;
    cout<<"El area del segundo rectangulo de dimensiones "<<
    rect1.getLargo()<<" X  "<<
    rect1.getAncho()<<" es "<<
    dArea1<<endl;
    cout<<endl;
    cout<<rect.imprime()<<endl;
    cout<<rect1.imprime()<<endl;

    return 0;
}
