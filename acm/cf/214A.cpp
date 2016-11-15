//AC
//http://codeforces.com/problemset/problem/214/A
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
    int n, m, cnt = 0;
    scanf("%d %d", &n, &m);
    for (int a = 0; a <= 1000; a++) {
        for (int b = 0; b <= 1000; b++) {
            if (a*a + b == n&&a + b*b == m) {
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
