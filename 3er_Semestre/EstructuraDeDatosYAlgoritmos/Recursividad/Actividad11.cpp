//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <cmath>

using namespace std; 

//Suma Iterativa
//se manda a llamar a la funcion, se evalua si es entero positivo o no
//complejidad O(n)
int sumaIterativa(int n){
    int a = 0;
    if(n > 0){
        for(int i = 1; i <= n; i++){
            a += i;
        }
        return a;
    } else {
        throw runtime_error("El numero debe de ser un entero positivo");
    }
}

//Suma Recursiva
//se manda a llamar a la funcion hasta quedar en 0 o 1 tiene complejidad complejidad O(n)
int sumaRecursiva(int n){
    if (n==1 || n ==0){
        return n;
    }else{
        return n + sumaRecursiva(n-1);
    }
}

//Suma Directa
//se hace de manera directa una unica operacion
int sumaDirecta(int n){
    if(n > 0){
        return (n*(n+1))/2;
    } else {
        throw runtime_error("El numero debe de ser un entero positivo");
    }
}


//Factorial
//se llama la funcion a si misma
//complejidad O(n)
int factorial(int n){
    if(n>0){
        if(n<=1){
            return 1;
        }else{
            return n*factorial(n-1);
        }
    }else{
        throw runtime_error("El numero debe de ser un entero positivo");
    }
    
}

//Patron de caracteres
//complejidad O(n)
//se evalua el espacio y las posiciones donde colocar el char
//comienza poniendo 1 de manera centrada y va aumentando hasta lograr formar la piramide
//con espacios y caracteres
void patronCaracteres(int n, int original, char txt){
  if( n <= 0){
    return;
  }
  patronCaracteres(n-1, original,txt); 

  for(int i = 0; i < (original -n); i++){
    cout<<" ";
  }
  for(int i = 0; i< n; i++){
    cout<<txt<<" ";
  }
  cout<<endl;
}

//nuevos ejercicios
//Ejercicio 1
//complejidad O(n)
//calcula el valor de fibonacci en la posicion
int fibonacciRecursivo(int n){
    if(n <=2){
        return 1;
    }
    else{
        return ( fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2));
    }
}


//esta funcion tiene //complejidad O(n al cuadrado)
//esto por que por cada llamada a su funcion esta llama n veces a la otra para encontrar el valor del digito
//en fibonacci
void fibonacci(int n,int times){
    if(n!=0){
        cout<<"F("<<(times)<<")="<<fibonacciRecursivo(times)<<endl;
        fibonacci(n-1,times+1);
    }
}

//Ejercicio 2
//complejidad O(n)
//esta llama la funcion hasta lograr llegar al numero de dias totales
//evalua si es 0 y si es el ingresado
//evalua si esta en la condicion o no, calculando las bacterias con la formuka
//hasta igualar las llamadas al total deseado
int bacteria2(int n, int current, int bacterias){
    if (current == 0) {
        if(current != n){
            return bacteria2(n,current+1,1);
        }
        else{
            return 1;
        }
    }
    else{
         bacterias = round(bacterias +(bacterias*3.78)-(bacterias*2.34));
         if(current !=n){
             return bacteria2(n,current+1,bacterias);
         }
         else{
             return bacterias;
         }
    }
}

//Ejercicio 3
////complejidad O(n)
//se llama hasta lograr completar los meses deseados
double inversionRecursiva(int meses, double cant){
    if(meses >0){
        cant = cant+(cant*0.1875);
        return inversionRecursiva(meses-1,cant);
    }
    else if(meses ==0){
        return cant;
    }
    else{
        throw runtime_error("Valores invalidos");
    }
}

//Ejercicio 4
//complejidad O(n)
//es una operacion hasta lograr hacer que y sea terminado
int potencia(int x, int y){
    if(y>1){
        return x * potencia(x,y-1);
    }else{
        return x;
    }
}

int main(){
    try{
        cout<<"Suma Iterativa: "<<endl;
        cout<<sumaIterativa(6)<<endl;
    }catch(runtime_error& e){
        cout<<e.what()<<endl;
    }
    cout<<"Suma Recursiva: "<<endl;
    cout<<sumaRecursiva(6)<<endl;
    try{
        cout<<"Suma Directa: "<<endl;
        cout<<sumaDirecta(6)<<endl;
    }catch(runtime_error& e){
        cout<<e.what()<<endl;
    }
    try{ 
        cout<<"Factorial: "<<endl;
        cout<<factorial(6)<<endl;
    }catch(runtime_error& e){
        cout<<e.what()<<endl;
    }

    cout<<"Patron Caracteres: "<<endl;
    patronCaracteres(6,6, '*');

    
    //nuevos ejercicios
    cout<<"Fibonacci: "<<endl;
    fibonacci(6,1);

    cout<<"Bacteria: "<<endl;
    cout<<bacteria2(5,0,0)<<endl;

    try{
        cout<<"Inversion: "<<endl;
        cout<<inversionRecursiva(5,500)<<endl;
    }catch(runtime_error& e){
        cout<<e.what()<<endl;
    }
    cout<<"Potencia: "<<endl;
    cout<<potencia(2,2)<<endl;
}