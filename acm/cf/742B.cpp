//AC
//http://codeforces.com/contest/742/problem/B
//Codeforces Round #383 (Div. 2) B
#include <cstdio>
#include <algorithm>
#define MAX 200000 //数最大能到max(a,b)*2
#define INF 0x3f3f3f3f
#define LL long long
int cnt[MAX + 10]; 
int arr[MAX + 10];
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n, x;
    scanf("%d %d", &n, &x);
    int Max = -INF;
    for (int i = 0; i < n; i++) {
        int t;
        scanf("%d", &t);
        arr[i] = t;
        cnt[t]++; //记录每个数出现的次数
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int t = arr[i] ^ x;
        if (t > MAX || !cnt[t]) continue;
        if (arr[i] == t) { // <=> x==0
            res += ((LL)cnt[t]*((LL)cnt[t]-1)) >> 1LL; //C(cnt,2)组合
        }
        else {
            res += ((LL)cnt[arr[i]] * (LL)cnt[t]);
        }
        cnt[arr[i]] = cnt[t] = 0; //用过一组数，个数清零
    }
    printf("%lld\n", res);
    return 0;
}