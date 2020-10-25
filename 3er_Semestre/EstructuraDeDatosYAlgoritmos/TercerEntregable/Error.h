#include <iostream>
using namespace std;

struct Error{
    string errorType;
    int frequency;

    bool operator <( const Error& rhs ) const{
        if(errorType < rhs.errorType){return true;}
        else{return false;}
    }
    bool operator >( const Error& rhs ) const{
        if(errorType < rhs.errorType){return true;}
        else{return false;}
    }
    bool operator <=( const Error& rhs ) const{
        if(errorType <= rhs.errorType){return true;}
        else{return false;}
    }
    bool operator >=( const Error& rhs ) const{
        if(errorType >= rhs.errorType){return true;}
        else{return false;}
    }
    bool operator ==( const Error& rhs ) const{
        if(errorType == rhs.errorType){return true;}
        else{return false;}
    }
    bool operator !=( const Error& rhs ) const{
        if(errorType != rhs.errorType){return true;}
        else{return false;}
    }
    //FOR HEAP
    bool minor( const Error& rhs ) const{
        if(frequency < rhs.frequency){return true;}
        else{return false;}
    }

    bool minorEqual( const Error& rhs ) const{
        if(frequency <= rhs.frequency){return true;}
        else{return false;}
    }

    bool major( const Error& rhs ) const{
        if(frequency > rhs.frequency){return true;}
        else{return false;}
    }

    bool majorEqual( const Error& rhs ) const{
        if(frequency >= rhs.frequency){return true;}
        else{return false;}
    }

    bool equal( const Error& rhs ) const{
        if(frequency == rhs.frequency){return true;}
        else{return false;}
    }
};
