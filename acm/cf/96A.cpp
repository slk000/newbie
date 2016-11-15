//AC
//http://codeforces.com/problemset/problem/96/A
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
string str;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> str;
    printf((str.find("0000000")!=-1||str.find("1111111")!=-1)?"YES\n":"NO\n");
    return 0;
}
