#include <cstdio>
using namespace std;
int main () {
	int N, M;
	scanf("%d %d", &N, &M);
	bool map[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}/*
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}*/

	
	return 0;
}
