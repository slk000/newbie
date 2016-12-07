//AC
//http://codeforces.com/problemset/problem/255/A
//wannafly 3 C
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAX 100
#define INF 0x3f3f3f3f
int a[MAX];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    
    int n;
    scanf("%d", &n);
    int res[3] = { 0,0,0 };
    int Max = -INF;
    for (int i = 0; i < n; i++) {
        //scanf("%d", &a[i]);
        int t;
        scanf("%d", &t);
        res[i % 3]+=t;
        
    }
    Max = max(Max, res[0]);
    Max = max(Max, res[1]);
    Max = max(Max, res[2]);
    if (Max == res[0]) {
        printf("chest\n");
    }
    else if (Max == res[1]) {
        printf("biceps\n");
    }
    else if (Max == res[2]) {
        printf("back\n");
    }
    return 0;
}