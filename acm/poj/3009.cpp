//AC
//http://poj.org/problem?id=3009
//dfs
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
#define MAX 25
#define INF 0x3f3f3f3f
bool map[MAX][MAX];

int startR, startC, endR, endC;
int res = INF;
int R, C;
int rr[4] = { -1,1,0,0 };
int cc[4] = { 0,0,-1,1 };
//char route[15];
inline bool check(int &r, int &c) { return r >= 0 && r < R && c >= 0 && c < C; }

//char str[] = { 'u','d','l','r' };
void d(int r, int c, int depth) {

	if (depth > 10)return;
	if (r == endR && c == endC) {
		//str[depth] = '\n';
		res = min(res, depth); //dfs所有结果取最小
							   //printf("find at (%d, %d)\n%s depth%d\n", r, c, str,depth);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		if (map[r + rr[i]][c + cc[i]] == 1)continue; //紧挨着的砖块不能靠移动来弄碎
		bool crash = false;
		int nr = r + rr[i], nc = c + cc[i];
		for (; check(nr, nc) && map[nr][nc] == 0; nr += rr[i], nc += cc[i]) {//不断往那个方向走
			if (nr == endR && nc == endC) {//只要途径了终点就行
				goto win;
			}
		}

		if (!check(nr, nc))continue;//冲过头

		if (map[nr][nc] == 1) { map[nr][nc] = 0; crash = true; } //此时(nr,nc)是冰壶停下来的地方再过去一个。如果有砖块则撞碎
	
		nr -= rr[i]; nc -= cc[i]; //冰壶停下的位置

		//printf("(%d, %d)", nr, nc);

		//printf("%c\n", str[i]);
		//route[depth] = str[i];
	win:
		d(nr, nc, depth + 1);

		if (crash)
			map[nr + rr[i]][nc + cc[i]] = 1;
	}

}
int main() {


	while (scanf("%d %d", &C, &R) && C && R) {
		
		res = INF;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int tmp;
				scanf("%d", &tmp);
				if (tmp == 1)
					map[i][j] = true;
				else
					map[i][j] = false;
				if (tmp == 2) {
					startR = i;
					startC = j;
				}
				else if (tmp == 3) {
					endR = i;
					endC = j;
				}
			}
		}
		
		d(startR, startC, 0);
		printf("%d\n", res == INF ? -1 : res);
	}
	return 0;
}