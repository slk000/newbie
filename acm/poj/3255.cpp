//AC
//http://poj.org/problem?id=3255
//dijkstra
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_NODE 5010
struct Edge {
    int vertex, weight;
};
vector<Edge> edges[MAX_NODE];

void insert(int x, int y, int weight) {
    #define NON_DIRECTED
    Edge tmp = { y, weight };
    edges[x].push_back(tmp);
#ifdef NON_DIRECTED
    tmp.vertex = x;
    edges[y].push_back(tmp);    //无向图
#endif
}
bool operator>(const Edge &a, const Edge &b) { return a.weight > b.weight; }

int N, M;  //节点个数
int dist[MAX_NODE];
int dist2[MAX_NODE];
void dijkstra(int v) {
    typedef Edge Path;    //最短距离、点编号
    memset(dist, 0x3f, sizeof(dist));
	memset(dist2, 0x3f, sizeof(dist));
    dist[v] = 0;
    priority_queue<Path, vector<Path>, greater<Path> > qu;  //存储各点距离源点的(最短)路径
    Path init = { v, 0 };
    qu.push(init);
    while (!qu.empty()) {
        Path min_path = qu.top();    //每次选一个距离源点最近的点（不一定是直接连接的）
        qu.pop();
        if (min_path.weight > dist2[min_path.vertex]) continue;

        for (int i = 0; i < edges[min_path.vertex].size(); i++) {
            Edge &j = edges[min_path.vertex][i];
			int newlength = min_path.weight + j.weight;
            if (newlength < dist[j.vertex]) {  //取得次短路就是加一个次短路dist2，计算方法和在一堆数中取最小的两个值一样
				dist2[j.vertex] = dist[j.vertex];  //如果有值比当前的最小值小，那么这个值成为新的最小值，以前的最小值成为次小值
                dist[j.vertex] = newlength;
                Path newPath = { j.vertex, dist[j.vertex] };
                qu.push(newPath);   
            }
			else if (newlength > dist[j.vertex] && newlength < dist2[j.vertex]) {//如果一个数直接就是次小值，直接更新dist2
				dist2[j.vertex] = newlength;
				Path newPath = { j.vertex, dist2[j.vertex] };
				qu.push(newPath);
			}
        }
    }
}

int main() {
   
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int from, to, dis;
        scanf("%d %d %d", &from, &to, &dis);
        insert(from, to, dis);
    }
	dijkstra(1);
	printf("%d\n", dist2[N]);
    return 0;
}