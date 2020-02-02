#include "Coordenada.h"
class Circulo
{	
  public:
  // Constructores
		Circulo();
		Circulo(Coordenada, int);

// Métodos modificadores
		void setCentro(Coordenada);
    void setRadio(int);

// Métodos de acceso
		Coordenada getCentro();
		int getRadio();

    
		void print();

	private:
		Coordenada centro;
		int iRadio;
};

