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
    edges[y].push_back(tmp);    //����ͼ
#endif
}
bool operator>(const Edge &a, const Edge &b) { return a.weight > b.weight; }

int N, M;  //�ڵ����
int dist[MAX_NODE];
int dist2[MAX_NODE];
void dijkstra(int v) {
    typedef Edge Path;    //��̾��롢����
    memset(dist, 0x3f, sizeof(dist));
	memset(dist2, 0x3f, sizeof(dist));
    dist[v] = 0;
    priority_queue<Path, vector<Path>, greater<Path> > qu;  //�洢�������Դ���(���)·��
    Path init = { v, 0 };
    qu.push(init);
    while (!qu.empty()) {
        Path min_path = qu.top();    //ÿ��ѡһ������Դ������ĵ㣨��һ����ֱ�����ӵģ�
        qu.pop();
        if (min_path.weight > dist2[min_path.vertex]) continue;

        for (int i = 0; i < edges[min_path.vertex].size(); i++) {
            Edge &j = edges[min_path.vertex][i];
			int newlength = min_path.weight + j.weight;
            if (newlength < dist[j.vertex]) {  //ȡ�ôζ�·���Ǽ�һ���ζ�·dist2�����㷽������һ������ȡ��С������ֵһ��
				dist2[j.vertex] = dist[j.vertex];  //�����ֵ�ȵ�ǰ����СֵС����ô���ֵ��Ϊ�µ���Сֵ����ǰ����Сֵ��Ϊ��Сֵ
                dist[j.vertex] = newlength;
                Path newPath = { j.vertex, dist[j.vertex] };
                qu.push(newPath);   
            }
			else if (newlength > dist[j.vertex] && newlength < dist2[j.vertex]) {//���һ����ֱ�Ӿ��Ǵ�Сֵ��ֱ�Ӹ���dist2
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