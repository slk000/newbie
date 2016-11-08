//AC
//http://codeforces.com/problemset/problem/148/A
//素筛==
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
bool flag[100010];
int main() {
    int d;
    int division[4];//k, l, m, n;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &division[i]);
    }
    scanf("%d", &d);
    for (int i = 0; i < 4; i++) {
        for (int j = division[i]; j <= d; j += division[i]) {
            if (!flag[j]) {
                cnt++;
                flag[j] = true;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
