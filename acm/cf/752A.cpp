//AC
//http://codeforces.com/problemset/problem/752/A
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int c = ceil((double)k / (2 * (double)m));
    int kk = 1 + 2 * m*(c-1);
    int r = ceil((k - kk) / 2)+1;
    printf("%d %d %c\n", c, r, k%2?'L':'R');
    return 0;
}