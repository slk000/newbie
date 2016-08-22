#include <cstdio>
#include <queue>
#include <vector>
#include <memory.h>
#define MAX_POS 1010
#define INF 0x3f3f3f3f
using namespace std;
typedef struct edge { int from, to, dis; } edge; //����㡢�е㡢����
vector<edge> edges;
int d[MAX_POS]; //start��ÿ�������̾���

void solve(int start) { //���
	memset(d, INF, sizeof(d));
	d[start] = 0;
	while (1) {
		bool flag = true; // û�и��̵�·����û�пɴ�㣿
		for (int i = 0; i < edges.size(); i++) {
			edge thisEdge = edges[i];
			if (d[thisEdge.from] != INF && d[thisEdge.from] + thisEdge.dis < d[thisEdge.to]) { //�˱߿ɴ��Ҿ����˱ߵ�to��ľ���С�����о���
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