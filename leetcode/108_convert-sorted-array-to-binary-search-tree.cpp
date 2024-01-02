#include <iostream>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* dfs(vector<int> &nums, int start, int end) { // [start, end)
        if (start >= end) return nullptr;
        int mid = (start+end)/2;
        TreeNode *ret = new TreeNode(nums[mid]);
        ret->left = dfs(nums, start, mid);
        ret->right = dfs(nums, mid+1, end);
        return ret;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size());
    }
};
