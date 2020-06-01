//

//  main.cpp

//  ejempComplejo

//

//  Created by Yolanda Martinez on 01/06/20.

//  Copyright © 2020 com.itesm. All rights reserved.

//

#include <iostream>
#include <cmath>
using namespace std;
#include "Complejo.h"

int main() {

    Complejo c1(10, 20), c2(5, 3), c3, c4;

    cout << "valores originales "<< endl;

    cout << "C1 = ";

    c1.muestra();

    cout << endl;

    cout << "C2 = ";

    c2.muestra();

    cout << endl;

    cout << "C3 = ";

    c3.muestra();

    cout << endl;

    cout << "C4 = ";

    c4.muestra();

    cout << endl;

    cout << endl;

    
    if (c3 == c4)

        cout << "c3 y c4 son iguales"<< endl;
    if (c3 > c4)

        cout << "c3 es mayor a c4"<< endl;

    cout << endl;

    cout << "La suma de c1 + c2 " << endl;

    

    c3 = c1 + c2;

    cout << "C1 = ";

    c1.muestra();

    cout << endl;

    cout << "C2 = ";

    c2.muestra();

    cout << endl;

    cout << "C3 = ";

    c3.muestra();

    cout << endl;

    c3 = c1*c2;

    cout<<endl;

    cout<<"La multiplicacion de C1*C2 = C3 = ";
    
    c3.muestra();
    
    cout<<endl;

    //prueba del ^
    c4 = c1^2;
    
    cout<<"C1 = *";
    
    c1.muestra();
    
    cout<<endl;
    
    cout<<"C4 = *";
    
    c4.muestra();
    
    cout<<endl;



    // prueba del ++

    cout << endl;

    cout << "prueba del ++" << endl;

    ++c2;

    c3 = ++c3;

    cout << "C2 = ";

    c2.muestra();

    cout << endl;

    cout << "C3 = ";

    c3.muestra();

    cout << endl;

    // prueba del ++

    cout << endl;

    cout << "prueba del --" << endl;

    --c2;

    c3 = --c1;

    cout << "C2 = ";

    c2.muestra();

    cout << endl;

    cout << "C3 = ";

    c3.muestra();

    cout << endl;

    return 0;

}