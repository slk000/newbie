// AC
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

struct Lnode{
    int l, r;
    // TreeNode *node;
    int m; // max of [l,r].
    int i; // index of the max val
} L[4096];
inline void update(int k){
    if(L[k*2].m < L[k*2+1].m){
        L[k].m = L[k*2+1].m;
        L[k].i = L[k*2+1].i;
    }
    else{
        L[k].m = L[k*2].m;
        L[k].i = L[k*2].i;
    }
}
void build(int k, int l, int r, vector<int> &nums){
    cout << "build " <<k<<' '<< l <<' '<< r<< "  " /*<< L[k].m*/<<endl;
    L[k].l = l;
    L[k].r = r;
    if(l == r){
        L[k].m = nums[l-1];
        L[k].i = l;
        return;
    }
    int mid = (l+r)/2;
    build(k*2, l, mid, nums);
    build(k*2+1, mid+1,r, nums);
    update(k);
}

// query the index of the max in range [l,r] l=[1...nums.size()]
// k start from 1 to make 2*k works
int query(int k, int l, int r, vector<int> &nums) {
    if(L[k].l == l && L[k].r == r) return L[k].i;
    int mid = (L[k].l + L[k].r) / 2;
    if(r <= mid) return query(k*2,l,r, nums);
    if(l > mid) return query(k*2+1, l,r, nums);

    int i = query(k*2,l,mid, nums);
    int j = query(k*2+1, mid+1,r, nums);
    if(nums[i-1]>nums[j-1]){
        return i;
    }
    else{
        return j;
    }
    
}

class Solution {
public:
    TreeNode* dfs(TreeNode *root, int l, int r, vector<int> &nums){
        int i = query(1,l,r,nums);
        root->val = nums[i-1];
        if(l == r) return 0; // l == r == i
        if(i != l){
            root->left = new TreeNode(-1);
            dfs(root->left, l,i-1,nums);
        }
        if (i != r){
            root->right = new TreeNode(-1);
            dfs(root->right, i+1, r, nums);
        }
        return 0;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        build(1,1,nums.size(), nums);
        TreeNode *dumb = new TreeNode(-1);
        int s,t;
        // while(cin >> s >> t){
        //     cout << query(1,s,t, nums) << endl;
        // }
        dfs(dumb, 1, nums.size(), nums);
        return dumb;
    }
};

int main(){
    vector<int> nums = {3,2,1,6,0,5};
    Solution().constructMaximumBinaryTree(nums);
}