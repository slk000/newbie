#include <cstdio>
class Node{
public:
    int _value;
    Node *left, *right, *_father;
    Node(int value, Node* father = NULL){
        _value = value;
        _father = father;
        left = right = NULL;
    }
    void insert(int value){
        
        if (value == _value) return;
        if (value > _value){
            if (right == NULL){
                right = new Node(value, this);
            }
            else{
                right->insert(value);
            }
        }
        else if(value < _value){
            if (left == NULL){
                left = new Node(value, this);
            }
            else{
                left->insert(value);
            }
        }
    } 
};
class BST{
    Node *root;
public:
    BST(){
        root = NULL;
    }    
    void insert(int value){
        if (root == NULL){
            root = new Node(value);
        }
        else{
            root->insert(value);
        }
        
    }
    Node* getroot(){return root;}
    void pre(Node* p){

        if(p->left != NULL)
            pre(p->left);
        printf("%d(%c, %c)\n", p->_value, p->left?p->left->_value+'0':'#',p->right?p->right->_value+'0':'#');
        if(p->right != NULL)
            pre(p->right);
    }
};
int main(){
    BST bst;
    int N;
    scanf("%d", &N);
    //int data[N];
    for(int i = 0; i < N; i++){
        int data;
        scanf("%d", &data);
        bst.insert(data);
    }
    bst.pre(bst.getroot());

    
    return 0;
}