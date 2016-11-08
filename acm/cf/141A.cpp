//AC
//http://codeforces.com/problemset/problem/141/A
// = =
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

    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    str1 += str2;
    sort(str1.begin(), str1.end());
    sort(str3.begin(), str3.end());
    cout << (str1==str3 ? "YES\n" : "NO\n") << endl;
    return 0;
}
