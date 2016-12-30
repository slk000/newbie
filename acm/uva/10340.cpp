//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=1281
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <queue>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    string str1, str2;
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    while (cin >> str1 >> str2) {
        int len1 = str1.length();
        int len2 = str2.length();
        int i = 0, j = 0;
        for (; i < len2; i++) {
            if (str1[j] == str2[i]) j++;
        }
        cout << ((len1 == j) ? "Yes\n" : "No\n");
    }
    return 0;
}