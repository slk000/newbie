//AC
//http://codeforces.com/problemset/problem/236/A
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

    string str;
    cin >> str;
    
    sort(str.begin(), str.end());
    int cnt = unique(str.begin(), str.end()) - str.begin();
    cout << (cnt & 1 ? "IGNORE HIM!" : "CHAT WITH HER!") << endl;
    return 0;
}
