//AC
//http://codeforces.com/problemset/problem/34/B
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
    vector<int> prices;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if (a < 0) {
            prices.push_back(a);
        }
    }
    int res = 0;
    sort(prices.begin(), prices.end());
    for (int i = 0; i < prices.size()&& i < m && prices[i] < 0; i++) {
        res += prices[i];
    }
    printf("%d\n", -res);
    return 0;
}
