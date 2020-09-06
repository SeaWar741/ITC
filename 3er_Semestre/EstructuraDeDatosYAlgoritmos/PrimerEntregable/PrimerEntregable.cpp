#include <iostream>
#include <string>
#include <fstream>
#include <vector>


using namespace std;

struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string error;
};

void printEntry(RegistryEntry entry){
    cout<<entry.month<<"|"<<entry.day<<"|"<<entry.hour<<"|"<<entry.minute<<"|"<<entry.second<<"|"<<entry.ip<<"|"<<entry.error<<endl;
}

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

void print(vector<string> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<endl;
    }
    cout<<endl;
}

int main(){

    ifstream file("./bitacora.txt");
    vector <RegistryEntry> entries;

    if(file.is_open()){
        string line;
        vector<string> words;
        vector<string> time;
        string errorString = "";

        int i =0;
        while(getline(file,line)&& i <6){
            words = split(line," ");
            //print(words);
            RegistryEntry entry;
            entry.month = words[0];
            entry.day = stoi(words[1]);
            time = split(words[2],":");
            entry.hour = stoi(time[0]);//
            entry.minute = stoi(time[1]);
            entry.second = stoi(time[2]);
            entry.ip = words[3];
            for (int i = 4; i < words.size(); i++){
                if(i !=4 && i !=words.size()){
                    errorString= errorString+ " " + words[i];
                }
                else{
                    errorString+=words[i];
                };
            }
            
            entry.error = errorString;
            entries.push_back(entry);
            errorString = "";
            words.clear();
            time.clear();

            i++;
        }
        file.close();
    }

    for (int i = 0; i < entries.size(); i++){
        printEntry(entries[i]);
    }
    

    return 0;
}
