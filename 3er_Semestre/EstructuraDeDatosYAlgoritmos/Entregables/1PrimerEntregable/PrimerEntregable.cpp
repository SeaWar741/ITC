//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <stdio.h>
#include <sstream>
#include <ctime>
#include <map>

#include <unistd.h> // for sleep()


using namespace std;

map<string, int> months; //map para los codigos de mes y numero de mes
map<int, string> monthsReversed; //mapa con key value invertidas al map original

int monthDuration[12] = {31,28,29,31,30,31,30,31,31,30,30,31}; //duracion maxima de cada mes

//--------------------------------Super helper functions------------------------------

//Fncion para imprimir linea
void line(){
    cout<<"----------------------------------------------------"<<endl;
}

//Funcion de efecto de loading
void loading(){
    sleep(1);//duerme cada segundo y hace cout de un punto
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
}

//--------------------------------Struct declaration---------------------------------

//Estructura de datos de registro
struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string error;
    
    //Funcion para verificar igualdades de fecha
    bool dateIsEqual(RegistryEntry const & entry) const {
        if( (months[month] == months[entry.month] && day==entry.day) && hour == entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar menor fecha y hora
    bool dateIsMinor(RegistryEntry const & entry) const{
        if(months[month] < months[entry.month]){
            return true;
        }
        if(months[month] == months[entry.month] && day < entry.day){
            return true;
        }
        if(months[month] == months[entry.month] && day == entry.day && hour < entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar menor hora
    bool hourIsMinor(RegistryEntry const & entry) const{
        if(hour<=entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar mayors hora
    bool hourIsMajor(RegistryEntry const & entry) const{
        if(hour>=entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

    //Funcion para verificar igualdad de hora
    bool hourIsEqual(RegistryEntry const & entry) const{
        if(hour == entry.hour){
            return true;
        }
        else{
            return false;
        }
    }

};

//-----------------------------Struct helper functions---------------------------------

//Funcion para llenar valores del map de meses
void populateMonths(){
    months.insert(pair<string, int>("Jan", 1)); 
    months.insert(pair<string, int>("Feb", 2)); 
    months.insert(pair<string, int>("Mar", 3)); 
    months.insert(pair<string, int>("Apr", 4)); 
    months.insert(pair<string, int>("May", 5)); 
    months.insert(pair<string, int>("Jun", 6)); 
    months.insert(pair<string, int>("Jul", 7));
    months.insert(pair<string, int>("Aug", 8)); 
    months.insert(pair<string, int>("Sep", 9)); 
    months.insert(pair<string, int>("Oct", 10)); 
    months.insert(pair<string, int>("Nov", 11)); 
    months.insert(pair<string, int>("Dic", 12));
}

//Funcion para invertir key y value de mapa de meses
void populateMonthsReversed(){ //
    for (auto i=months.begin(); i!=months.end(); ++i)
    monthsReversed[i->second] = i->first;
}

//Funcion para desplegar entry 
void printEntry(RegistryEntry entry){
    cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    //cout<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<<endl;
}

//Funcion para convertir en string un entry formateado
string stringEntry(RegistryEntry entry){
    //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    stringstream ss;
    //ss<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<< "\n";
    ss<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<< "\n";
    return ss.str();
}

//Funcion para imprimir todas las entries de logs
void printEntries(vector<RegistryEntry> list){
    cout<<endl<<"-----------=Query Result=-----------"<<endl<<endl;
    for (int i = 0; i < list.size(); i++){
        printEntry(list[i]);
    }
    
}

//Funcion para ver si una entry es previa a otra
bool isEarlier(RegistryEntry &first, RegistryEntry &last){
    if(months[first.month]>months[last.month]){
        //cout<<"comparison"<<endl;
        return true;
    }
    if(months[first.month]==months[last.month] && first.day>last.day){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour>last.hour){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour==last.hour && first.minute>last.minute){
        return true;
    }
    if(months[first.month]==months[last.month] && first.day==last.day&& first.hour==last.hour && first.minute==last.minute && first.second>last.second){
        return true;
    }
    else{
        //cout<<"comparison failed"<<endl;
        return false;
    }
}

//O(n)
//Funcion para dividir string por token o separador
vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

//O(n)
//Funcion para pasar a lowercase string
string toLowerCase(string str) {

    int str_len = str.length();

    string final_str = "";

    for(int i=0; i<str_len; i++) {

        char character = str[i];

        if(character>=65 && character<=92) {

            final_str += (character+32);

        } else {

            final_str += character;

        }

    }

    return final_str;

}

//Funcion para formatear el string de una fecha para ser valido
string monthFormater(string txt){
    string txtMod = toLowerCase(txt);
    txtMod[0] = toupper(txtMod[0]);//se hace uppercase la primer letra
    return txtMod;
}

//-------------------------------------Sort functions---------------------------------

//Funcion merge para merge sort a 
//partir de comparasion con fechas
template <class T>
void merge(vector<T> &list,int left,int middle,int right){
    int i = 0, j =0;
    int counter =left;
    vector<T> vectorLeft, vectorRight;

    //Copy to new vectors
    for(int iter1 = left; iter1 <= middle; iter1++){
        vectorLeft.push_back(list[iter1]);
    }
    for(int iter2 = middle+1; iter2 <= right; iter2++){
        vectorRight.push_back(list[iter2]);
    }

    //
    while(i < (middle-left+1) && j < (right-middle)){
        //if(vectorLeft[i] > vectorRight[j]){
        if(isEarlier(vectorLeft[i],vectorRight[j])){ ///Key comparison by date
            list[counter] = vectorRight[j];
            j++;   
        } else{
            list[counter] = vectorLeft[i];
            i++;
        }
        counter++;
    }

    //
    while(i < (middle - left + 1)){
        list[counter] = vectorLeft[i];
        counter++;
        i++;
    }
    while(j < (right-middle)){
        list[counter] = vectorRight[j];
        counter++;
        j++;
    }
}

//O(nlogn)
//Merge Sort
template<class T>
void mergeSort(vector<T> &list,int left,int right){
    if(left<right){
        int middle = left + (right-left)/2;
        mergeSort(list,left,middle);
        mergeSort(list,middle+1,right);

        merge(list,left,middle,right);
    }
}


//-------------------------------------Search functions---------------------------------

//O(log n)
//Binary Search implementation for upper date query
int lowerIndexQuery(vector<RegistryEntry> &list,RegistryEntry &value){
    int low,high,mid;
    int result = -1;
    low = 0;
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        //if(list[mid] ==value){
        if(list[mid].dateIsEqual(value)){
            result = mid;
            high = mid-1;
        }
        else if(list[mid].dateIsMinor(value)){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }

    if(result != -1){
        return result;
    }
    
    string newMonth;
    int newDay;

    if(value.day<=monthDuration[months[value.month]-1]){
        newMonth = value.month;
        newDay = value.day+1;
    }
    else{
        newMonth = monthsReversed[months[value.month]+1];
        newDay = 1;
    }    

    RegistryEntry lower{ newMonth,newDay,0,0,0,"",""};

    return lowerIndexQuery(list,lower);
}


//O(log n)
//Binary Search implementation for lower date query
int upperIndexQuery(vector<RegistryEntry> &list,RegistryEntry &value){
    int low,high,mid;
    low = 0;
    int result = -1;
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        //if(list[mid] ==value){
        if(list[mid].dateIsEqual(value)){
            result =mid;
            low = mid+1;
        }
        else if(list[mid].dateIsMinor(value)){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
    }

    if(result != -1){
        return result;
    }

    string newMonth;
    int newDay;

    if(value.day<=monthDuration[months[value.month]-1] && (value.day-1)>0){
        newMonth = value.month;
        newDay = value.day-1;
    }
    else{
        newMonth = monthsReversed[months[value.month]-1];
        newDay = monthDuration[months[newMonth]-1];
    }    
    //cout<<newMonth<<" "<<newDay<<endl;
    RegistryEntry upper{ newMonth,newDay,0,0,0,"",""};

    return upperIndexQuery(list,upper);
}

//O(n)
//Query result from two binary search
string queryDates(vector<RegistryEntry> &list, int lower, int upper){
    string dates = "";
    for(int i = lower; i <=upper;i++){
        dates = dates + (stringEntry(list[i]));
    }
    return dates;
}


//-------------------------------------utility functions---------------------------------

//O(m)
//Funcion para imprimir lista completa
void print(vector<string> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<endl;
    }
    cout<<endl;
}

//Funcion para desplegar menu
void optionMenu(){
    cout<<endl;
    cout<<"1) Display full database"<<endl;
    cout<<"2) Search events by date"<<endl;
    cout<<"3) Exit"<<endl<<endl;
}

//Funcion para hacer query de una fecha
void fetchQuery(vector<RegistryEntry> &list){
    time_t rawtime;
    struct tm * timeinfo; //Se obtiene la fecha actual del sistema y se formatea para nombre de archivo
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H-%M-%S",timeinfo);
    std::string str(buffer); //fecha a un string

    string lowerMonth,upperM,save,fetched;
    int lowerDay,upperDay,inputHourLower,inputHourUpper;
    bool continues = false;

    while(!continues){
        cout<<"Ingresa las primeras 3 letras del mes inicial >";cin>>lowerMonth;
        lowerMonth = monthFormater(lowerMonth);
        cout<<"Ingresa el dia del mes inicial >";
        while(!(cin>>lowerDay)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<endl<<"Ingresa el dia del mes inicial >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<"Ingresa la hora >";
        while(!(cin>>inputHourLower)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<endl<<"Ingresa la hora >";
            cin.clear();
            cin.ignore(123,'\n');
        }

        cout<<endl<<"Ingresa las primeras 3 letras del mes final >";cin>>upperM;
        upperM = monthFormater(upperM);
        cout<<"Ingresa el dia del mes final >";
        while(!(cin>>upperDay)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Ingresa el dia del mes final >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<"Ingresa la hora >";
        while(!(cin>>inputHourUpper)){ //evitar loops por input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Ingresa la hora >";
            cin.clear();
            cin.ignore(123,'\n');
        }


        if(months.find(lowerMonth) == months.end() && months.find(upperM) == months.end()) {
            cout<<endl<<"INVALID INPUT"<<endl<<endl; //Si no se encuenrta en el rango de lista niega query
        }
        else{
            if(months[lowerMonth]<=months[upperM]){ //si los meses son un frame direccional de menor a mayor realiza query
                if( (lowerDay >0 && lowerDay<31) || (upperDay > 0 && lowerDay<31) ){
                    continues = true;
                }
                else{
                    cout<<endl<<"INVALID INPUT, VERIFY MONTH AND DESIRED DATES"<<endl<<endl;
                }
            }
            else{
                cout<<endl<<"INVALID INPUT, VERIFY MONTH AND DESIRED DATES"<<endl<<endl;
            }            
        }
    }
    
    cout<<endl<<"Would you like to save the result on a file (yes/no) >";cin>>save;

    save = toLowerCase(save);

    cout<<endl<<"-----------=Query Result=-----------"<<endl<<endl;

    RegistryEntry lower{lowerMonth,lowerDay,inputHourLower,0,0," "," "}; //crea una entrada lower con parameters input 

    RegistryEntry upper{upperM,upperDay,inputHourUpper,0,0," "," "};//crea una entrada upper con parameters input 

    try{
        if(months[lower.month]>=months[list[0].month] && months[upper.month]<=months[list[list.size()-1].month]){
            //verifica viabilidad de query a partir del rango
            int lowerIndex = lowerIndexQuery(list,lower);//realiza binary search para encontrar primer occurance en lista

            int upperIndex = upperIndexQuery(list,upper);//realiza binary search para encontrar final occurance de lista
            
            fetched = queryDates(list,lowerIndex,upperIndex); //realiza query de entries
            
            cout<<fetched<<endl; //imprime query

            if(save == "yes"){ //si se dijo yes se guarda output en log file con fecha y hora como nombre
                ofstream out(str+".txt");
                out << fetched;
                out.close();
            }
        }
        else{
            cout<<"QUERY COULDNT BE PERFORMED TIME FRAME NOT AVAILABLE"<<endl<<endl;
        }
    }catch(const exception& e){
        cout<<"QUERY COULDNT BE PERFORMED"<<endl<<endl;
    }
}


void menu(vector <RegistryEntry> list){
    cout<<endl<<endl;
    cout<<"8888      w 8          8    8               w       "<<endl;
    cout<<"8www .d88 w 8 .d88b .d88    8    .d8b. .d88 w 8d8b. "<<endl;
    cout<<"8    8  8 8 8 8.dP' 8  8    8    8' .8 8  8 8 8P Y8 "<<endl;
    cout<<"8    `Y88 8 8 `Y88P `Y88    8888 `Y8P' `Y88 8 8   8 "<<endl;
    cout<<"                                       wwdP         "<<endl;
    cout<<"888b.            w       w               "<<endl;
    cout<<"8  .8 .d88b .d88 w d88b w8ww 8d8b Yb  dP "<<endl;
    cout<<"8wwK' 8.dP' 8  8 8 `Yb.  8   8P    YbdP  "<<endl;
    cout<<"8  Yb `Y88P `Y88 8 Y88P  Y8P 8      dP   "<<endl;
    cout<<"            wwdP                   dP    "<<endl<<endl<<endl;

    line(); //estilo

    cout<<endl<<"Loading database ";
    
    loading();//animacion

    cout<<endl;

    //se imprimen datos del registry
    cout<<endl<<"SUCCESS: "<<list.size()<<" registries have been loaded "<<endl<<endl;
    cout<<"ENTRIES: ("<<list[0].month<<" - "<<list[list.size()-1].month<<")"<<endl<<endl;
    line();

    bool continues = true;
    int selection;
    string lowerMonth,upperMonth;
    int saveQuery;


    while(continues){
        optionMenu();
        cout<<"Selection >";
        while(!(cin>>selection)){//Evitar loop input
            cout<<endl<<"ERROR: INVALID INPUT"<<endl<<endl;
            cout<<"Selection >";
            cin.clear();
            cin.ignore(123,'\n');
        }
        cout<<endl;
        switch (selection){//switch para la opcion 
            case 1:
                printEntries(list);//imprimir registry ordenado
                cout<<endl;
                line();
                break;
            case 2:
                fetchQuery(list);//realizar query
                cout<<endl;
                line();
                break;
            case 3:
                continues=false; //cerrar programa
                break;
            default:
                cout<<endl;
                line();
                cout<<endl<<"OPCION NO VALIDA"<<endl<<endl;
                line();
                break;
        }
    }
    cout<<endl;
    line();
    cout<<endl<<"FAILED LOGIN REGISTRY | TERMINATED SUCCESSFULLY"<<endl<<endl;
    line();
}

//-------------------------------------main program---------------------------------
int main(){
    populateMonths();//se llenan los meses
    populateMonthsReversed();

    ifstream file("./bitacora.txt"); //abre el archivo
    vector <RegistryEntry> entries; //vector para registry

    if(file.is_open()){
        string line;
        vector<string> words; //vector para almacenar palabras de entry
        vector<string> time;    //vector para el tiempo
        string errorString = "";    //string para el error

        int i =0;
        while(getline(file,line)/* && i<=20*/){ //Se leen todos las entries por linea
            words = split(line," ");
            //print(words);
            RegistryEntry entry; //se crea entry y se hace split de elementos para llener el struct
            entry.month = words[0];
            entry.day = stoi(words[1]);
            time = split(words[2],":");
            entry.hour = stoi(time[0]);//
            entry.minute = stoi(time[1]);
            entry.second = stoi(time[2]);
            entry.ip = words[3];
            for (int i = 4; i < words.size(); i++){ //todos los elementos posteriores son parte del error de login
                if(i !=4 && i !=words.size()){
                    errorString= errorString+ " " + words[i];
                }
                else{
                    errorString+=words[i];
                };
            }
            
            entry.error = errorString;
            entries.push_back(entry);//se inserta en vector
            errorString = "";
            words.clear();
            time.clear();

            i++;
        }
        file.close();
    }

    mergeSort(entries,0,entries.size()-1); //se ordenan las entries

    menu(entries);

    return 0;
}

