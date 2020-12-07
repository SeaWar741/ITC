#include <iostream>
#include <string>
using namespace std;

int funHashing(string data,int size, int &key){
    key=0;
    for (auto c : data){
        key+=abs(int(c));
    }
    return key%size;
}

int main(){
    string data;
    int size=50;
    cout <<"Teclea un string de 4 caracteres"<<endl;
    cin>>data;

    int key;
    int index = funHashing(data,size,key);
    cout<<"Key: "<<key<<" Index: "<<index<<endl;    
    return 0;
}
