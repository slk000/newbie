#include <cstdio>
int nums[100000];
int dp[100000];
int main (){
	int T;
	scanf("%d", &T);
	for (int N = 0; N < T; N++) {
		int n;
		scanf("%d", &n);
		int max = -100001;
		int tmpSum = 0;
		int start=1, end=0;
		for (int i = 1; i <= n; i++) {
            scanf("%d", &nums[i]);
            tmpSum+=nums[i];
            if (tmpSum>=0) {
                dp[i]=tmpSum;
                end++;
            }
            else{
                dp[i]=nums[i];
                tmpSum=nums[i];
                start=i;
            }
            if(max<dp[i]){
                max=dp[i];
                end = i;
            }
        }
        
       
        printf("%d %d %d", max, start, end);
        if(N!=T-1)printf("\n");
	}
	return 0;
}
