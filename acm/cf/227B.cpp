//AC
//http://codeforces.com/problemset/problem/227/B
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
int indexOf[100010];
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        indexOf[a] = i;
    }
    
    int m;
    scanf("%d", &m);
    long long cnt = 0; // long long important
    long long rcnt = 0;
    for (int i = 0; i < m; i++) {
        int t;
        scanf("%d", &t);
        
        cnt += indexOf[t];
        rcnt += n-indexOf[t]+1;
    }
    printf("%lld %lld\n", cnt, rcnt);
    return 0;
}
