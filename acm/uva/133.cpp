//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=832&page=show_problem&problem=69
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
bool arr[20 + 5];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //std::cin.tie(0);

    int n, k, m;
    while (EOF!=scanf("%d%d%d", &n, &k, &m) && n && k && m) {
        memset(arr, 1, sizeof(arr));
        int a = 0, b = n+1;
        int nn = n;
        while (nn) {
            for (int i = 0; i < k; i++) {
                a++;
                if (a == n + 1)a = 1;
                if (!arr[a])i--;
            }
            for (int i = 0; i < m; i++) {
                b--;
                if (b == 0)b = n;
                if (!arr[b])i--;
            }
            arr[a] = arr[b] = 0;

            if (a != b) {
                nn -= 2;
                printf(" %2d %2d", a, b);
            }
            else {
                nn -= 1;
                printf(" %2d", a);
            }
            if (nn)printf(",");
        }
        printf("\n");
    }
    return 0;
}