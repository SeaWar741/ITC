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
#include <string>a
#include <stdio.h>
#include <ctype.h>
#include <sstream>
using namespace std;

const int N = 10;//Columnas
const int M = 8;//Renglones

//Nombre:despliegaMatriz
//Descripcion: Metodo para imprimir una matriz
//              
//Entrada:
//          Matriz deseada
//Salida:
//          imprime una matriz en formato de tabla
void despliegaMatriz(int arry[][M]){
    cout<<endl;
    for (int i = 0; i < M; i++){ //itera sobre la matriz
        for (int j = 0; j < N; j++){
            cout<<arry[i][j]<<"\t";//utiliza un tab para igualar las distancias al imprimir
        }
        cout<<endl;//salto de linea cada fila completada
    }
    cout<<endl;
}

//Nombre:llenaConArchivo
//Descripcion: Metodo para leer datos de un archivo y almacenarlos en una
//              matriz dada
//Entrada:
//          Matriz deseada y nombre del archivo
//Salida:
//          Añade los datos a la matriz, en caso de que sean menores al tamaño se reemplazan por 0
void llenaConArchivo(int arry[][M],string txt){
    cout<<endl;
    ifstream inFile; //se crea el ifstream
    string pathf = "./"+txt+".txt"; //se hace un append para que lea el archivo en el directorio actual y le añade la extension
    int x,counter;
    inFile.open(pathf); //abre el archivo desde el path
    if (!inFile) {
        cerr << "No se pudo abrir el archivo "<<txt<<endl; //si no se encuentra el archivo
    }
    else{
        string str;
        int number;
        int ncounter =0;
        int counter=0;
        int readn[80] ={0}; //se inicializa el array con 0 en todos los elementos
        while (std::getline(inFile, str) && ncounter <=80) { //se lee cada linea mientras que no pase de 80 elementos
            std::istringstream iss (str); //se convierte a int
            iss >> number;
            readn[ncounter] = number;//se establece el valor
            ncounter++; //aumenta el contador de lineas
        }
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                arry[i][j]=readn[counter]; //se establecen los valores leidos en la matriz deseada deseado
                counter++;
            }
        }
    }
    inFile.close(); //se cierra el archivo
}

//Nombre:llenaConAleatorios
//Descripcion: Metodo para asignar valores aleatorios a una
//              matriz dada
//Entrada:
//          Matriz deseada 
//Salida:
//          Añade los datos a la matriz en un rango especifico
void llenaConAleatorios(int arry[][M]){
    srand(time(0));   //se inicializa el random
    int value = 0;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            value = rand() % 1500 + 1;//crea un valor aleatorio en el rango
            arry[i][j] = value;//lo establece de manera iterativa
        }
    }
}

//Nombre:sumaMatrices
//Descripcion: Suma matrices dadas
//Entrada:
//          Matrices deseadas y matriz para almacenar suma
//Salida:
//          Realiza una suma a las matrices, almacena el resultado en un archivo de texto
void sumaMatrices(int arry[][M], int arry2[][M],int sum[][M]){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < M; ++j){
            sum[i][j] = arry[i][j] + arry2[i][j]; //realiza la sumatoria y lo almacena en el nuevo array
        }
    }
    fstream myfile; //se llama a fstram
    myfile.open("salida.txt",fstream::app);//se establece que se hara un append al archivo
    for (int i=0; i< M;i++){        
        for (int j=0; j<N;j++){                      
            myfile << sum[i][j] <<"\t";//se añade cada elemento con un tab para espaciado
        }
        myfile<<std::endl;//se realiza un salto de linea cada row
    }
    myfile.close();//se cierra el documento/archivo
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    cout<<"Se guardo la suma en salida.txt exitosamente"<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
}

//Nombre:despliegaDiagonal
//Descripcion: Suma matrices dadas
//Entrada:
//          Matriz deseada
//Salida:
//          Imprime la diagonal de la matriz dada
void despliegaDiagonal(int arry[][M]){
    cout<<"Diagonal del array :"<<endl;
    for(int i=0 ; i<N &&i< M ; i++){//mientras que sea menor a n y a M realiza el ciclo
        for(int j = 0; j<i;j++){
            cout<<"\t";//formato deseado, realiza el espaciado    
        }
        cout<<arry[i][i]<<endl;
    }
}

//Nombre:intercambioaRenglonColumna
//Descripcion: Realiza un intercambio del renglon con columna
//Entrada:
//          Matriz deseada
//Salida:
//          Sustituye el renglon con la columna, lo hace con la restriccion de el numero de filas por 
//          lo que el ultimo elemento de la nueva sera el anterior ya que no se puede sustituir por el
//          tamaño del elemento deseado
void intercambioaRenglonColumna(int arry[][M]){
    int row,col,rowd,cold;
    cout<<"\nIngresa el numero de renglon: >";cin>>row;cout<<endl;//se ingresa el renglon y columna deseado
    cout<<"\nIngresa el numero de columna: >";cin>>col;cout<<endl;
    if(row<=M&&col<=N && row>=1&&col>=1){//se realiza si se cumplen las condiciones del rango en la matriz
        for(int i=0; i<M;i++){//se hace el intercambio de renglon columna
            rowd = arry[row-1][i];//se hace el menos uno para que el usuario pueda hacer la seleccion desde 1
            cold = arry[i][col-1];
            
            arry[row-1][i]=cold;
            arry[i][col-1]=rowd;
        }
        cout<<"\nSe realizo el intercambio!"<<endl;
    }
    else{//si no se cumple se imprime donde estuvo el error o si fue en ambos
        if(row>M||row<1){
            cout<<"Renglon fuera de rango\n";
        }
        if(col>N||col<1){
            cout<<"Columna fuera de rango\n";
        }
    }
}

//Nombre:selection
//Descripcion: char para obtener la seleccion del usuario de la matriz deseada
//Entrada:
//          
//Salida:
//          regresa un char en minusculas de la seleccion deseada para ejecutar el metodo
char selection(){
    char selection;
    cout<<"Ingresar letra de matriz(a/b/c): >";cin>>selection;
    selection = tolower(selection); //se pasa a minusculas
    cout<<endl;
    return selection;//se regresa el char
}

//Nombre:copyMatrix
//Descripcion: Se realiza una copia de la matriz
//Entrada:
//          matriz a copiar y a ser copiada
//Salida:
//          le establece los valores de la matriz a la otra
void copyMatrix(int arry[][M], int arry2[][M]){ 
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            arry[i][j]=arry2[i][j]; //se establecen los indices con los valores de la anterior
        }
    }
}

int main(){
    int matrizA[N][M] ={0},matrizB[N][M]={0},matrizC[N][M]={0},sum[N][M]={0};//se inicializan las matrices en 0
    char option,keep,matrixsave,suboption,matrixa,matrixb;//se inicializan los char para los menus
    string txt;//variable para el nombre de archivo
    bool continueg = true;//variable para controlar las repeticiones del menu
    cout<<endl;
    cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-=Bienvenid@ a la tarea de datos estructurados=-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
    while(continueg){//loop mientras que el usuario no seleccione la opcion de salir
        cout<<"\na) Llenar matriz con archivo"<<endl;
        cout<<"b) Llenar matriz con numeros aleatorios"<<endl;
        cout<<"c) Sumar Matrices"<<endl;
        cout<<"d) Desplegar Diagonal de una matriz"<<endl;
        cout<<"e) Intercambiar Renglon Columna"<<endl;
        cout<<"f) Salir"<<endl;
        cout<<endl;
        cout<<"Matrices:"<<endl;
        cout<<"Matriz A:";
        despliegaMatriz(matrizA);//se despliegan las matrices
        cout<<"Matriz B:";
        despliegaMatriz(matrizB);
        cout<<"Matriz C:";
        despliegaMatriz(matrizC);
        cout<<endl;
        cout<<"Ingresa una opcion del menu: >";cin>>option;//se pide el input del usuario
        switch (option){//switch principal para las opciones del menu
            case 'a'://establecer datos de la matriz con archivo
                cout<<"\nIngresa el nombre del archivo: >";cin>>txt;//se pide el nombre
                cout<<endl;
                suboption = selection();//se pide a que matriz se le asignaran los valores y se realiza la funcion
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
            case 'b'://establecer valores aleatorios 
                suboption = selection(); //se pide la seleccion de la matriz al usuario y se realiza la funcion
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
            case 'c'://suma de matrices con matrices dadas
                matrixa=selection();//se pide la matriz 1
                matrixb=selection();//se pide la matriz 2
                if(matrixa == 'a' &&matrixb=='b'|| matrixa == 'b' &&matrixb=='a'){//condicionales para todos los posibles casos
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
                else{//en caso de que no sea valida la combinacion se hace suma de a con b
                    cout<<"No se selecciono una combinacion valida, sumando matriz A con matriz B"<<endl;
                    sumaMatrices(matrizA,matrizB,sum);
                }

                cout<<"\nLa suma de las matrices es:"<<endl;
                despliegaMatriz(sum);//se imprime el valor de la suma
                cout<<"Desea guardar la matriz en otra? (s/n): >";cin>>keep;cout<<endl;
                if(tolower(keep)=='s'){//si el usuario quiere guardar la matriz se pide que ingrese en donde guardarla
                    matrixsave = selection();
                    switch (matrixsave){//switch para seleccionar donde establecer los valores y copiar ahi la matriz
                    case 'a':
                        copyMatrix(matrizA,sum);//se llama al metodo
                        break;
                    case 'b':
                        copyMatrix(matrizB,sum);
                        break;
                    case 'c':
                        copyMatrix(matrizC,sum);
                        break;
                    default:
                        copyMatrix(matrizA,sum);//en caso default se copia en A
                        cout<<"Se guardo en la matriz A\n";
                    }
                }
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            case 'd'://Desplegar la diagonal de una matriz seleccionada
                cout<<endl;
                suboption = selection();//se pide la matriz y se realiza sobre ella el metodo
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
            case 'e'://intercambio de renglon a columna 
                suboption = selection();//se pide la matriz y se llama al metodo
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
            case 'f'://se termina el loop
                continueg = false;
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
            default://se pide al usuario en caso de un input no valido intentar de nuevo
                cout<<"\nOpcion no valida, intentar de nuevo"<<endl;
                cout<<"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-"<<endl;
                break;
        }
    }
    cout<<"\nHasta luego!\n";//se acaba el programa
    return 0;
}