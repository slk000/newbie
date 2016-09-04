//AC
//http://poj.org/problem?id=3050
//force dfs
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 5
set<int> s;
const int rr[] = { -1,1,0,0 };
const int cc[] = { 0,0,-1,1 };
const int pows[] = { 100000,10000,1000,100,10,1 };
bool check(int r, int c) { return r >= 0 && r < MAX&&c >= 0 && c < MAX; }
int map[MAX][MAX];
void d(int r, int c, int depth, int number) {
	if (depth == 6) {
		s.insert(number);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nr = rr[i] + r;
		int nc = cc[i] + c;
		if (check(nr, nc)) {
			d(nr, nc, depth + 1, number + map[r][c] * pows[depth]);
		}
	}
}

int main() {
	for (int i = 0; i < MAX; ++i) {
		for (int j = 0; j < MAX; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			d(i, j, 0, 0);
		}
	}
	printf("%d\n", s.size());
	return 0;
}