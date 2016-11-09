//AC
//http://codeforces.com/problemset/problem/165/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 2000
int maxYOfX[MAX+10];
int minYOfX[MAX+10];
int maxXOfY[MAX+10];
int minXOfY[MAX+10];
int x[200];
int y[200];
int main() {
    fill(maxYOfX, maxYOfX + MAX, -INF);
    fill(maxXOfY, maxXOfY + MAX, -INF);
    fill(minYOfX, minYOfX + MAX, INF);
    fill(minXOfY, minXOfY + MAX, INF);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
        x[i] += 1000; y[i] += 1000; // for negative num
        maxYOfX[x[i]] = max(maxYOfX[x[i]], y[i]);
        minYOfX[x[i]] = min(minYOfX[x[i]], y[i]);
        maxXOfY[y[i]] = max(maxXOfY[y[i]], x[i]);
        minXOfY[y[i]] = min(minXOfY[y[i]], x[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (x[i]<maxXOfY[y[i]] && x[i]>minXOfY[y[i]] && y[i]<maxYOfX[x[i]] && y[i]>minYOfX[x[i]])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}
