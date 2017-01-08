//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
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
#define MAX 10000
int arr[MAX + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //std::cin.tie(0);
    int n, q, Case = 1;
    while (EOF!=scanf("%d %d", &n, &q), n&&q) {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        printf("CASE# %d:\n", Case++);
        for (int i = 0; i < q; i++) {
            int t;
            scanf("%d", &t);
            int* a = lower_bound(arr, arr + n, t);
            if (*a == t) {
                printf("%d found at %d\n", t, a - arr + 1);
            }
            else {
                printf("%d not found\n", t);
            }
        }
       
    }
    return 0;
}