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

map<string, int> months;
map<int, string> monthsReversed;

int monthDuration[12] = {31,28,29,31,30,31,30,31,31,30,30,31};

//--------------------------------Super helper functions------------------------------


//--------------------------------Struct declaration---------------------------------
struct RegistryEntry{
    string month;
    int day;
    int hour;
    int minute;
    int second;
    string ip;
    string error;
    
    bool dateIsEqual(RegistryEntry const & entry) const {
        if(months[month] == months[entry.month] && day==entry.day){
            return true;
        }
        else{
            return false;
        }
    }

    bool dateIsMinor(RegistryEntry const & entry) const{
        if(months[month] < months[entry.month]){
            return true;
        }
        if(months[month] == months[entry.month] && day < entry.day){
            return true;
        }
        else{
            return false;
        }
    }


};

//-----------------------------Struct helper functions---------------------------------
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

void populateMonthsReversed(){ //
    for (auto i=months.begin(); i!=months.end(); ++i)
    monthsReversed[i->second] = i->first;
}

void printEntry(RegistryEntry entry){
    //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    cout<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<<endl;
}

string stringEntry(RegistryEntry entry){
    //cout<<entry.month<<" "<<entry.day<<" "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<" "<<entry.ip<<" "<<entry.error<<endl;
    stringstream ss;
    ss<<entry.month<<"| "<<entry.day<<"| "<<entry.hour<<":"<<entry.minute<<":"<<entry.second<<"| "<<entry.ip<<"| "<<entry.error<< "\n";
    return ss.str();
}

void printEntries(vector<RegistryEntry> list){
    cout<<endl<<"-----------=Query Result=-----------"<<endl<<endl;
    for (int i = 0; i < list.size(); i++){
        printEntry(list[i]);
    }
    
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

string monthFormater(string txt){
    string txtMod = toLowerCase(txt);
    txtMod[0] = toupper(txtMod[0]);
    return txtMod;
}

//-------------------------------------Sort functions---------------------------------

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


//-------------------------------------Search functions---------------------------------

//O(log n)
//Binary Search implementation for upper date query
int lowerIndexQuery(vector<RegistryEntry> &list,RegistryEntry &value){
    int low,high,mid;
    low = 0;
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        //if(list[mid] ==value){
        if(list[mid].dateIsEqual(value)){
            return mid;
        }
        else if(list[mid].dateIsMinor(value)){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
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
    high = list.size();
    while (low<=high){
        mid = (low+high)/2;
        //if(list[mid] ==value){
        if(list[mid].dateIsEqual(value)){
            return mid;
        }
        else if(list[mid].dateIsMinor(value)){
            low = mid+1;
        }
        else{
            high = mid - 1;
        }
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


//
//Query result from two binary search
string queryDates(vector<RegistryEntry> &list, int lower, int upper){
    string dates = "";
    for(int i = lower; i <=upper;i++){
        dates = dates + (stringEntry(list[i]));
    }
    return dates;
}


//-------------------------------------utility functions---------------------------------
void print(vector<string> list){
    for (int i = 0; i < list.size(); i++){
        cout<<list[i]<<endl;
    }
    cout<<endl;
}

void optionMenu(){
    cout<<endl;
    cout<<"1) Display full database"<<endl;
    cout<<"2) Search events by date"<<endl;
    cout<<"3) Exit"<<endl<<endl;
}


void fetchQuery(vector<RegistryEntry> &list){
    time_t rawtime;
    struct tm * timeinfo;
    char buffer[80];

    time (&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,sizeof(buffer),"%d-%m-%Y %H-%M-%S",timeinfo);
    std::string str(buffer);

    string lowerMonth,upperM,save,fetched;
    int lowerDay,upperDay;
    bool continues = false;

    while(!continues){
        cout<<"Ingresa las primeras 3 letras del mes inicial >";cin>>lowerMonth;
        lowerMonth = monthFormater(lowerMonth);
        cout<<"Ingresa el dia del mes inicial >";cin>>lowerDay;

        cout<<endl<<"Ingresa las primeras 3 letras del mes final >";cin>>upperM;
        upperM = monthFormater(upperM);
        cout<<"Ingresa el dia del mes final >";cin>>upperDay;

        if(months.find(lowerMonth) == months.end() && months.find(upperM) == months.end()) {
            cout<<endl<<"INVALID INPUT"<<endl<<endl;
        }
        else{
            if(months[lowerMonth]<=months[upperM]){
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

    RegistryEntry lower{lowerMonth,lowerDay,0,0,0," "," "};

    RegistryEntry upper{upperM,upperDay,0,0,0," "," "};
    
    try{
        if(months[lower.month]>=months[list[0].month] && months[upper.month]<=months[list[list.size()-1].month]){
            int lowerIndex = lowerIndexQuery(list,lower);

            int upperIndex = upperIndexQuery(list,upper);
        
            
            fetched = queryDates(list,lowerIndex,upperIndex);
            
            cout<<fetched<<endl;

            if(save == "yes"){
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

    cout<<"Loading database ";
    
    /*
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    sleep(1);
    std::cout << "." << std::flush;
    */

    cout<<endl;

    cout<<endl<<"SUCCESS: "<<list.size()<<" registries have been loaded "<<endl<<endl;

    bool continues = true;
    int selection;
    string lowerMonth,upperMonth;
    int saveQuery;


    while(continues){
        optionMenu();
        cout<<"Selection >";
        cin>>selection;
        cout<<endl;
        switch (selection){
            case 1:
                printEntries(list);
                break;
            case 2:
                fetchQuery(list);
                break;
            case 3:
                continues=false;
                break;
            default:
                cout<<endl<<"OPCION NO VALIDA"<<endl<<endl;
                break;
        }
    }
    cout<<endl<<"FAILED LOGIN REGISTRY | TERMINATED SUCCESSFULLY"<<endl;
}

//-------------------------------------main program---------------------------------
int main(){
    populateMonths();
    populateMonthsReversed();

    ifstream file("./bitacora.txt");
    vector <RegistryEntry> entries;

    if(file.is_open()){
        string line;
        vector<string> words;
        vector<string> time;
        string errorString = "";

        int i =0;
        while(getline(file,line)/* && i<=20*/){
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

    mergeSort(entries,0,entries.size()-1);

    menu(entries);

    return 0;
}