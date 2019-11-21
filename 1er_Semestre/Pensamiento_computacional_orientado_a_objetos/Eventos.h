#include <iostream>
#include"RelojD.h"
using namespace std;

class Eventos{
private:
    RelojD hr;
    int iDuracionMin;
    string sAsunto;
public:
    Eventos();
    Eventos(RelojD,int,string);

    void setHora(RelojD);
    void setDuracion(int);
    void setAsunto(string);

    RelojD getHora();//composicion
    int getDuracion();
    int getMin();

    void incrementaMinutos();
    string print();
};

Eventos::Eventos(){
}

Eventos::Eventos(){
}
