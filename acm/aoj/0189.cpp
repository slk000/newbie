//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0189
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_NODE 1000
struct Edge {
	int vertex, weight;
};
vector<Edge> *edges;

void insert(int x, int y, int weight) {
#define NON_DIRECTED
	Edge tmp = { y, weight };
	edges[x].push_back(tmp);
#ifdef NON_DIRECTED
	tmp.vertex = x;
	edges[y].push_back(tmp);    //����ͼ
#endif
}
bool operator>(const Edge &a, const Edge &b) { return a.weight > b.weight; }
int dist[MAX_NODE];
void dijkstra(int v) {
	typedef Edge Path;    //��̾��롢����
	memset(dist, 0x3f, sizeof(dist));
	dist[v] = 0;
	priority_queue<Path, vector<Path>, greater<Path> > qu;  //�洢�������Դ���(���)·��
	Path init = { v, 0 };
	qu.push(init);
	while (!qu.empty()) {
		Path min_path = qu.top();    //ÿ��ѡһ������Դ������ĵ㣨��һ����ֱ�����ӵģ�
		qu.pop();
		if (min_path.weight > dist[min_path.vertex]) continue;

		for (int i = 0; i < edges[min_path.vertex].size(); i++) {
			Edge &j = edges[min_path.vertex][i];
			if (min_path.weight + j.weight < dist[j.vertex]) {
				dist[j.vertex] = min_path.weight + j.weight;
				Path newPath = { j.vertex, dist[j.vertex] };
				qu.push(newPath);    //�����Ҫ��������㵽Դ���·���������ظ���qu���������ݣ���Ϊ�����ȶ��б�֤�õ�����ʱ������ȡ����С���Ǹ�
			}
		}
	}
}

int main() {
	int M;
	while (EOF != scanf("%d", &M) && M) {
		int N = -1;
		edges = new vector<Edge>[MAX_NODE];
		int res1 = 0;
		int res2 = INF;
		for (int i = 0; i < M; i++) {
			int from, to, dis;

			scanf("%d %d %d", &from, &to, &dis);
			N = max(from, N);
			N = max(to, N);
			insert(from, to, dis);
		}
		for (int i = 0; i <= N; i++) {
			dijkstra(i);
			int tmp = 0;
			for (int j = 0; j <= N; j++)
				tmp += dist[j];
			if (tmp < res2) {
				res2 = tmp;
				res1 = i;
			}
		}
		delete[] edges;
		printf("%d %d\n", res1, res2);
	}
	return 0;
}
