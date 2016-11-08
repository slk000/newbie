//AC
//http://codeforces.com/problemset/problem/116/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int stops;
    scanf("%d", &stops);
    int Max = -INF;
    int cnt = 0;
    for (int i = 0; i < stops; i++) {
        int a, b; // exit, enter
        scanf("%d %d", &a, &b);
        cnt = cnt - a + b;
        Max = max(Max, cnt);
    }
    printf("%d\n", Max);
    return 0;
}
