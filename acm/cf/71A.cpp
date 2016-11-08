//AC
//http://codeforces.com/problemset/problem/71/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    //scanf("%d", &T);
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        int len = str.length();
        if (len > 10) {
            cout << str[0] << len - 2 << str[len - 1] << endl;
        }
        else {
            cout << str << endl;
        }
    }
    return 0;
}
