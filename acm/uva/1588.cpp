//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4463
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
#define INF 0x3f3f3f3f
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
        if (len1 < len2) {
            swap(str1, str2);
            swap(len1, len2);
        }
        int res = INF;
        for (int k = 0; k < 2; k++) { 
            bool ok = true;
            int i = 0, j = 0;
            for (; i < len1; i++) {
                ok = true;
                for (j = 0; i + j < len1&&j < len2; j++) {
                    ok &= (str1[i + j] - '0' + str2[j] - '0' <= 3);
                    if (!ok)break;
                }
                if (ok) {
                    break;
                }
            }
            int tmpRes;
            if (i + len2 <= len1) {
                tmpRes = len1;
            }
            else {
                tmpRes = len1 + len2 - (len1 - i);
            }
            reverse(str1.begin(), str1.end());
            reverse(str2.begin(), str2.end());
            res = min(tmpRes, res);

        }
        cout << res << '\n';
    }
    return 0;
}