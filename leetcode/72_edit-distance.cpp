#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length(), len2 = word2.length();
        vector<vector<int>> dp(len1+1, vector<int>(len2+1));
        // 初始化第0行：第0行时，word1为空，需要在word2中删除j个字符才能将其变空
        for (int j = 0; j <= len2; j++) dp[0][j] = j;
        for (int i = 0; i <= len1; i++) dp[i][0] = i; // 初始化第0列

        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        // for (int i = 0; i <= len1; i++) {
        //     for (int j = 0; j <= len2; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[len1][len2];
    }
};
