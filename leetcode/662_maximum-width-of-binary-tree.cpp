#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct Pair{
    int level;
    // int no;
    TreeNode *node;
};

constexpr int MAXVAL = 3000*100;
constexpr int NULLNODE = MAXVAL+1;
class Solution {
public:
    void pushback(deque<TreeNode*> &q, deque<unsigned long long> &nullCntQueue, TreeNode *node) {
        if (node) {
            q.push_back(node);
        }
        else {
            // 由于直接使用TreeNode->val统计连续空节点个数会超int,所以
            // 使用val == NULLNODE 的节点代表多个连续空节点，实际的个数存放在nullCntQueue中
            if (!q.empty() && q.back()->val == NULLNODE) { 
                nullCntQueue.back()++;
            }
            else {
                q.push_back(new TreeNode(NULLNODE));
                nullCntQueue.push_back(1);
            }
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        deque<TreeNode*> q; // 为了从队尾弹出指针，使用deque
        deque<unsigned long long> nullCntQueue;

        // int res = -1;
        unsigned long long res = 0;
        q.push_back(root);

        while(!q.empty()) {
            // 清空队头的空节点
            while (!q.empty() && q.front()->val == NULLNODE) {
                q.pop_front();
                nullCntQueue.pop_front();
            }
            int cnt = q.size(); 
            unsigned long long innerNodeCnt = 0;
            for (int i = 0; i < cnt; i++) {
                TreeNode *cur = q.front();
                q.pop_front();
                // 统计内部节点数量
                if (cur->val != NULLNODE) {
                    // 如果是正常节点，正常统计和入队
                    innerNodeCnt++;
                    pushback(q, nullCntQueue, cur->left);
                    pushback(q, nullCntQueue, cur->right);
                } 
                else {
                    // 如果是空节点，将数量翻倍再入队
                    unsigned long long nullCnt = nullCntQueue.front();
                    nullCntQueue.pop_front();
                    innerNodeCnt +=  nullCnt;

                    q.push_back(cur);
                    nullCntQueue.push_back(2 * nullCnt);
                }
            }
            res = max((unsigned long long)res, innerNodeCnt);
            // 清空队尾的空节点
            while (!q.empty() && q.back()->val == NULLNODE) {
                q.pop_back();
                nullCntQueue.pop_back();
            }

        }
        return res;
    }
};
int main(){
    // [1,3,2,5,null,null,9,6,null,7]
    

    /*
    TreeNode *root = new TreeNode(1);
    root->left= new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->left=new TreeNode(7);
    */
   

// [1,1,1,1,1,1,1,null,null,null,1,null,null,null,null,2,2,2,2,2,2,2,null,2,null,null,2,null,2]
    TreeNode *root = new TreeNode(101);
    root->left = new TreeNode(201);
    root->right = new TreeNode(301);
    root->left->left = new TreeNode(401);
    root->left->right = new TreeNode(501);
    
    root->right->left = new TreeNode(601);
    root->right->right = new TreeNode(701);

    root->left->right->right=new TreeNode(801);
    TreeNode *subroot = root->left->right->right;
    subroot->left=new TreeNode(902);
    subroot->right=new TreeNode(1002);
    subroot->left->left=new TreeNode(1102);
    subroot->left->right=new TreeNode(1202);
    subroot->right->left=new TreeNode(1302);
    subroot->right->right=new TreeNode(1402);
    subroot->left->left->left=new TreeNode(1502);
    subroot->left->right->left=new TreeNode(1602);
    subroot->right->left->right=new TreeNode(1702);
    subroot->right->right->right=new TreeNode(1802);

    // 
    cout << Solution().widthOfBinaryTree(root) << endl;
    return 0;
}
