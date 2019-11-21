#include "Circulo.h"
#include <iostream>
using namespace std;

int main()
{	
  Coordenada coor1(10,5), coor2(20,15), coor3;
	Circulo c1(coor2,10), c2;

	cout << "Los datos de la coordenada 1 son ";
	coor1.print();

  cout << "Los datos de la coordenada 2 son ";
	coor2.print();

  cout << "Los datos de la coordenada 3 son ";
	coor3.print();

	cout << endl;

	cout << "Los datos del circulo 1 son ";
	c1.print();    
  cout << "Los datos del circulo 2 son ";
  c2.print();


	cout << "Los datos del circulo 2 son ";
	coor3 = c2.getCentro();
	cout << "Centro -> (" << coor3.getX() << "," <<  coor3.getY() << "), " ;
	cout << "Radio -> "<< c2.getRadio() << endl;

	return 0;
}
