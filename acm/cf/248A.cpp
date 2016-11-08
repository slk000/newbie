//AC
//http://codeforces.com/problemset/problem/248/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum = 0;
    scanf("%d", &sum);
    int cntL = 0, cntR = 0; // cnt for open doors
    for (int i = 0; i < sum; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        cntL += a;
        cntR += b;
    }
    int ans = 0;
    ans += (sum >> 1) >= cntL ? cntL : sum - cntL;
    ans += (sum >> 1) >= cntR ? cntR : sum - cntR;
    printf("%d\n", ans);
    return 0;
}
