#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};


class LowestCAncestor {
    public:

        Node *ancestor(Node *root, int a,int b) {
            bool step = true;
            while(step){
                if ((b > root->data && a < root->data) || (b == root->data || a == root->data) || (b < root->data && a > root->data)){
                    step = false;
                }  
                else if(b >  root->data){
                    root = root->right;
                }
                else{
                    root = root->left;
                }
            }
            return  root;
        }

  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }
};




int main() {
    LowestCAncestor arbol;
    Node* root = NULL;
    
    int t,a, b,data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = arbol.insert(root, data);
    }
  	
  	
  	std::cin >> a >> b;

    Node *solution = arbol.ancestor(root, a, b);
    
  	std::cout << solution->data;

    return 0;
}