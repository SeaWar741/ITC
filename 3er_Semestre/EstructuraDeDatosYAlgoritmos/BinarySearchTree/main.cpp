#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main(){
    BinarySearchTree<int> tree;

    for (int i = 0; i < 10; i++){
        tree.Insert(i);
    }
    tree.Insert(20);
    tree.Insert(23);
    tree.Delete(20);
    
    return 0;
}
