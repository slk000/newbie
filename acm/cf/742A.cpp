//AC
//http://codeforces.com/contest/742/problem/A
//Codeforces Round #383 (Div. 2) A
#include <cstdio>
using namespace std;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
/*
res = (1378^n)%10
    = (1378%10)^n%10
    = 8^n%10
    res   n
    1     0
    8     1
    4     2
    2     3
    6     4
    8     5
    8     6
    4     7
    2     8
    6     9
    8     10
*/
    int n;
    scanf("%d", &n);
    if (n == 0) {
        printf("1\n");
        return 0;
    }
    int ans[] = { 8,4,2,6 };
    printf("%d\n", ans[(n-1) % 4]);
    return 0;
}