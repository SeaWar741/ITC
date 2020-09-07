//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>


using namespace std;

map<string, int> months; 

struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string error;
};

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

void printEntry(RegistryEntry entry){
    cout<<entry.month<<"|"<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<endl;
    //<<"<<entry.ip<<"| "<<entry.error<<endl;
}

void printEntries(vector<RegistryEntry> list){
    for (int i = 0; i < list.size(); i++){
        printEntry(list[i]);
    }
    
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

//Merge Sort
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
        if(isEarlier(vectorLeft[i],vectorRight[j])){ ///Key comparison
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

template<class T>
void mergeSort(vector<T> &list,int left,int right){
    if(left<right){
        int middle = left + (right-left)/2;
        mergeSort(list,left,middle);
        mergeSort(list,middle+1,right);

        merge(list,left,middle,right);
    }
}


//O(log n)
//Binary Search
template<class T>
int binarySearch(vector<T> list,T value){
    int low,high,mid;
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
    }
    return -1;
}




// utility functions
void print(vector<string> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<endl;
    }
    cout<<endl;
}


//main programm
int main(){
    populateMonths();

    ifstream file("./bitacora.txt");
    vector <RegistryEntry> entries;

    if(file.is_open()){
        string line;
        vector<string> words;
        vector<string> time;
        string errorString = "";

        int i =0;
        while(getline(file,line)&& i<=20){
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

    cout<<endl<<"UnSortedList"<<endl;
    //printEntries(entries);

    cout<<endl<<"Sorted entries"<<endl;

    mergeSort(entries,0,entries.size()-1);

    printEntries(entries);
    

    return 0;
}
