using namespace std;
#include <iostream>
#include <math.h>

void raices (double &dX1, double  &dX2, int iA, int iB, int iC ){
	dX1 = (-iB + sqrt(iB * iB - 4 * iA * iC)) / (2 * iA);
	dX2 = (-iB - sqrt(iB * iB - 4 * iA * iC)) / (2 * iA);
}
//Evaluar el paso de parámetros por valor y por referencia
void adivina(int &iX, int &iY, int iZ){
    iX = iY + iX;
    iY = iX + iY;
    iZ = iX + iY;
}
int main() {
    //Declaración de variables
    int iA, iB, iC;
    double dX1, dX2;
	iA = 5;
    iB = 8;
    iC = 9;

    adivina(iA, iB, iC);

    cout << iA << "-" << iB << "-" << iC << endl;
    
    raices (dX1, dX2, 3,0,-12 );  
    
    //la función debe actualizar a dX1=2, dX2=-2 y en el main desplegar
    cout << "Raiz1= " << dX1 << " Raiz2= " << dX2 << endl;
    
	raices (dX1, dX2, 1,-2,-1 ); 
	
	//la función debe actualizar a dX1=2.4142, dX2=-0.414214
    cout << "Raiz1= " << dX1 << " Raiz2= " << dX2 << endl;
	raices (dX1, dX2, 4,-4,-1 ); 
	
	//la función debe actualizar a dX1=1.20711, dX2=-0.207107
    cout << "Raiz1=" << dX1 << " Raiz2=" << dX2 << endl;
    return 0;
}