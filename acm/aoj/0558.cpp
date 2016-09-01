//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0558

#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define MAX 1010
#define INF 0x3f3f3f3f
int st = 1;
char map[MAX][MAX];
//char map2[MAX][MAX];
bool vis[MAX][MAX];
int res = 0;
typedef struct P {
	int r, c, status, steps;
	P() { r = c = status = steps = 0; }
	P(int _r, int _c, int _st) :r(_r), c(_c), steps(_st) {}
	P operator+(const P &b) {
		return P(r + b.r, c + b.c, steps + 1);
	}
} P;

int R, C, sum;

P start, end;
P pp[4] = { { -1,0,0 },{ 1,0,0 },{ 0,-1,0 },{ 0,1,0 } };

inline bool check(P &p) { return p.r >= 0 && p.r < R && p.c >= 0 && p.c < C && !vis[p.r][p.c] && map[p.r][p.c] != 'X'; }

void b(int aim) {
	queue<P> qu;

	qu.push(start);
	memset(vis, 0, sizeof(vis));
	vis[start.r][start.c] = 1;

	while (!qu.empty()) {
		P cur = qu.front(); qu.pop();
		//printf("(%d, %d)\n", cur.r, cur.c);
		if (map[cur.r][cur.c] - '0' == aim) {
			//printf("a %d\n", cur.steps);
			res += cur.steps;
			return;
		}
		for (int i = 0; i < 4; i++) {
			P n = cur + pp[i];
			if (check(n)) {
				qu.push(n);
				vis[n.r][n.c] = 1; //£¿£¿
			}
		}

	}

}

P pos[10];
int main() {
	scanf("%d %d %d", &R, &C, &sum);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == '\n') { j--; continue; }
			if (map[i][j] == 'S') {
				pos[0].r = i;
				pos[0].c = j;
			}
			if (map[i][j] >= '1' && map[i][j] <= '9') {
				pos[map[i][j] - '0'].r = i;
				pos[map[i][j] - '0'].c = j;
			}
		}
	}
	for (int i = 0; i < sum; i++) {
		start = pos[i];
		b(i + 1);
	}
	printf("%d\n", res);
	return 0;
}