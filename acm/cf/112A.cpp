//AC
//http://codeforces.com/problemset/problem/112/A
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
    string str1, str2;
    cin >> str1 >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
    transform(str2.begin(), str2.end(), str2.begin(), ::toupper);
    cout << str1.compare(str2) << endl;
    return 0;
}
