//AC
//http://hihocoder.com/problemset/problem/1369
//����� Ford-Fulkerson ��DFSʵ��
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAX_V 510
#define INF 0x3f3f3f3f
typedef struct Edge {
	int from, to, rev;//reverse:from->to�����ߵķ���ߣ�to->from����G[to]�����е��±�
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
			//����һ��·�����һ���ߺ�һ����˳��ݹ飬��·��ÿ�������޸�������d=flow=�ô�����·���ϱߵ���С����
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
		int df = dfs(from, to, INF);//��һ��·��
		if (df == 0) return res;//�Ҳ�������·ʱres��Ϊ�������
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