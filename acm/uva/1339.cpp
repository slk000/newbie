//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=430
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
using namespace std;
#define INF 0x3f3f3f3f
int cnt1[26], cnt2[26];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    ios::sync_with_stdio(false);
    std::cin.tie(0);

    string str1, str2;
    while (cin >> str1 >> str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        memset(cnt1, 0, sizeof(cnt1));
        memset(cnt2, 0, sizeof(cnt2));
        for (int i = 0; i < len1; i++) {
            cnt1[str1[i] - 'A']++;
            cnt2[str2[i] - 'A']++;
        }
        sort(cnt1, cnt1 + 26);
        sort(cnt2, cnt2 + 26);
        if (0 == memcmp(cnt1, cnt2, sizeof(cnt1))) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}