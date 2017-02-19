//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1003
//DP
#include <cstdio>
#define INF 0x3f3f3f3f
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    for (int N = 0; N < T; N++) {
        int n;
        scanf("%d", &n);
        int maxSum = -INF;
        int maxStart, maxEnd;
        int tmpStart = 1, tmpEnd = 1; 
        int tmpSum = 0; //记录累加过程中的和
        for (int i = 1; i <= n; i++) {
            int num;
            scanf("%d", &num);
            if (tmpSum >= 0) { 
                tmpSum += num; //如果这次num为负，那么加之前的状态已经才在max中了
                tmpEnd++;
            }
            else { //和为负，重新开始记区间
                tmpSum = num;
                tmpStart = i;
            }
            if (maxSum < tmpSum) {
                maxSum = tmpSum;
                maxStart = tmpStart;
                maxEnd = i;
            }
        }

        printf("Case %d:\n", N + 1);
        printf("%d %d %d\n", maxSum, maxStart, maxEnd);
        if (N != T - 1) printf("\n");
    }
    return 0;
}