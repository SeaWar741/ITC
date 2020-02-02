//
//  main.cpp
//  Strings
//
//  Created by Ma. Guadalupe Roque on 14/11/17.
//  Copyright © 2017 Ma. Guadalupe Roque. All rights reserved.
//

//
#include <iostream>
#include <stdio.h>
#include <ctype.h>
using namespace std;


//** Añadir descripción
void desglozaNombre( )
{
    //Declaración de variables
    string sName, sName2, sApellidoPaterno, sApellidoMaterno;
    int iPos1;
    
   // getline(cin,sName);
    cout << "Teclea tu nombre:";
    getline(cin,sName);
    
    cout << "Muy buen día😊! " << sName <<"\n";
    
    //sacar el nombre
    iPos1 = (int)sName.find(" ");
    sName2 = sName.substr(0,iPos1);
    sName.erase(0,iPos1 + 1);
    
    //Sacar el apellido
    iPos1 = (int)sName.find(" ");
    sApellidoPaterno  = sName.substr(0,iPos1);
    sName.erase(0,iPos1 + 1);
    
    //Sacar el apellido materno
    sApellidoMaterno = sName;
    
    
    //Desplegar el nombre por separado
    cout << "Tu Nombre =😊" << sName2 <<
    "\nApellido Paterno=😊" << sApellidoPaterno
    << "\nApellido Materno=😊" << sApellidoMaterno
    << endl;
}

//** Añadir descripción

bool palindrome (string sFrase)
{
    int iPos1;
    
    iPos1 = (int) sFrase.find(" ");
    while (iPos1 != -1)
    {
        sFrase.erase(iPos1, 1);
        iPos1 = (int) sFrase.find(" ");
    }
    
    cout << sFrase << "Sin blancos\n";
    
    //comparar si son diferentes
    iPos1 = (int) sFrase.length();
    
    for ( int iP = 0, iP2 = iPos1 - 1; iP < iPos1 / 2; iP ++, iP2--)
    {
        if ( tolower(sFrase[iP]) != tolower(sFrase[iP2] ))
            return false;
    }
    
    //si fue palindrome
    return true;
}



//** Añadir descripción
int  menu()
{
    //Declaración de variables
    int iOpcion;
    cout << "\n1. Desgloza nombre"
    << "\n2. Palindrome"
    << "\n0. Salir"
    << "\nTeclea la opcion:";
    
    cin >> iOpcion;
    
    cin.ignore(); //consume el fin de línea
    
    return iOpcion;
}


//**
int main()
{
    string sFrase;
    int iOpcion;
    
    
    do{
        iOpcion = menu();
        switch (iOpcion) {
            case 0:
                cout << "Gracias por usar el programa\n";
                break;
            case 1:
                desglozaNombre();
                break;
            case 2:
                cout << "Teclea la frase:";
                getline(cin, sFrase);
                //Añade las instrucciones para llamar a la función
                if (! palindrome(sFrase))
                {
                    cout << "No es palindrome\n";
                }
                else
                     cout << "Si es palindrome\n";
                
                break;
            default:
                cout << "Opcion Incorrecta!!\n";
                break;
        }
        cin.ignore();
        cout << "Teclea <enter> para continuar...";
        getline(cin, sFrase);
        
    }while (iOpcion != 0);
    
    
    
    return 0;
}
