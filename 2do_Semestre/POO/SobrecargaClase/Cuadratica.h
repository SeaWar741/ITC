//
//  Cuadratica.h
//  claseCuadraticaSinFriend
//
//  Created by Yolanda Martinez on 01/06/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Cuadratica_h
#define Cuadratica_h

class Cuadratica {
    
public:
    Cuadratica();
    Cuadratica(int, int, int);
      // suma X
      // resta X
      // multiplicar por un número entero X
      // sumar 1 entero a la ecuación, o sea, modifica sólo el coeficiente
      // comparar si son iguales
      // comparar si son diferentes
    Cuadratica operator+(Cuadratica);
    Cuadratica operator-(Cuadratica);
    Cuadratica operator*(int);
    Cuadratica operator++();
    bool operator==(Cuadratica);
    bool operator!=(Cuadratica);
    
    void muestra();
private:
    int coefA, coefB, coefC;
    
};

Cuadratica::Cuadratica() {
    coefA = 1;
    coefB = 1;
    coefC = 1;
}

Cuadratica::Cuadratica(int a, int b, int c) {
    coefA = a;
    coefB = b;
    coefC = c;
}

Cuadratica Cuadratica::operator+(Cuadratica ec2){
    int coef1 = coefA+ec2.coefA;
    int coef2 = coefB+ec2.coefB;
    int coef3 = coefC+ec2.coefC;
    Cuadratica nuevo(coef1,coef2,coef3);
    return nuevo;
}

Cuadratica Cuadratica::operator-(Cuadratica ec2){
    int coef1 = coefA-ec2.coefA;
    int coef2 = coefB-ec2.coefB;
    int coef3 = coefC-ec2.coefC;
    Cuadratica nuevo(coef1,coef2,coef3);
    return nuevo;
}

Cuadratica Cuadratica::operator*(int num){
    int coef1 = coefA*num;
    int coef2 = coefB*num;
    int coef3 = coefC*num;
    Cuadratica nuevo(coef1,coef2,coef3);
    return nuevo;
}

Cuadratica Cuadratica::operator++(){
    Cuadratica nuevo(coefA,coefB,(coefC++));
    return nuevo;
}

bool Cuadratica::operator==(Cuadratica ec){
    if(coefA == ec.coefA && coefB == ec.coefB && coefC == ec.coefC){
        return true;
    }else{
        return false;
    }
}

bool Cuadratica::operator!=(Cuadratica ec){
    if(coefA != ec.coefA && coefB != ec.coefB && coefC != ec.coefC){
        return true;
    }else{
        return false;
    }
}

void Cuadratica::muestra() {
    if (coefA != 0) {
        cout << coefA;
        cout << "x^2 ";
    }
    if (coefB != 0) {
        if (coefB > 0)
            cout << " + ";
        cout << coefB;
        cout << "x ";
    }
    if (coefC != 0) {
        if (coefC > 0)
            cout << " + ";
        cout << coefC << endl;
    }
}



#endif /* Cuadratica_h */
