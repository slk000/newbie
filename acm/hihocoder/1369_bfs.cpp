//AC
//http://hihocoder.com/problemset/problem/1369
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
	Edge(int f, int t, int c, int r): from(f),to(t),cap(c),rev(r) {}
} Edge;

vector<Edge> G[MAX_V];
void insert(int from, int to, int c) {
	G[from].push_back(Edge(from, to, c, G[to].size()));
	G[to].push_back(Edge(to, from, 0, G[from].size() - 1));
}
int vis[MAX_V];

Edge* p[MAX_V];
queue<int> work;
int bfs(int s, int t){
	int res = 0;
	while(!work.empty()) {
		int cur = work.front();
		work.pop();
		for (int i = 0; i < G[cur].size(); i++) {
			Edge &e = G[cur][i];
			if (!vis[e.to] && e.cap > 0){
				p[e.to] = &e; //记录路径
				vis[e.to] = min(e.cap, vis[cur]);
				work.push(e.to);
			}
		}
		if(vis[t]) break;//这次增广没有路能到t了，退出
	}
	if (!vis[t]) return 0;
	for (int e = t; e != s; e = p[e]->from){ //从t倒着更新增广路上的边的容量
		p[e]->cap -= vis[t];
		G[e][p[e]->rev].cap += vis[t];
	}
	return vis[t];
}


int ff(int s, int t){
	int flow = 0;
	while(1){
		while(!work.empty()) work.pop();
		memset(vis, 0, sizeof(vis));
		vis[s] = INF;
		work.push(s);
		int newFlow = bfs(s, t);
		if(!newFlow) break;
		flow += newFlow;
	}
	return flow;
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