//
//  Empleado.h
//  empleadosVendedores
//
//  Created by Yolanda Martinez on 09/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Empleado_h
#define Empleado_h


class Empleado {
    
public:
    Empleado();
    Empleado(int ide, double suel);
    
    void setIdent(int ide) { ident = ide; }
    void setSueldo(double suel) { sueldo = suel; }
    
    int getIdent() {  return ident; }
    double getSueldo() {  return sueldo; }
    
    double calculaPago();
    void muestra();
    
protected:
    int ident;
    double sueldo;
};

Empleado :: Empleado() {
    ident = 0;
    sueldo = 0;
}

Empleado :: Empleado(int ide, double suel) {
    ident = ide;
    sueldo = suel;
}

// el pago de un empleado es igual que su sueldo
double Empleado :: calculaPago() {
    return sueldo;
}

void Empleado::muestra() {
    cout << "Id de empleado " << ident;
    cout << " sueldo $" << sueldo << endl;
}

#endif /* Empleado_h */
