#include "RegistryEntry.h"

class Node {
  public:
    int key;
    RegistryEntry data;
    Node * next;
    Node * previous;
    
    Node() {
        RegistryEntry entry;
        key = 0;
        data = entry;
        next = NULL;
        previous = NULL;
    }
    Node(int k, RegistryEntry d) {
        key = k;
        data = d;
    }
};