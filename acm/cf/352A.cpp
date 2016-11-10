//AC
//http://codeforces.com/problemset/problem/352/A
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
    int n;
    int cnt5 = 0, cnt0 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        cnt5 += (a == 5);
        cnt0 += (a == 0);
    }
    if (cnt0 == 0) {
        printf("-1\n");
    }
    else if(cnt5 < 9) {
        printf("0\n");
    }
    else {
        cnt5 = cnt5-cnt5%9;
        for (int i = 0; i < cnt5; i++) {
            printf("5");
        }
        for (int i = 0; i < cnt0; i++) {
            printf("0");
        }
        printf("\n");
    }
    return 0;
}
