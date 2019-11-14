//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 14/11/2019
//| Descripcion: Programa para realizar operaciones con arreglos, lectura/escritura de datos y como entregable inicial de reto
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm> 
#include <fstream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
using namespace std;

const int N = 10;
const int M = 8;

void despliegaMatriz(int arry[][M]){
    cout<<endl;
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cout<<arry[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void llenaConArchivo(int arry[][M],string txt){
    cout<<endl;
    ifstream inFile;
    string pathf = "./"+txt+".txt";
    int x,counter;
    inFile.open(pathf);
    if (!inFile) {
        cerr << "No se pudo abrir el archivo "<<txt<<endl;
    }
    else{
        string str;
        int number;
        int ncounter =0;
        int counter=0;
        int readn[80] ={0};
        while (std::getline(inFile, str) && ncounter <=80) {
            std::istringstream iss (str);
            iss >> number;
            readn[ncounter] = number;
            ncounter++;
        }
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                arry[i][j]=readn[counter];
                counter++;
            }
        }
    }
    inFile.close();
}

void llenaConAleatorios(int arry[][M]){
    //. Llena la matriz que recibe como parámetro con números aleatorios
    //dentro del rango de 0 a 1500.
    srand(time(0));   //se inicializa el random
    int value = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            value = rand() % 1500 + 1;
            arry[i][j] = value;
        }
    }
}

void sumaMatrices(int arry[][M], int arry2[][M],int sum[][M]){
    /*Calcula la suma de dos matrices que recibe como parámetro (A y B) y
    coloca el resultado en una tercera matriz (C) que también se recibe como parámetro.
    Después de realizar la suma de las matrices A y B, el contenido de la matriz C debe
    almacenarse en el archivo salida.txt en formato "matriz", es decir con N renglones y M
    columnas. El contenido del archivo salida.txt no debe reescribirse por cada ejecución del
    método, el nuevo contenido debe agregarse al final del archivo.*/
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            sum[i][j] = arry[i][j] + arry2[i][j];
        }
    }
    fstream myfile;
    myfile.open("salida.txt",fstream::app);
    for (int i=0; i< M;i++){        
        for (int j=0; j<N;j++){                      
            myfile << sum[i][j] <<"\t";
        }
        myfile<<std::endl;
    }
    myfile.close();
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<<"Se guardo la suma en salida.txt exitosamente"<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
}

void despliegaDiagonal(int arry[][M]){
     /*Muestra en pantalla la diagonal principal de la matriz que recibe
     como parámetro. Se pide que la diagonal se muestre en el siguiente formato:*/
    cout<<"Diagonal del array :"<<endl;
    for(int i=0 ; i<N &&i< M ; i++){
        if(i<N-1){
            cout<<arry[i][i]<<"  ";
        }
        else{
            cout<<arry[i][i]<<endl;
        }
    }
}

void intercambioaRenglonColumna(int arry[][M]){
    int row,col,rowd,cold;
    cout<<"\nIngresa el numero de renglon: >";cin>>row;cout<<endl;
    cout<<"\nIngresa el numero de columna: >";cin>>col;cout<<endl;
    if(row<=M&&col<=N && row>=1&&col>=1){
        for(int i=0; i<M;i++){
            rowd = arry[row-1][i];
            cold = arry[i][col-1];
            
            arry[row-1][i]=cold;
            arry[i][col-1]=rowd;
        }
        cout<<"\nSe realizo el intercambio!"<<endl;
    }
    else{
        if(row>M||row<1){
            cout<<"Renglon fuera de rango\n";
        }
        if(col>N||col<1){
            cout<<"Columna fuera de rango\n";
        }
    }
}

char selection(){
    char selection;
    cout<<"Ingresar letra de matriz(a/b/c): >";cin>>selection;
    selection = tolower(selection);
    cout<<endl;
    return selection;
}

void copyMatrix(int arry[][M], int arry2[][M]){ 
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            arry[i][j]=arry2[i][j];
        }
    }
}

int main(){
    int matrizA[N][M] ={0},matrizB[N][M]={0},matrizC[N][M]={0},sum[N][M]={0};
    char option,keep,matrixsave,suboption,matrixa,matrixb;
    string txt;
    bool continueg = true;
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ a la tarea de datos estructurados=-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    while(continueg){
        cout<<"\na) Llenar matriz con archivo"<<endl;
        cout<<"b) Llenar matriz con numeros aleatorios"<<endl;
        cout<<"c) Sumar Matrices"<<endl;
        cout<<"d) Desplegar Diagonal de una matriz"<<endl;
        cout<<"e) Intercambiar Renglon Columna"<<endl;
        cout<<"f) Salir"<<endl;
        cout<<endl;
        cout<<"Matrices:"<<endl;
        cout<<"Matriz A:";
        despliegaMatriz(matrizA);
        cout<<"Matriz B:";
        despliegaMatriz(matrizB);
        cout<<"Matriz C:";
        despliegaMatriz(matrizC);
        cout<<endl;
        cout<<"Ingresa una opcion del menu: >";cin>>option;
        switch (option){
            case 'a':
                cout<<"\nIngresa el nombre del archivo: >";cin>>txt;
                cout<<endl;
                suboption = selection();
                if(suboption == 'a'){
                    llenaConArchivo(matrizA,txt);
                }
                else if(suboption == 'b'){
                    llenaConArchivo(matrizB,txt);
                }
                else{
                    llenaConArchivo(matrizC,txt);
                }
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'b':
                suboption = selection();
                if(suboption == 'a'){
                    llenaConAleatorios(matrizA);
                }
                else if(suboption == 'b'){
                    llenaConAleatorios(matrizB);
                }
                else{
                    llenaConAleatorios(matrizC);
                }
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'c':
                matrixa=selection();
                matrixb=selection();
                if(matrixa == 'a' &&matrixb=='b'|| matrixa == 'b' &&matrixb=='a'){
                    sumaMatrices(matrizA,matrizB,sum);
                }
                else if(matrixa == 'a' &&matrixb=='c'||matrixa == 'c' &&matrixb=='a'){
                    sumaMatrices(matrizA,matrizC,sum);
                }
                else if(matrixa == 'b' &&matrixb=='c'||matrixa == 'c' &&matrixb=='b'){
                    sumaMatrices(matrizB,matrizC,sum);
                }
                else if(matrixa == 'a' && matrixb=='a'){
                    sumaMatrices(matrizA,matrizA,sum);
                }
                else if(matrixa == 'b' && matrixb=='b'){
                    sumaMatrices(matrizB,matrizB,sum);
                }
                else if(matrixa == 'c' && matrixb=='c'){
                    sumaMatrices(matrizC,matrizC,sum);
                }
                else{
                    cout<<"No se selecciono una combinacion valida, sumando matriz A con matriz B"<<endl;
                    sumaMatrices(matrizA,matrizB,sum);
                }

                cout<<"\nLa suma de las matrices es:"<<endl;
                despliegaMatriz(sum);
                cout<<"Desea guardar la matriz en otra? (s/n): >";cin>>keep;cout<<endl;
                if(tolower(keep)=='s'){
                    matrixsave = selection();
                    switch (matrixsave){
                    case 'a':
                        copyMatrix(matrizA,sum);
                        break;
                    case 'b':
                        copyMatrix(matrizB,sum);
                        break;
                    case 'c':
                        copyMatrix(matrizC,sum);
                        break;
                    default:
                        copyMatrix(matrizA,sum);
                        cout<<"Se guardo en la matriz a\n";
                    }
                }
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'd':
                cout<<endl;
                suboption = selection();
                if(suboption == 'a'){
                    despliegaDiagonal(matrizA);
                }
                else if(suboption =='b'){
                    despliegaDiagonal(matrizB);
                }
                else{
                    despliegaDiagonal(matrizC);
                }
                cout<<endl;
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'e':
                suboption = selection();
                if(suboption == 'a'){
                    intercambioaRenglonColumna(matrizA);
                }
                else if(suboption=='b'){
                    intercambioaRenglonColumna(matrizB);
                }
                else{
                    intercambioaRenglonColumna(matrizC);
                }
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'f':
                continueg = false;
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            default:
                cout<<"\nOpcion no valida, intentar de nuevo"<<endl;
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
        }
    }
    cout<<"\nHasta luego!\n";
    return 0;
}