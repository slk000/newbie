#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        Node *levelStart = root; // 当前层的最左
        
        Node *nextLevelStart = nullptr; // 下一层的最左，即当前层第一个有孩子的节点的左/右孩子

        while (levelStart) {
            // 由于当前层一开始的节点不一定有孩子，所以要找到第一个有孩子的节点
            while(levelStart){
                if (levelStart->left) {
                    nextLevelStart = levelStart->left;
                    break;
                }
                if (levelStart->right) {
                    nextLevelStart = levelStart->right;
                    break;
                }
                levelStart = levelStart->next;
            }
            if (levelStart) cout << levelStart->val << endl;
            Node *last = nullptr;
            while (levelStart) {
                if (levelStart->left) {
                    if (last) {
                        last->next = levelStart->left;
                    }
                    last = levelStart->left;
                }
                if (levelStart->right) {
                    if (last) {
                        last->next = levelStart->right;
                    }
                    last = levelStart->right;
                }
                levelStart = levelStart->next;
            }
            levelStart = nextLevelStart;
        }
        return root;
    }
};

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    Solution().connect(root);

}
