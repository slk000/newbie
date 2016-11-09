//AC
//http://codeforces.com/problemset/problem/318/A
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
    long long n, k;
    scanf("%lld %lld", &n, &k);
    long long mid = (n & 1) ? (n >> 1) + 1 : (n >> 1);
    if (k <= mid) { //in the odd part
        printf("%lld\n", 2 * k - 1);
    }
    else {
        printf("%lld\n", 2 * (k - mid));
    }
    return 0;
}
