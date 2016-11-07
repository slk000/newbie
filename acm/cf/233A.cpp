//AC
//http://codeforces.com/problemset/problem/233/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[30];

int main() {
    
    int n;
    scanf("%d", &n);
    if (n & 1) {
        printf("-1\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                printf("%d ", i + 1);
            }
            else {
                printf("%d ", i - 1);
            }
        }
    }
    printf("\n");
    return 0;
}
