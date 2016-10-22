//AC
//http://hihocoder.com/problemset/problem/1037
//simple dp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 35000
int dp[MAX_N];
#define INF 0x3f3f3f3f
int N;
int main (){
	scanf("%d", &N);
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= N; i++){
		for (int j = i; j >= 1; j-- ){
			int s;
			scanf("%d", &s);
			if (j == 1){
				dp[j] += s;
			}
			else if(i == j){
				dp[j] = dp[j-1] + s;
			}
			else{
				dp[j] = max(dp[j],dp[j-1]) + s;
			}
		}
	}
	int res = -INF;
	for (int i = 1; i <= N; i++){
		res = max(res, dp[i]);
	}
	printf("%d\n", res);
	return 0;
}