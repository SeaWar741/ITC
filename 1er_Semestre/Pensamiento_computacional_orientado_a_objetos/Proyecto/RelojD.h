#include <iostream>
#include <string>
using namespace std;

class RelojD{
private:
    int iHr,iMin;
public:
    RelojD();
    RelojD(int,int);

    void setHoras(int);
    void setMinutos(int);

    int getHora();
    int getMin();

    void incementaMinutos();
    string str();
};

RelojD::RelojD(){
    iHr = 0;
    iMin = 0;
}
RelojD::RelojD(int iHri,int iMini){
    this ->iHr=iHri;
    this ->iMin=iMini;
}

void RelojD::setHoras(int iHri){
    iHr =iHri;
}
void RelojD::setMinutos(int iMini){
    iMin =iMini;
}
int RelojD::getHora(){
    return iHr;
}
int RelojD::getMin(){
    return iMin;
}
void RelojD::incementaMinutos(){
    if(iMin==59){//si son las 11pm con 59min se cambia a las 0:0
        if(iHr ==23){
            iHr =0;
            iMin=0;
        }
        else{
            iHr++;//en caso de que no se suma la hora
            iMin =0;
        }
    }
    else{//en caso de que no se cumpla se suma la hora
        iMin++;
    }
}
string RelojD::str(){
    string hour,minute;//variables para hora y minuto
    if(iHr<10){
        hour = "0"+to_string(iHr);//hora concatenada con 0 en caso de que sea menor a 10
    }
    else{
        hour = to_string(iHr);
    }
    if(iMin<10){
        minute = "0"+to_string(iMin);//minutos concatenada con 0 en caso de que sea menor a 10
    }
    else{
        minute = to_string(iMin);
    }
    return hour+":"+minute;//se imprime la hora y minutos
}

