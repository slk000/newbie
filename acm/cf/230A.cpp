//AC
//http://codeforces.com/problemset/problem/230/A
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
#define MAX 10000
pair<int, int> xy[MAX + 10];
int main() {
    //freopen("in.txt", "r", stdin);
    int s, n;
    scanf("%d %d", &s, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &xy[i].first, &xy[i].second);
    }
    sort(xy, xy + n);
    for (int i = 0; i < n; i++) {
        if (s > xy[i].first) {
            s += xy[i].second;
            continue;
        }
        else {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
