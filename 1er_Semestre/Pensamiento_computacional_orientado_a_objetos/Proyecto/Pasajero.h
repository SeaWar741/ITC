#include <iostream>
#include <string>
using namespace std;

class Pasajero{
private:
    string sName,sCel,sEmail,sContra;
    int iKm;
public:
    Pasajero();
    Pasajero(string,string,string,string,int);

    void setName(string);
    void setCel(string);
    void setEmail(string);
    void setPassword(string);
    void setKm(int);

    string getName();
    string getCel();
    string getEmail();
    string getPassword();
    int getKm();

    string str();
    void incrementaKm();
    void decrementakm();
    bool validarCuenta(string,string);
    bool existeUsuario(string);
};

Pasajero::Pasajero(/* args */)
{
}

Pasajero::~Pasajero()
{
}
