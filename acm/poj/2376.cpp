//AC
//http://poj.org/problem?id=2376
//greedy
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <functional>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_T 1000000

int rights[MAX_T]; //rights[i] = the right border of an interval with left boarder i
int N, T;
int main() {
	//freopen("in.txt", "r", stdin);
	//while (EOF != scanf("%d %d", &N, &T)) 
	{
		scanf("%d %d", &N, &T);
		//memset(rights, 0, sizeof(rights));
		int maxRight = -INF;
		int ans = 1;
		for (int i = 0; i < N; i++) {
			int L, R;
			scanf("%d %d", &L, &R);
			if (L == 1) {
				maxRight = max(R, maxRight);
			}
			else {
				rights[L] = max(rights[L], R);
			}
		}
		
		if (maxRight == -INF) { //no interval start from 1
			printf("-1\n");
			return 0;//continue;//
		}
		int lastLeft = 1;
		while (maxRight < T) {
			int m = maxRight;
			for (int left = lastLeft; left <= maxRight + 1; left++) { //find a new maxRight m in the **interval** 
				if (rights[left] > m) {								//whose left is in the reachable interval currently
					m = rights[left];									//and right is greater
					lastLeft = left;
				}
			}
			
			if (m != maxRight) {	// find a new right border
				maxRight = m;
				ans++;
			}
			else {
				ans = -1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}