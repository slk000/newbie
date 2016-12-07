//AC
//http://codeforces.com/contest/734/problem/C
//Codeforces Round #379 (Div. 2) C
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
#define MAX 200000
#define ll long long
int a[MAX + 10], b[MAX + 10], c[MAX + 10], d[MAX + 10];
ll min(ll a, ll b) { return a > b ? b : a; }

int binary_lowb(int l, int r, int t, int arr[]) {
    int m = (l + r+1) / 2;
    while (l<r)
    {
        m = (l + r+1) / 2;
        if (arr[m] <= t) l = m;
        else r = m - 1;
    }
    return l;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    /*int ttt[] = { 0,10,17,20,80 };
    int aaa = binary_lowb(0, 4, 8071,ttt);*/
    int sum, sumKind1, sumKind2;
    int originTime, originPoints;
    scanf("%d %d %d %d %d", &sum, &sumKind1, &sumKind2, &originTime, &originPoints);
    a[0] = originTime;
    for (int i = 1; i <= sumKind1; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= sumKind1; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 1; i <= sumKind2; i++) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= sumKind2; i++) {
        scanf("%d", &d[i]);
    }

    ll res = INF;
    for (int i = 0; i <= sumKind1; i++) {
        ll tmpTime = originTime;
        ll tmpPoints = originPoints;

        if (tmpPoints >= b[i]) { //选择一款type1
            tmpPoints -= b[i];
            tmpTime = a[i];
        }

        ll ci = 0;

        ci = binary_lowb(0, sumKind2, tmpPoints,d);//d中 小于等于当前点数的最大值

        int decreaseSum = c[ci];
        if (tmpTime < 0)tmpTime = 0;
        ll tmpSum = sum - decreaseSum;
        if (tmpSum < 0) tmpSum = 0;
        res = min(res, tmpTime * tmpSum);
    }
    printf("%lld\n", res);
    return 0;
}