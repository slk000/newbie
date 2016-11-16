//AC
//http://codeforces.com/problemset/problem/221/A
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
/*
int a[1010];
void f(int x) {
    if (x == 1) return;
    swap(a[x - 1], a[x]);
    f(x - 1);
    
}
int main() {
    for (int i = 1; i <= 1000; i++)a[i] = i;
    int n;
    scanf("%d", &n);
    f(n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}*/
int main() {
    int n;
    scanf("%d", &n);
    printf("%d ", n);
    for (int i = 1; i < n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    return 0;
}
