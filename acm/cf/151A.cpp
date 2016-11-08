//AC
//http://codeforces.com/problemset/problem/151/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int n, k, l, c, d, p, nl, np;
    scanf("%d %d %d %d %d %d %d %d", &n, &k, &l, &c, &d, &p, &nl, &np);
    int ans = min(min(k*l / nl, c*d), p / np)/n;
    printf("%d\n", ans);
    return 0;
}
