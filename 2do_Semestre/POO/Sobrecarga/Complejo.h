//

//  Complejo.h

//  ejempComplejo

//

//  Created by Yolanda Martinez on 01/06/20.

//  Copyright © 2020 com.itesm. All rights reserved.

//
#ifndef Complejo_h
#define Complejo_h

class Complejo{
public:

    Complejo() { real = 0; imag = 0; };

    Complejo(double r, double i) { real = r; imag = i;};

    void setReal (double r) { real = r; };

    void setImag (double i) { imag = i; };

    double getReal () { return real; };

    double getImag () { return imag; };

    void muestra();

    Complejo suma (Complejo c1);

    Complejo operator+(Complejo c2);

    Complejo operator-(Complejo c2);

    Complejo operator*(Complejo c2);

    Complejo operator^(int potencia);

    Complejo operator++();

    Complejo operator--();

    bool operator==(Complejo otro);

    bool operator>(Complejo otro);
        

private:

    double real, imag;

};
 

Complejo Complejo:: suma (Complejo c1) {

    Complejo res;
    res.real = this->real + c1.real;

    res.imag = this->imag + c1.imag;
    return res;

}


void Complejo:: muestra() {

    cout << real << " + " << imag << "i ";

}


Complejo Complejo::operator+(Complejo c2) {

    int realN = this->real + c2.real;

    int imagN = this->imag + c2.imag;

    Complejo nuevo(realN, imagN);

    return nuevo;

}

Complejo Complejo::operator-(Complejo c2) {

    int realN = real - c2.real;

    int imagN = imag - c2.imag;

    Complejo nuevo(realN, imagN);

    return nuevo;

}

Complejo Complejo::operator*(Complejo c2){
    int realN = real* c2.real - imag*c2.imag;
    int imagN = real*c2.imag + imag*c2.real;

    Complejo nuevo(realN,imagN);
    return nuevo;
}

Complejo Complejo::operator^(int potencia){
    Complejo resp(1,1);

    for(int i=0;i<potencia-1;i++){
        resp = resp*(*this);
    }
    return resp;
}

Complejo Complejo::operator++() {

    this->real++;

    this->imag++;

    return *this;

}

Complejo Complejo::operator--(){
    Complejo uno(1,1);
    //objeto complejo this= objeto complejo this- objeto complejo uno
    *this = *this - uno;

    return uno;
}

bool Complejo::operator==(Complejo otro) {

    if (real == otro.real && imag == otro.imag)

        return true;

    else

        return false;

}

bool Complejo::operator>(Complejo otro){
    double normal = sqrt(pow(real,2)+pow(imag,2));
    double norma2 = sqrt(pow(otro.real,2)+pow(otro.imag,2));
    if(normal>norma2){
        return true;
    }else{
        return false;
    }
}

#endif /* Complejo_h */