//AC
//http://bailian.openjudge.cn/practice/2945/
//http://bailian.openjudge.cn/2016acmmid/b/
#include <cstdio>
int max (int a, int b) {return a>b?a:b;}
int solve(int *arr, int n) {
    int dp[n];
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        int tmp=0;
        for (int j = 0; j < i; j++) {
            if (arr[i] <= arr[j])
                tmp = max(tmp, dp[j]);

        }
        dp[i] = max(dp[i], tmp+1);
        maxLen = max(maxLen, dp[i]);

    }
    return maxLen;
}
int main (){

    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", solve(arr, n));
    return 0;
}
