#include <iostream>
#include <cmath>
using namespace std;

#include "Cuadratica.h"

int main() {
    int a, b, c;
    char opcion;
    
    Cuadratica ec1(5,3,2), ecRes;
    Cuadratica ec3 = ec1;    // ec1 y ec3 tienen los mismos valores.
    
    //cout << "Teclea los coeficientes para la segunda ecuación" << endl;
    cin >> a >> b >> c;
    //cout << "Opcion: ";
    cin >> opcion;
    
    Cuadratica ec2(a, b, c);
    
    switch (opcion) {
        case 'a':
            /*********************************/
            cout << endl;
            cout << "=== Suma de Ecuaciónes 1 y 2. Deja el resultado en ecRes" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 2 :";
            ec2.muestra();
            // Agrega la sobrecarga para hacer la suma
            ec1 = ec1+ec2;
            
            
            
            cout << "Resultado  :";
            ecRes.muestra();
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 2 :";
            ec2.muestra();
            cout << endl;
            break;
            
        case 'b':
            /*********************************/
            cout << endl;
            cout << "=== Resta de Ecuaciónes 1 y 2. Deja el resultado en ecRes" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 2 :" ;
            ec2.muestra();
            // Agrega la sobrecarga para hacer la resta
            ec1 = ec1-ec2;
            
            
            
            cout << "Resultado  :";
            ecRes.muestra();
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 2 :";
            ec2.muestra();
            cout << endl;
            break;
            
        case 'c':
            /*********************************/
            cout << endl;
            cout << "=== Multiplica Ecuación 1 por valor entero 2. Deja el resultado en ecRes" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            // Agrega la sobrecarga para hacer la multiplicación
            ec1 = ec1*2;
            
            
            
            cout << "Resultado  :";
            ecRes.muestra();
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << endl;
            break;
            
        case 'd':
            /*********************************/
            cout << endl;
            cout << "=== Compara con == ecuación 1 y ecuación 2, deben ser diferentes" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 2 :" ;
            ec2.muestra();
            
            
            if (ec1==ec2)
                cout << "Son iguales" << endl;
            else
                cout << "Son diferentes " << endl;
            
        break;
            
        case 'e':
            /*********************************/
            cout << endl;
            cout << "=== Compara con != ecuación 1 y ecuación 3, deben ser iguales" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            cout << "Ecuación 3 :" ;
            ec3.muestra();

            if ( ec1!=ec2)
                cout << "Son diferentes" << endl;
            else
                cout << "Son iguales " << endl;
            break;
            
        case 'f':
            /*********************************/
            cout << endl;
            cout << "=== Aplica ++ a Ecuación 1. Deja el resultado en ecRes" << endl;
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            // Agrega la sobrecarga para hacer el incremento (++)
            
            //ec1++;    
                
            cout << "Regresa    :";
            ecRes.muestra();
            cout << "Ecuación 1 :" ;
            ec1.muestra();
            break;
        }
        return 0;
}
