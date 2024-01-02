#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int cnt = 0;

    // only go left
    void dfs(TreeNode *root){
        if(!root) return;
        cnt++;
        dfs(root->left);
    }
    int countNodes(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};

int main(){
    return 0;
}