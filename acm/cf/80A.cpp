//AC
//http://codeforces.com/problemset/problem/80/A
// = =
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100010;
int prime[17] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53 };

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int res = *((int*)upper_bound(prime, prime + 17, m));
    printf(n == res ? "YES\n" : "NO\n");
    return 0;
}
