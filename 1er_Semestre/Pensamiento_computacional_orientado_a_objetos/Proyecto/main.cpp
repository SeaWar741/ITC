//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//| Autor: Juan Carlos Garfias Tovar
//| Matricula: A01652138
//| Fecha de creacion/modificacion: 30/12/2019
//| Descripcion: Programa para gestion de vuelos y pasajeros
//|-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-* 
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream> 
#include <cstring>
#include <algorithm>
#include "Vuelo.h"

using namespace std;

//Variables Globales
vector<Pasajero> Pasajeros; //Vector con todos los pasajeros
vector<Vuelo> Vuelos; //Vector con todos los vuelos
string jump="\n"; //String para simplificar salto de linea
int nVuelos = 0; //Contador de numero de vuelos

//Nombre:filldata
//Descripcion: Metodo para llenar los objetos y vectores
//              
//Entrada:
//          
//Salida:
//
void filldata(){
    //Variables Personas
    string myText,myText2;
    int km;
    int counter=0;
    Pasajero pasajero;
    //Variables Vuelo
    Vuelo Vuelo;
    Fecha Fecha;
    RelojD Hora;
    int iPrecio;
    string sDestino;
    string sAerolinea;
    int iKm,iAsientos;
    int counter2=0;
    int matPasajeros[30][4];
    //Personas
    //Se realiza una lectura en el archivo contenedor de pasajeros
    ifstream MyReadFile("pasajeros.txt");
    while (getline (MyReadFile, myText)) {//mientras que existan lineas en el archivo
        istringstream ss(myText); 
        do { 
            string word; 
            ss >> word; //se crea un string por linea y se establecen los valores del objeto
            if(counter== 0){
                pasajero.setName(word);
            }
            else if(counter== 1){
                    pasajero.setCel(word);
            }
            else if(counter== 2){
                pasajero.setEmail(word);
            }
            else if(counter== 3){
                pasajero.setPassword(word);
            }
            else if(counter== 4){
                km = stoi(word);
                pasajero.setKm(km);
            }
            counter++;
        } while (ss);
        Pasajeros.push_back(pasajero); //se inserta el objeto al vector
        counter=0;
    }
    MyReadFile.close();
    //Se realiza una lectura en el archivo contenedor de vuelos
    ifstream MyReadFile2("vuelos.txt");
    int vueloid = 0;
    while (getline (MyReadFile2, myText)) {//mientras que existan lineas en el archivo
        istringstream ss(myText); 
        do { 
            string word; 
            ss >> word;
            if(counter== 0){//date
                    //12/04/2019
                int n = word.length(); 
  
                // declaring character array 
                char char_array[10 + 1]; 

                strcpy(char_array, word.c_str()); //se convierte la palabra en un char array
                string dia1(1,char_array[0]);
                string dia2(1,char_array[1]);

                string mes1(1,char_array[3]);
                string mes2(1,char_array[4]);

                string ano1(1,char_array[6]);
                string ano2(1,char_array[7]);
                string ano3(1,char_array[8]);
                string ano4(1,char_array[9]);

                Fecha.setDia(stoi(dia1+dia2));//se establece la fecha a partir de concatenacion de chars

                Fecha.setMes(stoi(mes1+mes2));
    
                Fecha.setYear(stoi(ano1+ano2+ano3+ano4));
                    
                Vuelo.setFecha(Fecha);
                //counter=0;
            }
            else if(counter== 1){//hour
                //12:59
                vector<int> vect;
                istringstream ss(word);

                for (int i; ss >> i;) {
                    vect.push_back(i);    
                    if (ss.peek() == ':')
                        ss.ignore();
                }
                for (size_t i = 0; i < vect.size(); i++){
                    if (i ==0){
                        Hora.setHoras(vect[i]);
                    }
                    else if (i ==1){
                        Hora.setMinutos(vect[i]);
                    }
                }
                Vuelo.setHora(Hora);
            }
            else if(counter== 2){//price
                Vuelo.setPrecio(stoi(word));
            }
            else if(counter== 3){//destino
                Vuelo.setDestino(word);
            }
            else if(counter== 4){//aerolina
                Vuelo.setAerolinea(word);
            }
            else if(counter== 5){//km
                Vuelo.setKilometros(stoi(word));
            }
            else if(counter== 6){//km
                Vuelo.setAsientos(stoi(word));
            }
            counter++;
        } while (ss);
            
        ifstream MyReadFile3("vuelo"+to_string(vueloid)+".txt");//se abre el archivo de los asientos con el id del vuelo
        int i=0,j=0;
        while (getline (MyReadFile3, myText2)&&i<30) { //mientras existan lineas y no se superen las 30 filas
            stringstream ss(myText2); 
            while(j<4){//se establece cada columna
                string word; 
                ss >> word;
                Vuelo.setReservaAsiento(i,j,stoi(word));//Se reserva el asiento
                if(stoi(word)!=-1){
                    Vuelo.derementaAsientos();//En caso de que este vacio se decrementan 
                }
                j++;
            }
            j=0;
            i++;
        }
        MyReadFile3.close();
        Vuelos.push_back(Vuelo); //se inserta al vector el objeto
        nVuelos++;
        vueloid++;
        counter=0;
    }
    MyReadFile2.close();
}

//Nombre:recordData
//Descripcion: Metodo para sobreescribir los archivos a partir de vectores de objeto
//              
//Entrada:
//          
//Salida:
//      Archivos de vuelo, pasajeros e individuales
void recordData(){
    string objectinfo;
    ofstream outfile;
    //pasajeros
    outfile.open("pasajeros.txt");
    for (int i = 0; i < Pasajeros.size(); i++){
        objectinfo+=Pasajeros[i].getName()+" ";
        objectinfo+=Pasajeros[i].getCel()+" ";
        objectinfo+=Pasajeros[i].getEmail()+" ";
        objectinfo+=Pasajeros[i].getPassword()+" ";
        objectinfo+=to_string(Pasajeros[i].getKm());
        // write inputted data into the file.
        outfile << objectinfo << endl;
        objectinfo ="";
    }
    // close the opened file.
    outfile.close();
    //Vuelos
    outfile.open("vuelos.txt");
    for (int i = 0; i < Vuelos.size(); i++){
        objectinfo+=Vuelos[i].getFecha().str()+" ";
        objectinfo+=Vuelos[i].getHora().str()+" ";
        objectinfo+=to_string(Vuelos[i].getPrecio())+" ";
        objectinfo+=Vuelos[i].getDestino()+" ";
        objectinfo+=Vuelos[i].getAerolinea()+" ";
        objectinfo+=to_string(Vuelos[i].getKilometros())+" ";
        objectinfo+=to_string(Vuelos[i].getAsientos())+" ";
        // write inputted data into the file.
        outfile << objectinfo << endl;
        objectinfo ="";
    }
   // close the opened file.
   outfile.close();

   //Asientos vuelos
   string wordly="";
   for (int i = 0; i < Vuelos.size(); i++){
        outfile.open("vuelo"+to_string(i)+".txt", std::ofstream::out | std::ofstream::trunc); //se vacia el archivo
        outfile.close();
   }
   //se inserta los valores de la matriz del vuelo
   for (int i = 0; i < Vuelos.size(); i++){
        outfile.open("vuelo"+to_string(i)+".txt");

        wordly=Vuelos[i].getmatPasajeros();
        outfile << wordly << endl;
        outfile.close();
   }
}

//Nombre:printdata
//Descripcion: Imprime todos los elementos de pasajeros
//              
//Entrada:
//          
//Salida:
//        Pasajeros
void printdata(){
    for(int i=0; i<Pasajeros.size(); ++i){
        cout << Pasajeros[i].str()<<endl;
    }
}

//Nombre:printdata2
//Descripcion: Imprime todos los elementos de vuelos
//              
//Entrada:
//          
//Salida:
//        Vuelos
void printdata2(){
    for(int i=0; i<Vuelos.size(); ++i){
        cout << Vuelos[i].str()<<endl;
    }
}

//Nombre:printdataDate
//Descripcion: Imprime los vuelos a partir de fecha
//              
//Entrada:
//          dia,mes,ano
//Salida:
//        Vuelos
void printdataDate(int dia,int mes,int ano){
    string word="";
    int counter = 0;
    for(int i=0; i<Vuelos.size(); ++i){
        if(Vuelos[i].getFecha().getDia()==dia&&Vuelos[i].getFecha().getMes() == mes&&Vuelos[i].getFecha().getYear() == ano &&Vuelos[i].getAsientos()<120){
            if (counter==9){
                word +=Vuelos[i].str()+"\n\n";
                counter =0;
            }
            else{
                word +=Vuelos[i].str()+"\n";
                counter++;
            }
        }
    }
    cout<<word<<endl;
}

//Funciones Pasajero

//Nombre:existeUsuario
//Descripcion: Verifica si existe usuario
//              
//Entrada:
//          correo
//Salida:
//        boolean
bool existeUsuario(string user){
    for(int i=0; i<Pasajeros.size(); ++i){
        if(Pasajeros[i].existeUsuario(user)){
            return true;
        }
    }
    return false;
}

//Nombre:crearUsuario
//Descripcion:  Crea un usuario
//              
//Entrada:
//          
//Salida:
//        Usuario anadido al vector 
void crearUsuario(){
    string sName,sCel,sEmail,sContra;
    int iKm;
    cout<<"Ingresar Nombre: >";cin>>sName;
    cout<<"Ingresar Email: >";cin>>sEmail;
    if (existeUsuario(sEmail)==false){
        cout<<"Ingresar Celular: >";cin>>sCel;
        cout<<"Ingresar Contrasena: >";cin>>sContra;
        Pasajero pasajero(sName,sCel,sEmail,sContra,0);
        Pasajeros.push_back(pasajero);
        cout<<"\nUsuario Creado exitosamente!"<<endl;
    }
    else{
        cout<<"\nEste usuario ya esta registrado!"<<endl;
    }
}

//LOGIN

//Nombre:login
//Descripcion:  Regresa la posicion en el vector a partir de credenciales
//              
//Entrada:
//          
//Salida:
//        Posicion en el vector
int login(){
    int userid;
    string user,password;
    cout<<"Ingresar email: >";cin>>user;
    if(existeUsuario(user)){
        cout<<"Ingresar contrasena: >";cin>>password;
        for(int i=0; i<Pasajeros.size(); ++i){
            if(Pasajeros[i].validarCuenta(user,password)){
                return i;
            }
        }
    }
    cout<<"\nUsuario no registrado"<<endl;
    return -1;
}

//Nombre:loginSC
//Descripcion:  Regresa la posicion en el vector a partir de usuario
//              
//Entrada:
//          
//Salida:
//        Posicion en el vector
int loginSC(){
    int userid;
    string user;
    cout<<"Ingresar email: >";cin>>user;
    if(existeUsuario(user)){
        for(int i=0; i<Pasajeros.size(); ++i){
            return i;
        }
    }
    cout<<"\nUsuario no registrado"<<endl;
    return -1;
}

//Nombre:loginVuelo
//Descripcion:  Regresa la posicion en el vector a partir de fecha y hora
//              
//Entrada:
//          
//Salida:
//        Posicion en el vector
int loginVuelo(){
    Fecha Fecha;
    RelojD Hora;
    string sDestino;
    string sAerolinea;
    int dia,mes,ano,hora,minuto;

    cout<<"Ingresar dia: >";cin>>dia;
    cout<<"Ingresar mes: >";cin>>mes;
    cout<<"Ingresar ano: >";cin>>ano;

    Fecha.setDia(dia);
    Fecha.setMes(mes);
    Fecha.setYear(ano);
    
    cout<<"Ingresar hora: >";cin>>hora;
    cout<<"Ingresar minuto: >";cin>>minuto;

    Hora.setHoras(hora);
    Hora.setMinutos(minuto);

    cout<<"Ingresar Aerolinea: >";cin>>sAerolinea;
    cout<<"Ingresar Destino: >";cin>>sDestino;

    for (size_t i = 0; i < Vuelos.size(); i++){
        if (Vuelos[i].getFecha().str() == Fecha.str() && Vuelos[i].getHora().str() == Hora.str() && Vuelos[i].getAerolinea() == sAerolinea && Vuelos[i].getDestino() == sDestino){
            return i;
        }   
    }
    cout<<"\nVuelo no registrado"<<endl;
    return -1;
}

//Nombre:loginVuelo
//Descripcion:  Regresa la posicion en el vector a partir de fecha y hora
//              
//Entrada:
//          
//Salida:
//        Posicion en el vector
int loginVueloDate(int idia,int imes,int anoi){
    Fecha Fecha;
    RelojD Hora;
    string sDestino;
    string sAerolinea;
    int dia,mes,ano,hora,minuto;

    dia = idia;
    mes = imes;
    ano = anoi;

    Fecha.setDia(dia);
    Fecha.setMes(mes);
    Fecha.setYear(ano);
    
    cout<<"\nPara seleccionar el vuelo ingresa los siguientes datos:"<<endl;
    cout<<"Ingresar hora: >";cin>>hora;
    cout<<"Ingresar minuto: >";cin>>minuto;

    Hora.setHoras(hora);
    Hora.setMinutos(minuto);

    cout<<"Ingresar Aerolinea: >";cin>>sAerolinea;
    cout<<"Ingresar Destino: >";cin>>sDestino;

    for (size_t i = 0; i < Vuelos.size(); i++){
        if (Vuelos[i].getFecha().str() == Fecha.str() && Vuelos[i].getHora().str() == Hora.str() && Vuelos[i].getAerolinea() == sAerolinea && Vuelos[i].getDestino() == sDestino){
            return i;
        }   
    }
    cout<<"\nVuelo no registrado"<<endl;
    return -1;
    
}

//Funciones Vuelos

//Nombre:crearVuelo
//Descripcion:  Crea un vuelo y lo anade al vector
//              
//Entrada:
//          
//Salida:
//        objeto tipo vuelo
void crearVuelo(){
    Vuelo Vuelo;
    int dia,mes,ano;
    
    int hora,minuto;

    int iPrecio;
    string sDestino;
    string sAerolinea;
    int iKm,iAsientos;
    int matPasajeros[30][4];
    Pasajero Pasajeros[30][4];

    cout<<"Ingresa el dia: >";cin>>dia;
    cout<<"Ingresa el mes: >";cin>>mes;
    cout<<"Ingresa el ano: >";cin>>ano;
    Fecha fecha(dia,mes,ano);

    cout<<"Ingresa hora: >";cin>>hora;
    cout<<"Ingresa minutos: >";cin>>minuto;
    RelojD clock(hora,dia);

    cout<<"Ingresa la aerolinea: >";cin>>sAerolinea;
    cout<<"Ingresa el precio: >$";cin>>iPrecio;
    cout<<"Ingresa el destino: >";cin>>sDestino;
    cout<<"Ingresa el numero de kilometros: >";cin>>iKm;
    
    Vuelo.setFecha(fecha);
    Vuelo.setHora(clock);
    Vuelo.setPrecio(iPrecio);
    Vuelo.setDestino(sDestino);
    Vuelo.setAerolinea(sAerolinea);
    Vuelo.setKilometros(iKm);

    Vuelos.push_back(Vuelo);
    ofstream outfile;
    //pasajeros
    string vueloslist = "";
    outfile.open("vuelo"+to_string(nVuelos-1)+".txt");
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 4; j++){
            vueloslist+="-1 ";
        }
        vueloslist+="\n";
    }
    outfile << vueloslist << endl;
    outfile.close();

}

//Menus

//Nombre:menuPasajeros
//Descripcion:  Regresar la opcion del menu e impresion del mismo
//              
//Entrada:
//          
//Salida:
//        seleccion del menu
int menuPasajeros(){
    int iOpcion;
    cout<<"------------------= Gestor de pasajeros =------------------"<<
    "\n\n1) Crear un nuevo usuario "<<
    "\n\n---= Modificadores de pasajeros =----"<<
    "\n\n2) Cambiar nombre "<<
    "\n3) Cambiar celular "<<
    "\n\n4) Cambiar contrasena "<<
    "\n\n---= Acceso de informacion de pasajeros =----"<<
    "\n\n5) Obtener nombre "<<
    "\n6) Obtener celular "<<
    "\n7) Obtener Km "<<
    "\n8) Obtener email "<<
    "\n9) Obtener contrasena "<<
    "\n\n---= Acciones adicionales para pasajeros =----"<<
    "\n\n10) Incrementa kilometros "<<
    "\n11) decrementa kilometros "<<
    //"\n12) Validar Cuenta "<<
    "\n\n---= Mostrar cuentas de pasajeros =----"<<
    "\n\n12) Imprimir Cuentas "<<
    "\n\n---= Salir del sistema =----"<<
    "\n\n0) Terminar "<<
    "\n\nTeclea la opcion: >";
    cin>>iOpcion;
    return iOpcion;
}

//Nombre:menuVuelos
//Descripcion:  Regresar la opcion del menu e impresion del mismo
//              
//Entrada:
//          
//Salida:
//        seleccion del menu
int menuVuelos(){
    int iOpcion;
    cout<<"------------------= Gestor de vuelos =------------------"<<
    "\n\n1) Crear un nuevo vuelo "<<
    "\n\n---= Modificadores de vuelos =----"<<
    "\n2) Rstablecer fecha "<<
    "\n3) Establecer hora "<<
    "\n4) Establecer precio "<<
    "\n5) Establecer destino "<<
    "\n6) Establecer aerolinea "<<
    "\n7) Establecer Km "<<
    "\n8) Establecer Asientos "<<
    "\n9) Dejar todos los asientos vacios "<<
    "\n\n---= Acceso de informacion de vuelos =----"<<
    "\n\n10) Obtener fecha "<<
    "\n11) Obtener hora "<<
    "\n12) Obtener precio "<<
    "\n13) Obtener destino "<<
    "\n14) Obtener aerolinea "<<
    "\n15) Obtener km "<<
    "\n16) Obtener asientos "<<
    "\n\n---= Acciones adicionales para vuelos =----"<<
    "\n\n17) Desplegar info vuelo "<<
    "\n18) Muestra asientos disponibles "<<
    "\n19) Incrementa Asientos "<<
    "\n20) Decrementa Asientos "<<
    "\n21) Reservar Asiento "<<
    "\n22) Quitar Reserva Asiento "<<
    "\n23) Muestra lista de pasajeros del vuelo"<<
    "\n24) Verificar disponibilidad asiento "<<
    "\n\n---= Mostrar vuelos =----"<<
    "\n\n25) Imprimir Vuelos "<<
    "\n\n---= Salir del sistema =----"<<
    "\n\n0) Terminar "<<
    "\n\nTeclea la opcion: >";
    cin>>iOpcion;
    return iOpcion;
}

//Nombre:menuPrincipal
//Descripcion:  Regresar la opcion del menu e impresion del mismo
//              
//Entrada:
//          
//Salida:
//        seleccion del menu
int menuPrincipal(){
    int iOpcion;
    cout<<"------------------= Control de vuelos CDMX - Aeropuerto Benito Juarez =------------------"<<
    "\n\n1) Clientes"<<
    "\n2) Vuelos"<<
    "\n0) Terminar"<<
    "\n\nTeclea la opcion: >";
    cin>>iOpcion;
    return iOpcion;
}

//Acciones Pasajeros

//Nombre:pasajeros
//Descripcion:  Realiza operaciones a partir de input para pasajeros
//              
//Entrada:
//          
//Salida:
//        
void pasajeros(){
    bool continueg =true; //Variable controladora para continuar loop
    int option; //seleccion
    int userid; //id del usuario
    string nuser,celular,contrasena;//Variables para las credenciales de usuario
    while (continueg){
        option = menuPasajeros();
        cout<<jump;
        switch (option){
            case 1:
                crearUsuario();
                break;
            case 2:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nuevo nombre: >";
                    cin>>nuser;
                    Pasajeros[userid].setName(nuser);
                    cout<<"Nombre cambiado exitosamente!"<<endl;
                }
                break;
            case 3:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nuevo celular: >";
                    cin>>celular;
                    Pasajeros[userid].setName(celular);
                    cout<<"Celular cambiado exitosamente!"<<endl;
                }
                break;
            case 4:
                userid = login();
                if(userid!=-1){
                    cout<<"Ingresar nueva contrasena: >";
                    cin>>contrasena;
                    Pasajeros[userid].setName(contrasena);
                    cout<<"Contrasena cambiada exitosamente!"<<endl;
                }
                break;
            case 5:
                userid = login();
                if(userid!=-1){
                    cout<<"Nombre: "<<Pasajeros[userid].getName()<<endl;
                }
                break;
            case 6:
                userid = login();
                if(userid!=-1){
                    cout<<"Celular: "<<Pasajeros[userid].getCel()<<endl;
                }
                break;
            case 7:
                userid = login();
                if(userid!=-1){
                    cout<<"Km: "<<Pasajeros[userid].getKm()<<endl;
                }
                break;
            case 8:
                userid = login();
                if(userid!=-1){
                    cout<<"Email: "<<Pasajeros[userid].getEmail()<<endl;
                }
                break;
            case 9:
                userid = loginSC();
                if(userid!=-1){
                    cout<<"Contrasena: "<<Pasajeros[userid].getPassword()<<endl;
                }
                break;
            case 10:
                userid = login();
                if(userid!=-1){
                    Pasajeros[userid].incrementaKm();
                    cout<<"Se han anadido km a su cuenta exitosamente!"<<endl;
                }
                break;
            case 11:
                    Pasajeros[userid].incrementaKm();
                    cout<<"Se han decrementado km a su cuenta exitosamente!"<<endl;
                break;
            case 12:
                printdata();
                break;
            case 0:
                continueg = false;
                cout<<"Hasta luego!"<<endl;
                break;
            default:
                cout<<"Opcion no valida, volver a intentar"<<endl;
                break;
        }
        recordData();
        cout<<jump;
    }
}

//ACCIONES VUELOS

//Nombre:vuelos
//Descripcion:  Realiza operaciones a partir de input para vuelos
//              
//Entrada:
//          
//Salida:
//        
void vuelos(){
    int i9,j22;//variables contadoras para caso 9 (i9) y 22(i9,j22)
    bool continueg =true;//Variable controladora para loop
    bool continueg2 = true;//Variable controladora para loop
    int newid;//Variable para nuevo id
    int option,userid,fila,col,posi,posj; //Variables para posiciones y opciones
    int vueloid,dia,mes,ano,hora,minuto,iPrecio,ikm;//Variables para objeto
    string iDestino,Aerolinea,situation,myText;
    Fecha Fecha;
    RelojD Hora;
    bool accept = false; //Variable determinadora de accion
    char accepting; //variable determinadora de accion
    while (continueg){
        option = menuVuelos();
        cout<<jump;
        switch (option){
            case 1:
                crearVuelo();
                break;
            case 2:
                vueloid = loginVuelo();
                cout<<"Ingresar Dia: >";cin>>dia;
                cout<<"Ingresar Mes: >";cin>>mes;
                cout<<"Ingresar Ano: >";cin>>ano;
                if (vueloid !=-1){
                    Fecha.setDia(dia);
                    Fecha.setMes(dia);
                    Fecha.setYear(ano);
                    Vuelos[vueloid].setFecha(Fecha);
                }
                break;
            case 3:
                vueloid = loginVuelo();
                cout<<"Ingresar Hora: >";cin>>hora;
                cout<<"Ingresar Minuto: >";cin>>hora;
                if (vueloid !=-1){
                    Hora.setHoras(hora);
                    Hora.setMinutos(minuto);
                    Vuelos[vueloid].setHora(Hora);
                }
                break;
            case 4:
                vueloid = loginVuelo();
                cout<<"Ingresar Precio: >$";cin>>iPrecio;
                if (vueloid !=-1){
                    Vuelos[vueloid].setPrecio(iPrecio);
                }
                break;
            case 5:
                vueloid = loginVuelo();
                cout<<"Ingresar Destino: >";cin>>iDestino;
                if (vueloid !=-1){
                    Vuelos[vueloid].setDestino(iDestino);
                }
                break;
            case 6:
                vueloid = loginVuelo();
                cout<<"Ingresar Aerolinea: >";cin>>Aerolinea;
                if (vueloid !=-1){
                    Vuelos[vueloid].setAerolinea(Aerolinea);
                }
                break;
            case 7:
                vueloid = loginVuelo();
                cout<<"Establecer Km: >";cin>>ikm;
                if (vueloid !=-1){
                    Vuelos[vueloid].setKilometros(ikm);
                }
                break;
            case 8:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    for (int i = 0; i < 30; i++){ //se itera en toda la matriz ingresando los ids
                        for (int j = 0; j < 4; j++){
                            cout<<"Ingresa el id para fila ("<<i<<") columna "<<j<<": >";
                            cin>>newid;
                            Vuelos[vueloid].setReservaAsiento(i,j,newid);
                            cout<<endl;
                            cout<<"Deseas seguir agregando asientos? (s/n): >";//se pregunta si se desea seguir anadiendo asientos
                            cin>>situation;
                            if (situation =="n"||situation=="N"){
                                j=4;//se termina la accion
                                i=30;
                            }
                            
                        }
                    }
                }
                break;
            case 9:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<"Deseas eliminar a todos del vuelo? (s/n) >";
                    cin>>accepting;//se pregunta si se desea eliminar todos los pasajeros
                    if(accepting == 's'|| accepting =='S'){
                        ifstream MyReadFile3("vuelo"+to_string(vueloid)+".txt");
                        i9=0;
                        while(getline (MyReadFile3, myText)&&i9<30) {//se lee el archivo, busca ids y resta kms
                            stringstream ss(myText); 
                            string word; 
                            ss >> word;
                            if(stoi(word)!=-1){
                                for(int ikmi = 0;ikmi<Vuelos[vueloid].getKilometros();ikmi++){//decrementa km a partir de cantidad del vuelo
                                    Pasajeros[stoi(word)].decrementakm();
                                }
                            }
                            i9++;
                        }
                        MyReadFile3.close();
                        for(int i = 0;i<30;i++){
                            for(int j = 0;j<4;j++){
                                Vuelos[vueloid].setReservaAsiento(i,j,-1); //se establecen como vacios
                            }
                        }
                        Vuelos[vueloid].setAsientos(0);
                    }
                }
                break;
            case 10:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getFecha().str()<<endl;
                }
                break;
            case 11:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getHora().str()<<endl;
                }
                break;
            case 12:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getPrecio()<<endl;
                }
                break;
            case 13:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getDestino()<<endl;
                }
                break;
            case 14:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getAerolinea()<<endl;
                }
                break;
            case 15:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].getKilometros()<<endl;
                }
                break;
            case 16:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<"\nAsientos en el vuelo: "<<Vuelos[vueloid].getAsientos()<<endl;
                    Vuelos[vueloid].muestraAsientosDisponibles();
                }
                break;
            case 17:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    cout<<Vuelos[vueloid].str()<<endl;
                }
                break;
            case 18:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    Vuelos[vueloid].muestraAsientosDisponibles();
                }
                break;
            case 19:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    Vuelos[vueloid].incrementaAsientos();
                    cout<<"\nSe elimino una reservacion de manera artificial!"<<endl;
                }
                break;
            case 20:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    Vuelos[vueloid].incrementaAsientos();
                    cout<<"\nSe agrego una reservacion de manera artificial!"<<endl;
                }
                break;
            case 21:
                userid = login();
                if(userid !=-1){
                    int india,inmes,iano;
                    cout<<"Ingresar dia: >";cin>>india;
                    cout<<"Ingresa mes: >";cin>>inmes;
                    cout<<"Ingresa ano: >";cin>>iano;
                    cout<<"\nVuelos disponibles:"<<endl;
                    printdataDate(india,inmes,iano);
                    cout<<endl;

                    vueloid = loginVueloDate(india,inmes,iano);
                    Vuelos[vueloid].muestraAsientosDisponibles();
                    cout<<endl;
                    cout<<"Para cancelar ingresar -1 en fila y columna"<<endl;
                    cout<<"Ingresar Fila: >";cin>>fila;
                    cout<<"Ingresar Columna: >";cin>>col;
                    if(fila ==-1&&col==-1 ||fila<0&&col<0||fila>30&&col>4){//se verifican los asientos y en caso de salir ingresar -1
                        cout<<"\nSe cancelo la operacion de reservacion"<<endl;
                    }
                    else{
                        if(Vuelos[vueloid].reservarAsiento(Pasajeros[userid],userid,fila,col)){
                            for(int i = 0;i<Vuelos[vueloid].getKilometros();i++){//se incrementan km
                                Pasajeros[userid].incrementaKm();
                            }
                        }
                    }
                }
                break;
            case 22:
                userid = login();
                if(userid !=-1){
                    cout<<"Ingresar datos del vuelo donde se cancelara la reservacion:"<<endl;
                    vueloid = loginVuelo();
                    if (vueloid !=-1){
                        //verificar que este el usuario en el vuelo, si si, guardar la posicion
                        //eliminar ese asiento y quitar los kilometros
                        ifstream MyReadFile3("vuelo"+to_string(vueloid)+".txt");
                        i9=0;
                        j22=0;
                        while(getline (MyReadFile3, myText)&&i9<30) {
                            stringstream ss(myText); 
                            while(j22<4){
                                string word; 
                                ss >> word;
                                Vuelos[vueloid].setReservaAsiento(i9,j22,stoi(word));
                                if(stoi(word)!=-1&&stoi(word)==userid){
                                    Vuelos[vueloid].derementaAsientos();//Resta al numero de pasajeros
                                    Vuelos[vueloid].setReservaAsiento(i9,j22,-1);//Deja el lugar vacio
                                    for(int ikmi = 0;ikmi<Vuelos[vueloid].getKilometros();ikmi++){
                                        Pasajeros[userid].decrementakm();//Se quitan los km al pasajero
                                    }
                                    cout<<"\nSe elimino su asiento en la fila "<<i9<<" columna "<<j22<<" con exito!"<<endl;
                                }
                                j22++;
                            }
                            j22=0;
                            i9++;
                        }
                        MyReadFile3.close();
                    }
                }
                break;
            case 23:
                vueloid = loginVuelo();
                if (vueloid !=-1){
                    Vuelos[vueloid].muestraListaPasajeros(Pasajeros);
                }
                break;
            case 24:
                userid = login();
                if(userid !=-1){
                    vueloid = loginVuelo();
                    Vuelos[vueloid].asientoDisponible(fila,col);
                }
                break;
            case 25:
                printdata2();
                break;
            case 0:
                continueg = false;
                cout<<"\nHasta luego!"<<endl;
                break;
            default:
                cout<<"\nOpcion no valida, volver a intentar"<<endl;
                break;
        }
        recordData();
        cout<<jump;
    }
}

//MAIN
int main(){
    bool continueg = true;
    int suboption2;
    filldata(); //se lee todos los usuarios,vuelos y se insertan en el vector
    while(continueg){
        cout<<jump;
        int option1 = menuPrincipal();//se ejecuta el menu principal
        cout<<jump;
        switch (option1){
        case 1:
            pasajeros();//en caso de la seleccion de pasajeros se llama al metodo
            break;
        case 2:
            vuelos();//en caso de la seleccion de vuelos se llama al metodo
            break;
        case 0:
            continueg = false;
            cout<<jump;
            cout<<"\n----------= Hasta luego! =----------"<<endl;
            break;
        default:
            cout<<jump;
            cout<<"\nOpcion no valida, volver a intentar"<<endl;
            break;
        }
    }
    return 0;
}