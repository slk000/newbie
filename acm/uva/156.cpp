//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=92
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <map>
using namespace std;
#define INF 0x3f3f3f3f
map<string, int> m;
vector<string> words, ans;
void toLowercase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') str[i] = str[i] - 'A' + 'a';
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    string str = "";
    
    while (cin >> str) {
        if (str[0] == '#') break;
        words.push_back(str);
        toLowercase(str);
        sort(str.begin(), str.end());
        if (m.count(str) == 0) m[str] = 0;
        m[str]++;
        
    }
    for (int i = 0; i < words.size(); i++) {
        string t = words[i];
        toLowercase(t);
        sort(t.begin(), t.end());
        if (m[t] == 1) {
            ans.push_back(words[i]);
        }
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}