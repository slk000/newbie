//AC
//http://codeforces.com/problemset/problem/118/B
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
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n+1; i++) {
        int j;
        for (int j = 0; j < 2 * (n - i); j++) printf(" ");
        for (j = 0; j <= i; j++) printf(j==i&&i==0?"%d":"%d ", j);
        for (j--; j > 0; j--) printf(j==1?"%d":"%d ", j-1);
        printf("\n");
    }
    //printf("\n");
    for (int i = n-1; i >=0; i--) {
        int j;
        for (int j = 0; j < 2 * (n - i); j++) printf(" ");
        for (j = 0; j <= i; j++) printf(j==i&&i==0?"%d":"%d ", j);
        for (j--; j > 0; j--) printf(j==1?"%d":"%d ", j - 1);
        printf("\n");
    }
    return 0;
}