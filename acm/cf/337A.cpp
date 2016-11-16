//AC
//http://codeforces.com/problemset/problem/337/A
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
#define MAX 50
int f[MAX + 10];
int main() {
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &f[i]);
    }
    sort(f, f + m);
    int res = INF;
    for (int i = 0; i < m - n+1; i++) {
        res = min(res, f[i + n-1] - f[i]);
    }
    printf("%d\n", res==INF?0:res);
    return 0;
}
