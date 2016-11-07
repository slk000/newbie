//AC
//http://codeforces.com/problemset/problem/69/A
//calc sum of vector
#include <cstdio>
using namespace std;
int main() {
    int n;
    int a, b, c;
    while (EOF != scanf("%d", &n)) {
        int sumA = 0, sumB = 0, sumC = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &a, &b, &c);
            sumA += a; sumB += b; sumC += c;
        }
        if (sumA == 0 && sumB == 0 && sumC == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    
    return 0;
}