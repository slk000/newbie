//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0121
//bfs 康托展开
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define N 8
const int fac[] = { 1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880 };///阶乘  

int s2c(int s[], int n)  //康托
{
	int i, j, cnt, sum;
	sum = 0;
	for (i = 0; i < n; ++i)
	{
		cnt = 0;
		for (j = i + 1; j < n; ++j)
			cnt += (s[j] < s[i]);
		sum += cnt * fac[n - i - 1];
	}
	return sum;
}


//n-1数码，第k个排列  
void c2s(int ans[], int n, int k)  //逆康托
{
	bool vis[10];
	int i, j, t;
	memset(vis, 0, sizeof(vis));
	//--k;
	for (i = 0; i < n; ++i)
	{
		t = k / fac[n - i - 1];
		for (j = 0; j < n; j++)
			if (!vis[j])
			{
				if (t == 0) break;
				--t;
			}
		ans[i] = j, vis[j] = true;
		k %= fac[n - i - 1];
	}
}

enum Move{UP,DOWN,LEFT,RIGHT};
int move(int c, int op) {
	
	int tmp[20];
	c2s(tmp, N, c);
	int zeroPos;

	for (zeroPos = 0; tmp[zeroPos] != 0; ++zeroPos);

	switch (op)
	{
	case UP:
		if (zeroPos <= 3) return -1;
		swap(tmp[zeroPos], tmp[zeroPos - 4]);
		break;
	case DOWN:
		if (zeroPos >= 4) return -1;
		swap(tmp[zeroPos], tmp[zeroPos + 4]);
		break;
	case LEFT:
		if (zeroPos == 0 || zeroPos == 4) return -1;
		swap(tmp[zeroPos], tmp[zeroPos - 1]);
		break;
	case RIGHT:
		if (zeroPos == 3 || zeroPos == 7) return -1;
		swap(tmp[zeroPos], tmp[zeroPos + 1]);
		break;
	default:
		break;
	}
	return s2c(tmp, N);
}
int start = 0;
int vis[50000];
int b(/*int aim*/) {
	memset(vis, 0x3f, sizeof(vis));

	queue<int> qu;
	
	qu.push(start);
	vis[start] = 0;
	while (!qu.empty()) {
		int cur = qu.front(); qu.pop();
		/*if (cur == aim) {
			//printf("a %d\n", vis[cur]);
			return vis[cur];
		}*/
		for (int i = 0; i < 4; i++) {
			int n = move(cur, i);
			//if (n != -1 && INF == vis[n]) {
			if (n != -1 && vis[cur] + 1 < vis[n]) {
				qu.push(n);
				vis[n] = vis[cur]+1;
			}
		}
	}
	return -1;
}

int main() {
	int tmp[N] = { 0,1,2,3,4,5,6,7 };
	b();//打表从goal开始找出全部有解状态

	while (EOF != scanf("%d %d %d %d %d %d %d %d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &tmp[4], &tmp[5], &tmp[6], &tmp[7])) {
		start = s2c(tmp, N);
		printf("%d\n",vis[start]);
	}
	return 0;
}