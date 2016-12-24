#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 100000
int arr[MAX + 10];
using namespace std;
int digSum(int n) {
    int s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}
int main() {
    for (int i = 1; i <= MAX; i++) {
        int t = i + digSum(i);
        if(!arr[t]) arr[t] = i;
    }
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", arr[n]);
    }

    return 0;
}
