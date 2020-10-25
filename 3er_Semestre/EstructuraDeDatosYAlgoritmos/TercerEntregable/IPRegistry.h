#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

struct IPRegistry{
    string ip;
    int frequency = 0;
    vector<string> errors;


    string stringifyErrors(){
        string output ="";
        // Define an map 
        map<string, int> frequencies; 
        // Traverse vector vec check if 
        // current element is present 
        // or not 
        for (int i = 0; i< errors.size(); i++) { 
    
            // If the current element 
            // is not found then insert 
            // current element with 
            // frequency 1 
            if (frequencies.find(errors[i]) == frequencies.end()) { 
                frequencies[errors[i]] = 1; 
            } 
    
            // Else update the frequency 
            else { 
                frequencies[errors[i]]++; 
            } 
        } 
    
        // Traverse the map to print the 
        // frequency 
        output+="{";
        for (auto& it : frequencies) { 
            output+= it.first + ':'+ to_string(it.second)+ ','; 
            cout << it.first << ' '
             << it.second << '\n'; 
        }
        output+="}";
        return output; 
    }

    friend ostream &operator<<( ostream &output, IPRegistry &D ) { 
        //string errors = D.errors.stringify();
        output << "{IP:"<<D.ip <<", Frequency:"<<D.frequency<<", Errors:"<<D.stringifyErrors()<<"}"<<endl;
        return output;            
    }
    

    bool operator <( const IPRegistry& rhs ) const{
        if(ip < rhs.ip){return true;}
        else{return false;}
    }
    bool operator >( const IPRegistry& rhs ) const{
        if(ip < rhs.ip){return true;}
        else{return false;}
    }
    bool operator <=( const IPRegistry& rhs ) const{
        if(ip <= rhs.ip){return true;}
        else{return false;}
    }
    bool operator >=( const IPRegistry& rhs ) const{
        if(ip >= rhs.ip){return true;}
        else{return false;}
    }
    bool operator ==( const IPRegistry& rhs ) const{
        if(ip == rhs.ip){return true;}
        else{return false;}
    }
    bool operator !=( const IPRegistry& rhs ) const{
        if(ip != rhs.ip){return true;}
        else{return false;}
    }
    //FOR HEAP
    bool minor( const IPRegistry& rhs ) const{
        if(frequency < rhs.frequency){return true;}
        else{return false;}
    }

    bool minorEqual( const IPRegistry& rhs ) const{
        if(frequency <= rhs.frequency){return true;}
        else{return false;}
    }

    bool major( const IPRegistry& rhs ) const{
        if(frequency > rhs.frequency){return true;}
        else{return false;}
    }

    bool majorEqual( const IPRegistry& rhs ) const{
        if(frequency >= rhs.frequency){return true;}
        else{return false;}
    }

    bool equal( const IPRegistry& rhs ) const{
        if(frequency == rhs.frequency){return true;}
        else{return false;}
    }
};



