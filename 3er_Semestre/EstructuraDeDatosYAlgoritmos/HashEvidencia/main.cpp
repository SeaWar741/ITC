//Juan Carlos Garfias Tovar, A01652138

#include "Hash.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;


int checkInt(){
    int num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again: ";
            cin >> num;
        }
        if(!cin.fail()){
            break;
        }
    }
    return num;
}


int checkIntR(int min, int max){
    int num;
    cin >> num;
    while(1){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Input must be a number.. try again: ";
            cin >> num;
        }
        if(!cin.fail()){
            if(num < min || num > max){
                cout << "Enter a valid number: ";
                cin >> num;
            } else{
                break;
            }
        }
    }
    return num;
}


void split(vector<string> &vect, string str, string pattern){
    int beg = 0, end = 0;
    string value;
    while(end >= 0){
        end = int(str.find(pattern, beg));
        vect.push_back(str.substr(beg, end - beg));
        beg = end + 1;
    }
}


void getErrorData(string &str, vector<string> values){
    str = values[4];
    for(int i = 5; i < values.size(); i++){
        str = str + " " + values[i];
    }
}


void readIps(Hash<string> &hash){
    ifstream file("bitacora.txt");
    if(file){
        string line;
        vector<string> lengths;
        int count = 0;  
        while(getline(file, line) && count < hash.getSize()){
            if(count != 0){
                hash.insert(line);
            }
            count++;
        }
    } else{
        throw runtime_error("Error (readIps): error opening file (bitacora");
    }
    file.close();
}


void readEdges(Hash<string> &hash){
    ifstream file("bitacora.txt");
    if(file){
        string line, ip, ipAd;
        vector<string> values; //initialize necessary vectors and variables
        vector<string> ipData;
        int count = 0;
        while(getline(file, line)){
            if(count > hash.getSize()){
                split(values, line, " ");
                split(ipData, values[3], ":");
                ip = ipData[0];
                ipData.clear();

                split(ipData, values[4], ":");
                ipAd = ipData[0];
                hash.insertEdge(ip, ipAd); 
                values.clear();
                ipData.clear();
            }
            count++;
        }
    }
}


int getSize(){
    ifstream file("bitacora.txt");
    if(file){
        string line;
        getline(file, line);
        vector<string> lengths;
        split(lengths, line, " ");
        return stoi(lengths[0]);
    }
    return 0;
}


bool isIP(string key){
    int beg = 0, end = 0, count = -1;
    while(end >= 0){
        end = int(key.find(".", beg));
        beg = end + 1;
        count++;
    }
    return count == 3;
}


int menu(){
    cout << "\n\nEnter option\n";
    cout << "1. Search IP\n";
    cout << "2. Exit\n";
    return(checkIntR(1,2));
}

int main(){
    Hash<string> hash(getSize()+1);
    try{
        cout << "Reading Elements";
        readIps(hash);
        cout<<"error en edges"<<endl;
        //readEdges(hash);



    } catch(runtime_error &e) {
        cout << e.what();
    }
    

    return 0;
}