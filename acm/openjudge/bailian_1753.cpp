//AC
//BFS
//http://bailian.openjudge.cn/2016acmmid/g/
//http://bailian.openjudge.cn/practice/1753/

//ref.
//http://www.cnblogs.com/jackge/archive/2013/03/04/2943316.html
//http://www.cnblogs.com/lyy289065406/archive/2011/07/29/2120501.html
#include <cstdio>
#include <queue>
#include <memory.h>
#define MAX_S 1<<16
#define MAX 4
using namespace std;

bool vis[MAX_S];
int steps[MAX_S];
int rr[] = { -1, 1, 0, 0, 0 };
int cc[] = { 0, 0, -1, 1, 0 };
bool hasSolutions;
queue<int> qu;
int change(int r, int c, int status) {
	status ^= (1 << ((MAX - 1 - r)*MAX)) << (MAX - 1 - c);
	return status;
}
bool get(int r, int c, int status) {
	return (status >> (MAX - 1 - c)) >> (r*MAX) & 1;
}
int flip(int r, int c, int status) {

	for (int i = 0; i < 5; i++) {
		int nr = r + rr[i], nc = c + cc[i];
		if (nr >= 0 && nr < MAX && nc >= 0 && nc < MAX) {
			status = change(nr, nc, status);
		}
	}
	return status;
}
void b() {
	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		if (cur == 0 || cur == 0xffff) {
			hasSolutions = true;
			printf("0\n");
			return;
		}
		int next = cur;

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				next = flip(i, j, cur);

				if (next == 0 || next == 0xffff) {
					printf("%d\n", steps[cur] + 1);
					hasSolutions = true;
					return;
				}
				if (!vis[next]) {
					steps[next] = steps[cur] + 1;
					vis[next] = true;
					qu.push(next);
				}
			}
		}
	}

}
int main() {
	int input = 0;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 + 1; j++) {
			char tmp;
			scanf("%c", &tmp);
			if (tmp == '\n') {
				break;
			}

			if (tmp == 'b') {
				input = change(i, j, input);
			}
		}

	}
	qu.push(input);
	vis[input] = true;
	steps[input] = 0;
	b();
	if (!hasSolutions) {
		printf("Impossible\n");
	}
	return 0;
}

