//Juan Carlos Garfias Tovar, A01652138

#include <string>
#include <iostream>

using namespace std;

struct Node{
    string ip;
    int failedAttempts;
    Node *next;
    Node *prev;
    Node();
    Node(string ip);
    Node(string ip, int failedAttempts);
    bool operator<(const Node nodeInput){
        return (failedAttempts < nodeInput.failedAttempts);
    }
    bool operator>(const Node nodeInput){
        return (failedAttempts > nodeInput.failedAttempts);
    }
    
    void print();
};

//constructor
Node::Node(){
    ip = "";
    failedAttempts = 0;
    next = NULL;
    prev = NULL;
}

//constructor
Node::Node(string ip){
    this->ip = ip;
    failedAttempts = 0;
    next = NULL;
    prev = NULL;
}

//constructor
Node::Node(string ip, int failedAttempts){
    this->ip = ip;
    this->failedAttempts = failedAttempts;
    this->next = NULL;
    this->prev = NULL;
}


//print
//imprime nodo
//O(1)
void Node::print(){
    cout << "[" << ip << "] --> Failed Attempts: " << failedAttempts << endl;
}