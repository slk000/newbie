//AC
//http://codeforces.com/problemset/problem/124/A
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
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    int res;
    if (n - b <= a) { // 1..2..b[..3..4..a]
        res = n-a;
    }
    else {  // 1..2..a]..3..4..[b
        res = b + 1;
    }
    printf("%d\n", res);
    return 0;
}
