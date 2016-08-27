//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0118
//dfs
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 110
char map[MAX][MAX];
int H, W;
int res = 0;
int cc[4] = { 0,0,-1,1 };
int rr[4] = { -1,1,0,0 };
void d(int r, int c) {
	char old = map[r][c];
	map[r][c] = -1;
	for (int i = 0; i < 4; i++) {
		int nc = c+cc[i],
			nr = r+rr[i];
		if (nc >= 0 && nc < W && nr >= 0 && nr < H &&map[nr][nc]!=-1&& map[nr][nc] == old) {
			d(nr, nc);
		}
		
		
	}
}
int main() {
	
	while (scanf("%d %d", &H, &W) && H && W) {
		res = 0;
		for (int i = 0; i < H; i++) {
			scanf("%s", map[i]);
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (map[i][j] != -1) {
					d(i, j);
					res++;
				}
			}
		}
		
		printf("%d\n", res);
	}
	return 0;
}