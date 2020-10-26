//Juan Carlos Garfias Tovar, A01652138
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h> 
#include <algorithm>
using namespace std;

//Struct IPRegistry
//almacenar ips, frecuencia, errores y puertos
struct IPRegistry{
    string ip;
    int frequency = 0;
    vector<string> errors;
    vector<string> ports;


    //stringifyErrors
    //obtener string de los errores de un map de frecuencia
    //O(n)
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
        int counter = frequencies.size();
        for (auto& it : frequencies) { 
            output+= '\u0022'+it.first + '\u0022'+':'+ to_string(it.second); 
            if(counter >1){
                output += ",";
            }
            counter--;
        }
        output+="}";
        return output; 
    }

    //stringifyPorts
    //obtener string de los errores de un map de frecuencia
    //O(n)
    string stringifyPorts(){
        string output ="";
        // Define an map 
        map<string, int> frequencies; 
        // Traverse vector vec check if 
        // current element is present 
        // or not 
        for (int i = 0; i< ports.size(); i++) { 
    
            // If the current element 
            // is not found then insert 
            // current element with 
            // frequency 1 
            if (frequencies.find(ports[i]) == frequencies.end()) { 
                frequencies[ports[i]] = 1; 
            } 
    
            // Else update the frequency 
            else { 
                frequencies[ports[i]]++; 
            } 
        } 

        // Traverse the map to print the 
        // frequency 
        output+="{";
        int counter = frequencies.size();
        for (auto& it : frequencies) { 
            output+= '\u0022'+it.first +'\u0022'+ ": "+ to_string(it.second); 
            if(counter >1){
                output += ",";
            }
            counter--;
        }
        output+="}";
        return output; 
    }

    //sobrecarga
    //para cout
    friend ostream &operator<<( ostream &output, IPRegistry &D ) { 
        //string errors = D.errors.stringify();
        //output << "{"<<'"'<<"IP"<<'"'<<":"<<'"'<<D.ip <<'"'<<","<<'"'<<"Ports"<<'"'<<":"<<D.stringifyPorts()<<"," <<'"'<<"Frequency"<<'"'<<":"<<D.frequency<<","<<'"'<<"Errors"<<'"'<<":"<<D.stringifyErrors()<<"}"<<endl;
        cout<<"IP: "<<D.ip<<endl;
        cout<<"Frequency: "<<D.frequency<<endl;
        cout<<"Ports:"<<D.stringifyPorts()<<endl;
        cout<<"Errors:"<<D.stringifyErrors()<<endl;

        return output;            
    }
    
    //stringify
    //para obtener string de ip
    string stringify(){
        string output="";
        string stringF= to_string(frequency);
        output += string("{")+'"'+"IP"+'"'+":"+'"'+ip +'"'+","+'"'+"Ports"+'"'+":"+stringifyPorts()+"," +'"'+"Frequency"+'"'+":"+stringF+","+'"'+"Errors"+'"'+":"+stringifyErrors()+"}"+"\n";
        return output;   
    }

    //sobrecargas para mayor, menor, igual, menor o igual, mayor o igual

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



