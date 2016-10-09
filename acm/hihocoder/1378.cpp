//AC
//http://hihocoder.com/problemset/problem/1378
//求最大流最小割
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define MAX_V 510
#define INF 0x3f3f3f3f

//Edmonds-Karp 最大流 Ford-Fulkerson 的BFS实现
typedef struct Edge {
	int from, to, rev;//reverse:from->to这条边的反向边（to->from）在G[to]数组中的下标
	int cap;
	int origin_cap;
	bool pos;
	Edge() { cap = origin_cap = 0; }
	Edge(int f, int t, int c, int r, bool p) : from(f), to(t), cap(c), rev(r), pos(p) { origin_cap = cap; }
} Edge;

vector<Edge> G[MAX_V];
void insert(int from, int to, int c) {
	G[from].push_back(Edge(from, to, c, G[to].size(), true));
	G[to].push_back(Edge(to, from, 0, G[from].size() - 1, false));
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

int N, M;

//在最大流的剩余网络上求最小割
//参数：源点编号，存储S集合的数组
void bfs2(int s, vector<int> &res){
	queue<int> qu;
	bool vis2[MAX_V];memset(vis2, 0, sizeof(vis2));
	qu.push(s);
	res.push_back(s);
	vis2[s] = true;
	while(!qu.empty()){
		int cur = qu.front();qu.pop();
		for (int i = 0; i < G[cur].size(); i++){
			Edge &e = G[cur][i];
			if (!vis2[e.to] && e.cap != 0){  //容量为0的点不在剩余网络中
				qu.push(e.to);
				vis2[e.to] = true;
				res.push_back(e.to);
			}
		}
	}
}
int main() {
	
	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		insert(u, v, c);
	}
	printf("%d ", ff(1, N));
	
	vector<int> res;
	bfs2(1, res);
	printf("%d\n",res.size());
	for (vector<int>::iterator it = res.begin(); it != res.end(); it++){
		printf("%d ", *it);
	}
	printf("\n");
	
	return 0;
}