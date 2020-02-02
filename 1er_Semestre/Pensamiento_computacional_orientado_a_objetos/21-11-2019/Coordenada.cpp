#include <iostream>
using namespace std;
#include "Coordenada.h"

Coordenada :: Coordenada()
{	
  iX = 0;
	iY = 0;
}

Coordenada :: Coordenada(int valorX, int valorY)
{	 
  iX = valorX;
	iY = valorY;
}

void Coordenada::setX(int valorX)
{	 
  iX = valorX;
}

void Coordenada::setY(int valorY)
{	 iY = valorY;
}

int Coordenada::getX()
{	return iX;
}

int Coordenada::getY()
{	return iY;
}

void Coordenada::print()
{	
  cout << "(" << iX << "," << iY << ")";
}
