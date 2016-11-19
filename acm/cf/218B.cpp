//AC
//http://codeforces.com/problemset/problem/218/B
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
#define INF 0x3f3f3f3f
#define MAX 1000
int main() {
    //freopen("in.txt", "r", stdin);
    int n, m;
    priority_queue<int> Max;
    priority_queue<int, vector<int>, greater<int> >Min;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        Max.push(t);
        Min.push(t);
    }
    int resMin = 0, resMax = 0;
    for (int cnt = 0; cnt < n; cnt++) {
        int t = Min.top();
        Min.pop();
        resMin += t;
        if (--t)Min.push(t);

        t = Max.top();
        Max.pop();
        resMax += t;
        if (--t)Max.push(t);
    }
    printf("%d %d\n", resMax, resMin);
    return 0;
}
