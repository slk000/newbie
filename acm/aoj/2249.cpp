//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2249
/*
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_NODE 10010
struct Edge {
	int vertex, weight,cost;
};
vector<Edge> *edges;
int M, N;
void insert(int x, int y, int weight, int cost) {
#define NON_DIRECTED
	Edge tmp = { y, weight,cost };
	edges[x].push_back(tmp);
#ifdef NON_DIRECTED
	tmp.vertex = x;
	edges[y].push_back(tmp);    //无向图
#endif
}
bool operator>(const Edge &a, const Edge &b) {
	if (a.weight == b.weight)
		return a.cost > b.cost;
	return a.weight > b.weight; 
}
int dist[MAX_NODE];
int cost[MAX_NODE];
int pre[MAX_NODE];
int dijkstra(int v) {
	int res=0;
	typedef Edge Path;    //最短距离、点编号
	memset(dist, 0x3f, sizeof(dist));
	memset(cost, 0x3f, sizeof(cost));
	memset(pre, -1, sizeof(pre));
	dist[v] = 0;
	//cost[v] = 0;
	priority_queue<Path, vector<Path>, greater<Path> > qu;  //存储各点距离源点的(最短)路径
	Path init = { v, 0,0 };
	qu.push(init);
	while (!qu.empty()) {
		Path min_path = qu.top();    //每次选一个距离源点最近的点（不一定是直接连接的）
		qu.pop();
		if (min_path.weight > dist[min_path.vertex]) continue;
		//res = min(res,min_path.cost);
		for (int i = 0; i < edges[min_path.vertex].size(); i++) {
			Edge &j = edges[min_path.vertex][i];
			if (min_path.weight + j.weight == dist[j.vertex]) {
				cost[j.vertex] = min(cost[j.vertex], j.cost);
			}
			else if (min_path.weight + j.weight < dist[j.vertex]) {
				dist[j.vertex] = min_path.weight + j.weight;
				Path newPath = { j.vertex, dist[j.vertex]};
				pre[j.vertex] = min_path.vertex;
				cost[j.vertex] =  j.cost;
				qu.push(newPath);    //如果需要更新这个点到源点的路径长，不必更新qu中已有数据，因为能优先队列保证用到它的时候总是取到最小的那个
			}
		}
	}
	for (int i = 2; i <= N; i++)res += cost[i];
	return res;
}

int main() {
	//freopen("e:/2249-input.txt", "r", stdin);
	
	while (EOF != scanf("%d %d", &N, &M) && N) {
		
		edges = new vector<Edge>[MAX_NODE];
		for (int i = 0; i < M; i++) {
			int from, to, dis,cost;

			scanf("%d %d %d %d", &from, &to, &dis, &cost);
			insert(from, to, dis, cost);
		}
		printf("%d\n", dijkstra(1));
		
		delete[] edges;
		
	}
	return 0;
}
*/
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_NODE 10010
struct Edge {
	int vertex, weight, cost;
};
vector<Edge> *edges;

void insert(int x, int y, int weight, int cost) {
#define NON_DIRECTED
	Edge tmp = { y, weight,cost };
	edges[x].push_back(tmp);
#ifdef NON_DIRECTED
	tmp.vertex = x;
	edges[y].push_back(tmp);    
#endif
}
bool operator>(const Edge &a, const Edge &b) {
	if (a.weight == b.weight)
		return a.cost > b.cost;
	return a.weight > b.weight;
}
int dist[MAX_NODE];

int pre[MAX_NODE];
bool vis[MAX_NODE];
int dijkstra(int v) {
	int res = 0;
	typedef Edge Path;
	memset(dist, 0x3f, sizeof(dist));
	memset(vis, false, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	dist[v] = 0;

	priority_queue<Path, vector<Path>, greater<Path> > qu;
	Path init = { v, 0,0 };
	//vis[v] = 1;
	qu.push(init);
	while (!qu.empty()) {
		Path min_path = qu.top();
		qu.pop();
		if (vis[min_path.vertex] || min_path.weight > dist[min_path.vertex]) continue;
		vis[min_path.vertex] = true;

		res += min_path.cost;
		for (int i = 0; i < edges[min_path.vertex].size(); i++) {
			Edge &j = edges[min_path.vertex][i];

			if (min_path.weight + j.weight <= dist[j.vertex])
			{
				dist[j.vertex] = min_path.weight + j.weight;

				Path newPath = { j.vertex, dist[j.vertex], j.cost };
				pre[j.vertex] = min_path.vertex;
				qu.push(newPath);
			}
		}
	}
	return res;
}

int main() {

	int M, N;
	while (EOF != scanf("%d %d", &N, &M) && N) {
		memset(dist, 0x3f, sizeof(dist));
		edges = new vector<Edge>[MAX_NODE];
		for (int i = 0; i < M; i++) {
			int from, to, dis, cost;

			scanf("%d %d %d %d", &from, &to, &dis, &cost);
			insert(from, to, dis, cost);
		}
		printf("%d\n", dijkstra(1));

		delete[] edges;

	}
	return 0;
}