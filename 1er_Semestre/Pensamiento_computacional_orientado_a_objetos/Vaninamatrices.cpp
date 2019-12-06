#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

const int icolumna = 8;
const int irenglon = 10;
void llenaConArchivo(int iMatA[][icolumna])
{
  int iK = 0, resultado,indCol = 0;
  string archivo, numero;
  cout << "Nombre del archivo: ";

  cout<<"\n";

  ofstream archivo_salida;
  ifstream archivo_entrada;

  archivo_entrada.open("texto.txt", ios::app);

  if (archivo_entrada.fail() )
  {
    cout << "Error! El archivo no existe. "<< endl;
  }
  else
  {
    while (! archivo_entrada.eof())
    {
      for(int iFila=0; iFila<10; iFila++)
    {
      for(int iCol=0; iCol<8; iCol++)
      {
        getline(archivo_entrada, numero);
        resultado = atoi(numero.c_str());
        //cout<<resultado<<endl;
        iMatA[iFila][iCol]=resultado;
        /* Este que debe de hacer?
        if (indCol>iK-1)
          iMatA[iFila][iCol]=0;
        */
        indCol = indCol +1;
      }
    }
    }

    archivo_entrada.close();
  }
  for(int iFila=0; iFila<10; iFila++)
    {
      for(int iCol=0; iCol<8; iCol++)
      {
        cout << " " << iMatA[iFila][iCol];
      }
      cout << "" << endl;
    }
    cout << "" << endl;
}

void llenaConAleatorios(int iMatB[][icolumna], int iRen, int iCol)
{
  srand( time(NULL));
  for (int iR = 0; iR < iRen; iR++){
    for (int iC = 0; iC < iCol; iC++){
      iMatB[iR][iC] = rand() % 2001 - 1000;
    }
  }
}
void sumaMatrices(float matrizA[irenglon][icolumna],
float matrizB[irenglon][icolumna], float matrizC[irenglon][icolumna]){
  int numero, iK;
  string valor;
  ifstream archivo_entrada;
  ofstream archivo_salida;
  archivo_salida.open("archivo.txt");

  for(int iFil=0; iFil<10; iFil++)
    {
      for(int iCol=0; iCol<8; iCol++)
    {
      numero = matrizA[iFil][iCol]+matrizA[iFil][iCol];
      matrizC[iFil][iCol] = numero;
      archivo_salida << matrizC[iFil][iCol];
      archivo_salida << " ";
      if(iK %8==0)
        archivo_salida << endl;
    }
    }
    archivo_salida.close();
    archivo_entrada.open("archivo.txt");
    while(!archivo_entrada.eof()){
      getline(archivo_entrada, valor);
      cout << valor << endl;
    }
  archivo_entrada.close();
}
void desp_Diagonal(float matrizB[irenglon][icolumna]){
  int numero;
  string x = "";
  for(int iPosition=0; iPosition<8; iPosition++)
    {
      numero= matrizB[iPosition][iPosition];
      cout << x << numero << endl;
      x = x + " ";
    }
    cout<<""<<endl;
}
void intercambiaRenglon(float matrizB[irenglon][icolumna])
{
  int renglon, columna, escrito;
  float x[10], x2[28];
  cout << "Que escribira en el renglon? ";
  cin >> renglon;
  while (renglon > 10||renglon < 1){
    cout << "Nuevo valor para el renglon. ";
    cin >> renglon;
  }
  while (columna > 10||columna < 1){
    cout << "Valor para la columna. ";
    cin >> columna; 
  }
  for(int k = 0; k < 10; k++){
    escrito = matrizB[k][columna-1];
  }
  for(int j =0; j < 8; j++)
    {
      escrito = matrizB[renglon-1][j];
      x2[j]= escrito;
    }
    for(int m =0; m < 10; m++)
    {
      escrito  = x[m];
      matrizB[renglon-1][m]=escrito;
    }
    for(int iFila =0; iFila < 10; iFila++)
    {
      for(int iCol = 0; iCol<8; iCol++)
      {
        cout<<" "<< matrizB[iFila][iCol];
      }
      cout<< "" << endl;
    }  
    cout<< "" << endl;
}
void despliegaMatriz(int matrizA[irenglon][icolumna]){
  for (int j = 0; j < 10; j++){
    for (int k = 0; k < 8; k++){
      cout << matrizA[j][k];
    }
    cout << " ";
  } 
  cout << endl;
}
int menu()
{ int iOpcion;
  cout << "1. Llena con Archivos."<<endl;
  cout << "2. Llena con Aleatorios." << endl;
  cout << "3. Suma Matrices." << endl;
  cout << "4. Desplegar diagonal." << endl;
  cout << "0. Salir. " <<endl;
  cin>>iOpcion;
  return iOpcion;
}
int main()
{
  int iOpcion;
  int matrizA[irenglon][icolumna];
  int matrizB[irenglon][icolumna];
  int matrizC[irenglon][icolumna];
  do{
    iOpcion = menu();
    switch (iOpcion)
    {case 0:
        cout << "Gracias por usar el programa...";
        break;
      case 1:
        cout <<"Escogiste la opción 1. "<<endl;
        llenaConArchivo(matrizA);
        break;
      case 2:
        cout <<"Escogiste la opción 2. "<<endl;
        despliegaMatriz(matrizA);
        break;
      case 3:
        break;
      case 4:
        break;
      case 5:
        break;
      case 6:
        break;
      default:
        cout << "Opción inválida.\n";
        break;
    }
    cout << "Teclea enter para continuar. ";
  } while(iOpcion != 0);
  return 0;
}
