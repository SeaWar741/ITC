//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>

using namespace std;

//Variables globales para contar comparaciones
//de cada algoritmo
int seq = 0,binary = 0;

//O(n^2)
//insertion
template <class T>
vector<T> insertion(vector<T> list)  {  
    T key;
    int i, j;
    int comparaciones = 0,intercambios = 0;  
    for (i = 1; i < list.size(); i++) {  
        key = list[i];  
        j = i - 1;  

        comparaciones++;

        while (j >= 0 && list[j] > key){
            list[j + 1] = list[j];  
            j--;  
        }
        intercambios++;
        list[j + 1] = key;  
    }
    //cout<<"-Comparaciones: "<<comparaciones<<"\n-Intercambios: "<<intercambios<<endl<<endl;
    return list;  
}

//O(n)
template <class T>
int sequential(vector<T> list,T element){
    int i=0;
    seq = 0;
    while(i<list.size()){
        if(list[i]==element){
            return i;
        }
        i++;
        seq++;
    }
    return -1;
    
}

//O(log n)
template<class T>
int binarySearch(vector<T> list,T value){
    int low,high,mid;
    binary = 0;
    low = 0;
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        if(list[mid]==value){
            return mid;
        }
        else if(list[mid]<value){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
        binary++;
    }
    return -1;
}

//O(n)
//Esta funcion crea un map a partir del vector dado
//se encarga de utilizar la letra como llave
//y como valor las repeticiones de la letra en el vector
template<class T>
T uniqueValue(vector<T> v){
    unordered_map<T, size_t> count;

    //Itera creando las llaves
    for (T i : v) {
        count[i]++;
    }

    //aplica un sort modificado
    //se toma el valor de count y se suma a partir
    //de la letra encontrada, ordenandolo con estas codiciones
    // el vector queda ordendo a partir del map
    // quedando en la ultima posicion el que tenga menos repeticiones
    sort(
        v.begin(), 
        v.end(),
        [&count](T const& a, T const& b) {
        if (a == b) {
            return false;
        }
        if (count[a] > count[b]) {
            return true;
        }
        else if (count[a] < count[b]) {
            return false;
        }
        return a < b;
    });
    //si el valor de la izquierda no es igual al ultimo regresa
    //el valor, siendo el valor unico
    if(v.back() !=v[v.size()-2]){
        return v.back();
    }else{
        //en caso de que se cumpla, no hay elemento unico
        throw runtime_error("NO HAY UN ELEMENTO UNICO");
    }        
}


//O(n)
//Imprimir vector
template <class T>
void print(vector<T> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<'\t';
    }
    cout<<endl<<endl;
}

int main(){
    vector <string> files = {"01","02","03","04"};//vector con los nombres de archivos a evaluar
    char unique; //char para el valor unico
    string input="";//string para escribir en el txt
    for (auto i : files){// para cada string del vector
        ifstream file("./Inputs/"+i+".in");//se abre el archivo y se lee
        string content;
        
        int counter = 0;//no se cuenta la primer linea ya que se lee hasta terminar las lineas del txt
        cout<<i<<".in"<<endl;
        while(file >> content) {//mientras existan lineas se lee
            if(counter != 0){//si no es la primera linea se ejecuta
                //cout<<"-------------------------------------------"<<endl;
                vector<char> v(content.begin(), content.end());//se pasa el string a un vector de chars
                //cout<<endl<<"Original:"<<endl;
                //print(v);
                //cout<<"Ordenado:"<<endl;
                v =insertion(v);//se ordenan por insertion sort
                //print(v);
                try{ //se trata de evaluar lo siguiente
                    unique = uniqueValue(v);//se busca el valor unico (aqui puede suceder el error si no hay)
                    /*
                    cout<<"Unico:"<<endl;
                    cout<<uniqueValue(v)<<endl;
                    cout<<"Sequential search:"<<endl;
                    cout<<sequential(v,uniqueValue(v))<<endl;
                    cout<<"Binary search:"<<endl;
                    cout<<binarySearch(v,uniqueValue(v))<<endl;
                    */
                    sequential(v,unique);//se ejecuta sequential sort
                    binarySearch(v,unique);//se ejecuta binary search
                    cout<<unique<<" "<<seq<<" "<<unique<<" "<<binary<<endl; //se imprime las comparaciones necesarias
                    
                    input += unique+" "+to_string(seq)+" "+unique+" "+to_string(binary)+"\n"; //se a;ade al string del .out el output
                    ofstream out("./Outputs/"+i+".out");//se crea un archivo en el directorio
                    out << input;//se inserta el string en el ofstream
                    out.close();//se cierra el archivo

                }catch(runtime_error& e){
                    cout<<e.what()<<endl;//en caso de error se menciona que no hay unico
                }
            }
            
            counter++;//se suma el counter

        }
        cout<<endl<<endl;//para crear separacion
    }
    

    /*
    ifstream file("01.in");
    string content;
    
    int counter = 0;
    while(file >> content) {
        if(counter != 0){
            cout<<"-------------------------------------------"<<endl;
            vector<char> v(content.begin(), content.end());
            cout<<endl<<"Original:"<<endl;
            print(v);
            cout<<"Ordenado:"<<endl;
            v =insertion(v);
            print(v);
            cout<<"Unico:"<<endl;
            cout<<uniqueValue(v)<<endl;
            cout<<"Sequential search:"<<endl;
            cout<<sequential(v,uniqueValue(v))<<endl;
            cout<<"Binary search:"<<endl;
            cout<<binarySearch(v,uniqueValue(v))<<endl;
        }
        counter++;

    }
    */
    return 0;
}
