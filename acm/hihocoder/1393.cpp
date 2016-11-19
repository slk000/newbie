//AC
//http://hihocoder.com/problemset/problem/1393
//Edmonds-Karp 最大流 Ford-Fulkerson 的BFS实现
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
#define MAX_V 510
#define INF 0x3f3f3f3f
typedef struct Edge {
	int from, to, rev;//reverse:from->to这条边的反向边（to->from）在G[to]数组中的下标
	int cap;
	Edge() { cap = 0; }
	Edge(int f, int t, int c, int r) : from(f), to(t), cap(c), rev(r) {}
} Edge;
int N, M, need[MAX_V], a[MAX_V], b[MAX_V], goodAt[MAX_V][MAX_V];
vector<Edge> G[MAX_V];
void insert(int from, int to, int c) {
	G[from].push_back(Edge(from, to, c, G[to].size()));
	G[to].push_back(Edge(to, from, 0, G[from].size() - 1));
}
int vis[MAX_V];

Edge* p[MAX_V];
queue<int> work;
int bfs(int s, int t) {
	int res = 0;
	while (!work.empty()) {
		int cur = work.front();
		work.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			Edge &e = G[cur][i];
			if (!vis[e.to] && e.cap > 0) {
				p[e.to] = &e; //记录路径
				vis[e.to] = min(e.cap, vis[cur]);
				work.push(e.to);
			}
		}
		if (vis[t]) break;//这次增广没有路能到t了，退出
	}
	if (!vis[t]) return 0;
	for (int e = t; e != s; e = p[e]->from) { //从t倒着更新增广路上的边的容量
		p[e]->cap -= vis[t];
		G[e][p[e]->rev].cap += vis[t];
	}
	return vis[t];
}


int ff(int s, int t) {
	int flow = 0;
	while (1) {
		while (!work.empty()) work.pop();
		memset(vis, 0, sizeof(vis));
		vis[s] = INF;
		work.push(s);
		int newFlow = bfs(s, t);
		if (!newFlow) break;
		flow += newFlow;
	}
	return flow;
}
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= M; i++) {
			scanf("%d", &need[i]);

			insert(i + N, N + M + 1, need[i]);
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d %d", &a[i], &b[i]);
			for (int j = 0; j < b[i]; j++) {
				int to;
				scanf("%d", &to);
				to += N;
				insert(i, to, 1);
			}
			insert(0, i, a[i]);
		}
		ff(0, N + M + 1);

		bool res = true;
		for (int i = 1; i <= M; i++) {
			res &= (G[N+i][0].cap == 0); //判断b[i]->t是否满流。因为这些边都是在最早加的所以下标都是0
		}
		printf("%s\n", res?"Yes":"No");
		for (int i = 0; i <= N + M + 1; i++)G[i].clear();
		memset(p, 0, sizeof(p));
		memset(vis, 0, sizeof(vis));
	}
	return 0;
}