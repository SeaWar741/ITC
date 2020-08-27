#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm> 
#include <unordered_map>

using namespace std;

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
template<class T>
T uniqueValue(vector<T> v){
    unordered_map<T, size_t> count;

    for (T i : v) {
        count[i]++;
    }

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
    if(v.back() !=v[v.size()-2]){
        return v.back();
    }else{
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
    vector <string> files = {"01","02","03","04"};
    char unique;
    string input="";
    for (auto i : files){
        ifstream file("./Inputs/"+i+".in");
        string content;
        
        int counter = 0;
        cout<<i<<".in"<<endl;
        while(file >> content) {
            if(counter != 0){
                //cout<<"-------------------------------------------"<<endl;
                vector<char> v(content.begin(), content.end());
                //cout<<endl<<"Original:"<<endl;
                //print(v);
                //cout<<"Ordenado:"<<endl;
                v =insertion(v);
                //print(v);
                try{
                    unique = uniqueValue(v);
                    /*
                    cout<<"Unico:"<<endl;
                    cout<<uniqueValue(v)<<endl;
                    cout<<"Sequential search:"<<endl;
                    cout<<sequential(v,uniqueValue(v))<<endl;
                    cout<<"Binary search:"<<endl;
                    cout<<binarySearch(v,uniqueValue(v))<<endl;
                    */
                    sequential(v,unique);
                    binarySearch(v,unique);
                    cout<<unique<<" "<<seq<<" "<<unique<<" "<<binary<<endl;
                    
                    input += unique+" "+to_string(seq)+" "+unique+" "+to_string(binary)+"\n";
                    ofstream out("./Outputs/"+i+".out");
                    out << input;
                    out.close();

                }catch(runtime_error& e){
                    cout<<e.what()<<endl;
                }
            }
            
            counter++;

        }
        cout<<endl<<endl;
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
