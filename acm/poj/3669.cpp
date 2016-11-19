//AC
//http://poj.org/problem?id=3669
//bfs
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 410
#define INF 0x3f3f3f3f

int map[MAX][MAX];
int arriveTime[MAX][MAX];

int res = 0;
typedef struct P {
	int r, c, status, time;
	P() { r = c = status = time = 0; }
	P(int _r, int _c, int _t) :r(_r), c(_c), time(_t) {}
	P operator+(const P &b) {
		return P(r + b.r, c + b.c, time + 1);
	}
} P;

int R, C, sum;

P pp[5] = { { -1,0,0 },{ 1,0,0 },{ 0,-1,0 },{ 0,1,0 },{0,0,0} };//four adjacent pos and mid

inline bool check(P &p) { return p.r >= 0 && p.r < MAX && p.c >= 0 && p.c < MAX && arriveTime[p.r][p.c]==INF && map[p.r][p.c] > p.time; }//She cannot be located on a point at any time greater than or equal to the time it is destroyed

int b() {
	queue<P> qu;
	qu.push(P(0,0,0));
	while (!qu.empty()) {
		P cur = qu.front(); qu.pop();
		arriveTime[cur.r][cur.c] = 0;
		//printf("(%d, %d)\n", cur.r, cur.c);
		if (map[cur.r][cur.c]  == INF) {
			//printf("a %d\n", cur.time);
			return cur.time;
		}
		for (int i = 0; i < 4; i++) {
			P n = cur + pp[i];
			if (check(n) && n.time < arriveTime[n.r][n.c]) {  //剪。
				qu.push(n);
				arriveTime[n.r][n.c] = n.time;
			}
		}
	}
	return -1;
}

P pos[10];
int main() {
	memset(map, 0x3f, sizeof(map));
	memset(arriveTime, 0x3f, sizeof(arriveTime));
	scanf("%d", &sum);
	for (int i = 0; i < sum; i++) {
		int r, c, t;
		scanf("%d %d %d", &r, &c, &t);
		for (int j = 0; j < 5; j++) {
			P p = P(r, c, 0) + pp[j];
			if (p.r >= 0 && p.r < MAX && p.c >= 0 && p.c < MAX && map[p.r][p.c]>t) { //一个点可能被炸多次，取最早炸到时的时间
				map[p.r][p.c] = t;
			}
		}
	}
	printf("%d\n", b());
	return 0;
}