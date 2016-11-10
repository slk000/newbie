//AC
//http://codeforces.com/problemset/problem/339/B
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
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    long long ans = 0;
    int last = 1;
    for (int i = 0; i < m; i++) {
        int cur;
        scanf("%d", &cur);
        if (last > cur) {
            ans += n - (last - cur);
        }
        else {
            ans += cur - last;
        }
        last = cur;
    }
    printf("%lld\n", ans);
    return 0;
}
