#include <iostream>
#include <string>
#include <vector>
using namespace std;
// a b a b a
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> isPalindromeAtEnd; // 子字符串[i,j]是否是回文
    void build(string &s) {
        int len = s.length();
        isPalindromeAtEnd.resize(len, vector<bool>(len));
        for (int i = len-1; i >= 0; i--) {
            for (int j = i; j < len ;j++) {
                if (i == j) isPalindromeAtEnd[i][j] = true;
                else if (j-i == 1) isPalindromeAtEnd[i][j] = s[i] == s[j];
                else {
                    isPalindromeAtEnd[i][j] =( s[i] == s[j] && isPalindromeAtEnd[i+1][j-1]);
                }
            }
        }

        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len; j++) {
                cout << isPalindromeAtEnd[i][j] << "\t";
            }
            cout << endl;
        }
    }
    bool isPalindrome(string &s, int start, int end) { // [start, end]
        
        return isPalindromeAtEnd[start][end];
    }
    void dfs(string &s, int start) {
        if (s.length() == start) {
            res.emplace_back(path);
            return;
        }
        for (int end = start; end < s.length();end++) {
            if (isPalindrome(s, start,end)) {
                path.push_back(s.substr(start,end-start+1));
                dfs(s,end+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        build(s);
        dfs(s, 0);
        return res;
    }
};

int main() {
    string s;
    cin >> s;
    auto res = Solution().partition(s);
    for (auto v : res) {
        for (auto s : v) {
            cout << s << ", ";
        }
        cout << endl;
    }
}
