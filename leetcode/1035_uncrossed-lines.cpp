#include <bits/stdc++.h>
using namespace std;
// 最长公共子序列
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        swap(nums1,nums2);
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1));
        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (nums1[i-1] == nums2[j-1]) {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for (int i = 1; i <= n1; i++) {
        //     for (int j = 1; j <= n2; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n1][n2];
    }
};
/*
暴力搜索超时
//    2   5   1   2   5
//        |     \     |
//    10  5   2   1   5   2
// i  0   1   2   3   4   5  6
//    x   1   3   x   4
/ *
map idx:
nums1[i]:{在nums2中出现的下标集合}
2: {2, 5}   |
5: {1, 4}   |
1: {3}      |
2: {2, 5}   |
5: {1, 4}  \|/
依次从这些集合里找一条递增序列，最长的那条就是绘制线条最多的方法
例如245、134、135
设dp[i]：第i个数时最长递增序列的长度
* /
class Solution {
public:
    unordered_map<int, vector<int>> idx;
    int n1, n2;
    int res = 0;
    void dfs(int start, int lastNum, int len, vector<int> &nums1) { // start:nums1数组的下标，lastNnm上一层递归（上一个集合）选择的数，len：选择了几个数
        if (start >= n1) {
            res = max(res, len);
            return;
        }
        const vector<int> &i = idx[nums1[start]]; // 1.选中一个集合
        for (int v : i) { // 在这个集合中选择一个更大的数并往下走
            if(v > lastNum) dfs(start+1, v, len+1, nums1);
        }
        dfs(start+1, lastNum, len, nums1);// 2.不在这个集合中选，直接跳过，不累加len
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size(), n2 = nums2.size();
        
        for (int i = 0; i < n2; i++) {
            idx[nums2[i]].push_back(i);
        }
        dfs(0, -1, 0, nums1);
        return res;
    }
};
*/
int main() {
    // vector<int> nums1{2,5,1,2,5}, nums2{10,5,2,1,5,2};
    vector<int> nums1{1,3,7,1,7,5}, nums2{1,9,2,5,1};
    cout << Solution().maxUncrossedLines(nums1, nums2) << endl;
}
