#include <iostream>
#include "DoublyLinkedList.h"
using namespace std;

struct IPRegistry{
    string ip;
    int frequency = 0;
    //DoublyLinkedList<string> errors;
    friend ostream &operator<<( ostream &output, const IPRegistry &D ) { 
        output << "{IP:"<<D.ip <<", Frequency:"<<D.frequency<<"}"<<endl;
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



