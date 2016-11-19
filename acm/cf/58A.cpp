//AC
//http://codeforces.com/problemset/problem/58/A
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
const char p[] = "hello";
int main() {
    //freopen("in.txt", "r", stdin);
    char ch;
    int cnt = 0;
    while (EOF != scanf("%c", &ch) && ch != '\n' &&ch != '\r') {
        if (ch == p[cnt]) {
            cnt++;
        }
    }
    printf(cnt == 5 ? "YES\n" : "NO\n");
    return 0;
}
