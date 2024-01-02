#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isStartWith(const string &str, int start, const string &pattern) {
        int i = start, j = 0;
        while (i < str.size() && j < pattern.size() && str[i] == pattern[j]) {
            j++;
            i++;
        }
        return j == pattern.size();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1); // dp[i]:以i为开头，能拼出多长的字符串 
        for (int bagSize = 0; bagSize <= s.length(); bagSize++) {
            for (int i = 0; i < wordDict.size(); i++) {
                int wordLen = wordDict[i].length(); // 用int存length,以免下面bagSize-wordDict[i].length()变成无符号溢出
                if (bagSize - wordLen < 0) continue;
                if(isStartWith(s, bagSize-wordLen, wordDict[i])) {
                    dp[bagSize] = max(dp[bagSize], dp[bagSize-wordLen] + wordLen);
                }
            }
            /*
            cout << "bagSize: " << bagSize << "\t";
            for (int ii = 0; ii <= s.size(); ii++) {
                cout << dp[ii] << " ";
            }
            cout << endl;
            */
        }
        return dp[s.size()] == s.size();
    }
};

int main() {
   // string str = "applepenapple"; vector<string> dic{"apple","pen"};
    // string str = "leetcode"; vector<string> dic{"leet", "code"};
    // string str = "leetcode"; vector<string> dic{"leetc", "code"};
    // string str = "catsandog"; vector<string> dic{"cats", "dog", "sand", "and", "cat"};
    string str = "dogs"; vector<string> dic{"dog","s","gs"};

    cout << Solution().wordBreak(str, dic) << endl;
}
