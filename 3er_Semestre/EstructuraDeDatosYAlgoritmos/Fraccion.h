#ifndef  Fraccion_h
#define  Fraccion_h

class Fraccion {
private:
    int numerador;
    int denominador;
    float valor;
    void reducir();
public:
    Fraccion();
    Fraccion(int numerador, int denominador);
    int getNumerador();
    int getDenominador();
    void setNumerador(int numerador);
    void setDenominador(int denominador);
    Fraccion operator+(Fraccion fraccion);
    Fraccion operator+(int numero); // opcional
    Fraccion operator-(Fraccion fraccion);
    Fraccion operator*(Fraccion fraccion);    
    Fraccion operator/(Fraccion fraccion);    
    void operator+=(Fraccion fraccion);
    void operator++(int fraccion);
    void operator--(int fraccion);
    void operator*=(Fraccion fraccion);   
    void operator-=(Fraccion fraccion);
    void operator/=(Fraccion fraccion);   
    bool operator==(Fraccion fraccion);
    bool operator>(Fraccion fraccion); 
    bool operator<(Fraccion fraccion); 
    bool operator>=(Fraccion fraccion); 
    bool operator<=(Fraccion fraccion); 
    bool operator!=(Fraccion fraccion); 
    void imprimir();
    //void operator<<();
    friend ostream& operator<<(ostream& os, Fraccion fraccion); 
};
Fraccion::Fraccion() {
    numerador = 0;
    denominador = 1;
    valor = 0;
}
Fraccion::Fraccion(int numerador, int denominador) {
    if (denominador < 0) {
        numerador *= -1;
        denominador *= -1;
    } else {
        if (denominador == 0) {
            denominador = 1;
        }
    }
    this->numerador = numerador;
    this->denominador = denominador;
    reducir();
}

int Fraccion::getNumerador() {
    return numerador;
}
int Fraccion::getDenominador() {
    return denominador;
}
void Fraccion::setNumerador(int numerador) {
    this->numerador = numerador;
    reducir();
}
void Fraccion::setDenominador(int denominador) {
    if (denominador < 0) {
        this->numerador *= -1;
        denominador *= -1;
    }
    this->denominador = denominador;
    reducir();
}


Fraccion Fraccion::operator+(int numero) {
    Fraccion resultado;
    resultado.denominador = denominador;
    resultado.numerador = numerador  + numero * denominador;        
    resultado.reducir();
    return resultado;
}

void Fraccion::operator+=(Fraccion fraccion) {
    Fraccion resultado;
    resultado = *this + fraccion;
    resultado.reducir();
    numerador = resultado.numerador;
    denominador = resultado.denominador;
    valor = resultado.valor;
}
void Fraccion::operator++(int fraccion) {
    numerador = numerador + denominador;
    reducir(); 
}
void Fraccion::operator--(int fraccion) {
    numerador = numerador - denominador;
    reducir(); 
}
Fraccion Fraccion::operator+(Fraccion fraccion) {
    Fraccion resultado;
    if (denominador == fraccion.denominador) {
        resultado.numerador = numerador + fraccion.numerador;
        resultado.denominador = denominador;
    } else {
        resultado.denominador = denominador * fraccion.denominador;
        resultado.numerador = numerador * fraccion.denominador + fraccion.numerador * denominador;        
    }
    resultado.reducir();
    return resultado;
}
Fraccion Fraccion::operator-(Fraccion fraccion) {
    Fraccion resultado;
    if (denominador == fraccion.denominador) {
        resultado.numerador = numerador - fraccion.numerador;
        resultado.denominador = denominador;
    } else {
        resultado.denominador = denominador * fraccion.denominador;
        resultado.numerador = numerador * fraccion.denominador - fraccion.numerador * denominador;        
    }
    resultado.reducir();
    return resultado;
}
Fraccion Fraccion::operator*(Fraccion fraccion) {
    Fraccion resultado;
    resultado.numerador = numerador * fraccion.numerador;
    resultado.denominador = denominador * fraccion.denominador;
    resultado.reducir();
    return resultado;
}
Fraccion Fraccion::operator/(Fraccion fraccion) {
    Fraccion resultado;
    resultado.numerador = numerador * fraccion.denominador;
    resultado.denominador = denominador * fraccion.numerador;
    resultado.reducir();
    return resultado;
}
void Fraccion::operator*=(Fraccion fraccion) {
    numerador = numerador * fraccion.numerador;
    denominador = denominador * fraccion.denominador;
    reducir();
}
/*
void Fraccion::operator++() {
    numerador = numerador + denominador;
    reducir(); 
}
*/
bool Fraccion::operator==(Fraccion fraccion) {
    if (valor == fraccion.valor) {
        return true;
    } else {
        return false;
    }
}
bool Fraccion::operator<(Fraccion fraccion) {
    if (valor < fraccion.valor) {
        return true;
    } else {
        return false;
    }
}
bool Fraccion::operator>(Fraccion fraccion) {
    if (valor > fraccion.valor) {
        return true;
    } else {
        return false;
    }
}
bool Fraccion::operator<=(Fraccion fraccion) {
    if (valor <= fraccion.valor) {
        return true;
    } else {
        return false;
    }
}
bool Fraccion::operator>=(Fraccion fraccion) {
    if (valor >= fraccion.valor) {
        return true;
    } else {
        return false;
    }
}
bool Fraccion::operator!=(Fraccion fraccion) {
    if (valor != fraccion.valor) {
        return true;
    } else {
        return false;
    }
}

void Fraccion::reducir() {
    int a = abs(numerador);
    int b = denominador;
    int c = a % b;
    while(c > 0)
    {
        a = b;
        b = c;
        c = a % b;
    }
    int gcd = b;
    numerador /= gcd;
    denominador /= gcd;
    valor = float(numerador)/float(denominador);
}

void Fraccion::imprimir() {
    cout << numerador << '/' << denominador << "=" << valor << endl;
}

ostream& operator<<(ostream& os, Fraccion fraccion) {
    os << fraccion.numerador << '/' << fraccion.denominador;
    return os;
}


#endif