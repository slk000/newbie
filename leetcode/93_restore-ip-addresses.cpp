#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    vector<string> segments;
    bool checkNum(string &s) {
        if (s.size() > 3) return false; // 防止stoi超范围
        if (s.size() > 1 && s[0] == '0') return false; // "00", "0xx"
        int num = stoi(s);
        if (num > 255) return false;
        if (num == 0 && s.size() != 1) return false; // "00"
        return true;
    }
    void dfs(string &s, int start) {
        if (segments.size() == 4) {
            if (start == s.size()) {
                // 刚好划分完
                res.push_back(segments[0]+"."+segments[1]+"."+segments[2]+"."+segments[3]);
            }
            return;
        }
        string num;//一节数字
        for (int i = start; i < s.size(); i++) {
            num.push_back(s[i]);
            if (checkNum(num)) {
                segments.emplace_back(num);
                dfs(s, i+1);
                segments.pop_back();
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return res;
    }
};

int main() {
    string s;
    while (cin >> s) {
        auto v = Solution().restoreIpAddresses(s);
        for (string str : v) {
            cout << str << ", " ;
        }
        cout << endl;
    }

}
