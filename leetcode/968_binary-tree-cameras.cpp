/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
[0,0,0,null,null,null,0]
    0
0        0
           0
*/
class Solution {
public:
    int res = 0;
    void dfs(TreeNode *root) {
        // root->val = 1代表安装摄像头，=2代表没安装但是被覆盖 =0代表没安装也没覆盖
        if (!root) return;
        // 叶子节点什么也不做(先不在叶子上安装，因为在其父节点上安装可能更好)
        if (!root->left && !root->right) return;

        dfs(root->left); // 后序遍历，先在子树上安装，然后在root根据左右孩子的覆盖情况再处理
        dfs(root->right);
        
        // 1. 如果存在没有覆盖或安装的孩子，则需要在当前节点上安装一次（例如刚开始dfs时处理的那个最末端父节点）
        if ((root->left && root->left->val == 0) || (root->right && root->right->val == 0)) {
            res++;
            root->val = 1;
            return;
        }

        // 1. 左子节点上安装了，当前节点可以被覆盖
        if (root->left && root->left->val == 1) {
            root->val = 2;
            return;
        }

        // 2. 右子节点上安装了，当前节点可以被覆盖
        if (root->right && root->right->val == 1) {
            root->val = 2;
            return;
        }
    }
    
    int minCameraCover(TreeNode* root) {
        dfs(root);
        if (root->val == 0) res++;  // 根节点没有父节点继续往上了，最终处理根节点
        int cnt = res;

        return cnt;
    }
};
