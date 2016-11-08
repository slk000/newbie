//AC
//http://codeforces.com/problemset/problem/231/A
// = =
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum;
    scanf("%d", &sum);
    int cnt = 0;
    for (int i = 0; i < sum; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a + b + c >= 2)cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
