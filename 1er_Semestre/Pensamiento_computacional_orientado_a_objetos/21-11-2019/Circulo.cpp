#include <iostream>
using namespace std;
#include "Circulo.h"

Circulo::Circulo()
{
  Coordenada  c(1,1);
  centro = c;
  iRadio = 1;
}

Circulo::Circulo(Coordenada cen, int iValorRadio) 
{
  centro = cen;	
  iRadio = iValorRadio;
}

void Circulo::setCentro(Coordenada c)
{
  centro = c;
}

void Circulo::setRadio(int valorRadio)
{
  iRadio = valorRadio;
}

Coordenada Circulo::getCentro()
{
  return centro;
}

int Circulo::getRadio()
{
  return iRadio;
}

void Circulo::print()
{
  cout << "Centro :";
  centro.print();
  cout << ", Radio :" << iRadio << endl;
}
