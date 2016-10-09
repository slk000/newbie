//AC
//http://hihocoder.com/problemset/problem/1227
//brute force
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <memory.h>
using namespace std;
#define MAX_N 100
#define INF 1234567
double dis[MAX_N + 5][MAX_N + 5];
double x[MAX_N + 5], y[MAX_N + 5];
const double eps = 10e-6;
int M, N;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int res = INF;
		scanf("%d %d", &M, &N);
		
		for (int i = 0; i < M; i++) {
			scanf("%lf %lf", &x[i], &y[i]);
		}
		if (M < N) goto no;
		for (int i = 0; i < M; i++) {//每两点的距离
			for (int j = i; j < M; j++) {
				dis[i][j] = sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]));
				dis[j][i] = dis[i][j];
			}
		}

		
		for (int i = 0; i < M; i++) { //以每个点为圆心

			int tmp = 0;
			//double d[MAX_N];
			//memcpy(d, dis[i],sizeof(d));
			sort(dis[i], dis[i] + M);

			tmp = ceil(dis[i][N-1]); //需要包含N个点，则需要 到从近到远第N-1个点的距离 那么大的圈，并向上取整
			
			if (fabs(ceil(dis[i][N-1]) - dis[i][N-1]) < eps) tmp++; //ceil(d[N-1]) == d[N-1] //如果这个点正好在是整数距离（ceil没卵用），则半径外扩1
			if(N<M && dis[i][N] <= tmp) {//扩了之后如果有新点被阔进来了，就是-1的情况
			//if (fabs(d[N] - tmp) < eps) {
				tmp = INF;
				//continue;
			}


			res = min(tmp, res);
		}
		no:
		printf("%d\n",res==INF?-1:res);
	}
	return 0;
}