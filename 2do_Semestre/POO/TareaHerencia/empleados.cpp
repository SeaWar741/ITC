//
//  main.cpp
//  empleadosVendedores
//
//  Created by Yolanda Martinez on 09/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#include <iostream>
using namespace std;

#include "Vendedor.h"
int main() {
    
    Empleado emp1(129, 12000);
    Empleado emp2(231, 13500);
    Vendedor vend1(146, 8500, 0.03, 155000);
    Vendedor vend2(275, 5500, 0.05, 132500);
    
    cout << "Empleado 1 " << endl;
    emp1.muestra();
    cout << "Total a pagar " << emp1.calculaPago() << endl;
    
    cout << "Empleado 2 " << endl;
    emp2.muestra();
    cout << "Total a pagar " << emp2.calculaPago() << endl;
    
    cout << "Vendedor 1 " << endl;
    vend1.muestra();
    cout << "Total a pagar " << vend1.calculaPago() << endl;
    
    cout << "Vendedor 2 " << endl;
    vend2.muestra();
    cout << "Total a pagar " << vend2.calculaPago() << endl;
    
    return 0;
}
