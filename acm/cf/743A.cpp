//AC
//http://codeforces.com/problemset/problem/743/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // ONLINE_JUDGE
    int n, a, b;
    char aType, bType;
    scanf("%d %d %d", &n, &a, &b);
    getchar();
    for (int i = 1; i <= n; i++) {
        if (i == a) scanf("%c", &aType);
        else if (i == b) scanf("%c", &bType);
        else scanf("%*c");
    }
    puts((aType == bType || a == b) ? "0" : "1");
    return 0;
}