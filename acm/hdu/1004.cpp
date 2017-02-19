//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1004
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
map<string, int, greater<string> > m;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n && n) {
        m.clear();
        int Max = -INF;
        string res = "";
        for (int i = 0; i < n; i++) {
            string str;
            cin >> str;
            if (m.count(str) == 0) {
                m[str] = 0;
            }
            m[str]++;
            if (Max < m[str]) {
                Max = m[str];
                res = str;
            }
        }
        cout << res << '\n';
    }
    return 0;
}