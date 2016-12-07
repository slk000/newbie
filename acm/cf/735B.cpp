//AC
//http://codeforces.com/problemset/problem/735/B
//Codeforces Round #382 (Div. 2) B
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <queue> 
#include <algorithm> 
using namespace std;
#define MAX 100000
typedef long long LL;
int n, n1, n2;
int arr[MAX + 10];

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif   
    scanf("%d %d %d", &n, &n1, &n2);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + n);
    double res = 0;
    //for(int i = 0; i <n;i++)printf("%d\n",arr[i]);
    if (n1 > n2)swap(n1, n2);
    if (n1 <= n2) {
        LL sum1 = 0, sum2 = 0; //fuck int
        int i;
        for (i = 0; n - i - 1 >= 0 && i<n1; i++) { // 求最大的n1个数的和
            sum1 += arr[n - i - 1];
        }

        for (int j = 0; n - n1 - j>-0 && j<n2; j++) {
            sum2 += arr[n - n1 - 1 - j];
        }
        res = ((double)sum1 / (double)n1) + ((double)sum2 / (double)n2);
    }

    printf("%lf\n", res);
    return 0;
}