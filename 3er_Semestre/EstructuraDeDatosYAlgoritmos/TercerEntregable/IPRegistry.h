#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

struct IPRegistry{
    string ip;
    int frequency;
    //DoublyLinkedList<string> errors;
    friend ostream &operator<<( ostream &output, const IPRegistry &D ) { 
        output << D.ip << D.frequency;
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
};



