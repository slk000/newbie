//AC
//http://hihocoder.com/problemset/problem/1369
//最大流 Ford-Fulkerson 的DFS实现
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 510
#define INF 0x3f3f3f3f
typedef struct Edge {
	int from, to, rev;//reverse:from->to这条边的反向边（to->from）在G[to]数组中的下标
	int cap;
	Edge() { cap = 0; }
	Edge(int f, int t, int c, int r): from(f),to(t),cap(c),rev(r) {}
} Edge;

vector<Edge> G[MAX_V];
bool vis[MAX_V];
void insert(int from, int to, int c) {
	G[from].push_back(Edge(from, to, c, G[to].size()));
	G[to].push_back(Edge(to, from, 0, G[from].size() - 1));
}
int dfs(int from, int to, int flow) {
	vis[from] = true;
	if (from == to) return flow;
	for (int i = 0; i < G[from].size(); i++) {
		Edge &e = G[from][i];
		if (!vis[e.to] && e.cap > 0) {
			int d = dfs(e.to, to, min(e.cap, flow));
			//找完一条路径最后一个边后一层层退出递归，在路径每条边上修改流量，d=flow=该次增广路径上边的最小容量
			if (d > 0) {
				e.cap -= d;
				G[e.to][e.rev].cap += d;
				return d;
			}
		}
	}
	return 0;
}
int ff(int from, int to) {
	int res = 0;
	while (1) {
		memset(vis, 0, sizeof(vis));
		int df = dfs(from, to, INF);//找一条路径
		if (df == 0) return res;//找不到增广路时res即为最大流量
		res += df;
	}
}
int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		insert(u, v, c);
	}
	printf("%d\n",ff(1, N));

	return 0;
}