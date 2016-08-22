#include <cstdio>
#define N 50
int dp[N+1];
int main (){
    int n;
    dp[0] = dp[1] = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    printf("%d\n", dp[n]);
    return 0;
}