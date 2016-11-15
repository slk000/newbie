//AC
//http://codeforces.com/problemset/problem/215/A
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
int a[10010];

int main() {
    int n, m;
    int Max = -INF, cntMax = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        int b;
        scanf("%d", &b);
        for (int j = 0; j < n; j++) {
            if (b % a[j] == 0) {
                if (b / a[j] == Max) {
                    cntMax++;
                }
                else if (b / a[j] > Max) {
                    Max = b / a[j];
                    cntMax = 1;
                }
            }
        }
    }
    printf("%d\n", cntMax);
    return 0;
}
