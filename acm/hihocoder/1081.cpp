#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#define MAX_POS 1010
#define INF 0x3f3f3f3f
using namespace std;
typedef struct edge { int from, to, dis; } edge; //边起点、中点、长度
vector<edge> edges;
int d[MAX_POS]; //start到每个点的最短距离

void solve(int start) { //起点
	memset(d, INF, sizeof(d));
	d[start] = 0;
	while (1) {
		bool flag = true; // 没有更短的路或者没有可达点？
		for (int i = 0; i < edges.size(); i++) {
			edge thisEdge = edges[i];
			if (d[thisEdge.from] != INF && d[thisEdge.from] + thisEdge.dis < d[thisEdge.to]) { //此边可达且经过此边到to点的距离小于已有距离
				d[thisEdge.to] = d[thisEdge.from] + thisEdge.dis;
				flag = false;
			}
		}
		if (flag) break;
	}
}
int main() {
	int posSum, pathSum, start, end;
	scanf("%d %d %d %d", &posSum, &pathSum, &start, &end);
	for (int i = 0; i < pathSum; i++) {
		edge p;
		scanf("%d %d %d", &p.from, &p.to, &p.dis);
		edges.push_back(p);
		swap(p.from, p.to);
		edges.push_back(p);
	}
	
	solve(start);
	printf("%d\n", d[end]);
	return 0;
}