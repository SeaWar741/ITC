//
//  main.cpp
//  Archivos
//
//  Created by Ma. Guadalupe Roque on 29/04/2019.
//  Copyright © 2019 Ma. Guadalupe Roque. All rights reserved.
//

#include <iostream>
#include <fstream> //1er paso hacer este include
using namespace std;

int main()
{
    ofstream archivoSalida; //2o Declarar una variable del tipo archivo de salida
    ifstream archivoEntrada;//2o Declarar la variable tipo archivo de entrada
    
    string sNombre, sCarrera, sEdad;
    
    //lee del teclado y lo manda grabar al archivo
    archivoSalida.open("FundamentosEM2019.txt", ios::app);// 3o Abrir el archivo

    for (int iK = 1; iK <= 5; iK++){
        cout<<"Teclea tu nombre:";
        getline(cin, sNombre);
        cout<<"Teclea tu carrera:";
        getline(cin, sCarrera);
        cout<<"Teclea tu edad:";
        getline(cin, sEdad);

				// cout << iK << "-" << sNombre << "-" << ...
        archivoSalida << iK << "-" << sNombre << "-" <<  sCarrera << "-" << sEdad << endl;
    }
		// Qué pasa si no lo cierro - no se guarda la información - 
    archivoSalida.close();
    
    
    //lee linea por linea del archivo y lo despliega en pantalla
    archivoEntrada.open("FundamentosEM2019.txt");
    
    if ( archivoEntrada.fail() ) //fail return true si No EXISTE EL ARCHIVO
        cout << "El archivo no existe" << endl;
    else
        
        // Ciclo que termina cuando se detecta el final del archivo.
        while ( ! archivoEntrada.eof() )    // eof = end of file.
        {
					  // Lee linea por linea del archivo.
            getline(archivoEntrada, sNombre);   
            cout << sNombre << endl;
        }
    
    archivoEntrada.close();
    
    return 0;
}
