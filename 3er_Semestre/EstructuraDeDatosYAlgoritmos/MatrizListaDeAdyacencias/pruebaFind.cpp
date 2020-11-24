//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> list = {1,2,3,4,5};

    vector<int>::iterator it;//crear iterador

    it = find(list.begin(),list.end(),3);//busqueda en la lista
    
    if(it != list.end()){
        cout<<"Found in position "<< it -list.begin()<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    return 0;
}
