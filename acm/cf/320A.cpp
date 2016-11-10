//AC
//http://codeforces.com/problemset/problem/320/A
//23333
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
bool chk(string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '*') return false;
    }
    return true;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    string str;
    cin >> str;
    int it;
    while ((it=str.find("144")) != -1) {
        str.replace(it, 3, "***");
    }
    while ((it = str.find("14")) != -1) {
        str.replace(it, 2, "**");
    }
    while ((it = str.find("1")) != -1) {
        str.replace(it, 1, "*");
    }
    cout << (chk(str)?"YES":"NO") << endl;
    return 0;
}
