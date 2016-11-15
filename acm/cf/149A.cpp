//AC
//http://codeforces.com/problemset/problem/149/A
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
int month[12];
int main() {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < 12; i++) {
        scanf("%d", &month[i]);
    }
    sort(month, month + 12, greater<int>());
    int res = 0, sum = 0;
    for (; res < 12 && sum < k; sum += month[res++]);
    printf("%d\n", sum >= k ? res : -1);
    return 0;
}
