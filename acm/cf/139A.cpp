//AC
//http://codeforces.com/problemset/problem/139/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
int pages[7];
int main() {
    int page;
    scanf("%d", &page);
    for (int i = 0; i < 7; i++) {
        scanf("%d", &pages[i]);
    }
    int ans = 0;
    while (page > 0) {
        page -= pages[ans];
        ans = (ans + 1) % 7;
    }
    if (ans == 0)ans = 7;
    printf("%d\n", ans);
    return 0;
}
