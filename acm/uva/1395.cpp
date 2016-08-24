//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=4141
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#define INF 0x3f3f3f3f
using namespace std;
int min(int a, int b) { return a < b ? a : b; }
class DisjointSet {
private:
	int *father, *rank;
public:
	DisjointSet(int size) {
		father = new int[size];
		rank = new int[size];
		for (int i = 0; i < size; ++i) {
			father[i] = i;
			rank[i] = 0;
		}
	}
	~DisjointSet() {
		delete[] father;
		delete[] rank;
	}
	int find_set(int node) {
		if (father[node] != node) {
			father[node] = find_set(father[node]);

		}
		return father[node];
	}
	bool merge(int node1, int node2) {
		int ancestor1 = find_set(node1);
		int ancestor2 = find_set(node2);
		if (ancestor1 != ancestor2) {
#ifdef ROUTE_COMPRESS
			if (rank[ancestor1] > rank[ancestor2]) {
				swap(ancestor1, ancestor2);
			}
#endif
			father[ancestor1] = ancestor2;
			rank[ancestor2] = max(rank[ancestor1] + 1, rank[ancestor2]);
			return true;
		}
		return false;
	}
};
struct Edge {
	int from, to, weight;
};
bool operator>(const Edge &a, const Edge &b) { return a.weight > b.weight; }
bool operator<(const Edge &a, const Edge &b) { return a.weight < b.weight; }

vector<Edge> edges2;

void insert(int x, int y, int weight) {
	Edge tmp = { x, y, weight };
	edges2.push_back(tmp);

}
int N, M;

int solve() {
	int ans = INF;
	sort(edges2.begin(), edges2.end());
	for (int L = 0; L < M; L++) { 
		DisjointSet d(N+1);
		int cnt = 0;
		int min = INF, max = -1;
		for (int R = L; R < M; R++) {  //��������[L,R]

			cnt += d.merge(edges2[R].from, edges2[R].to);  //�ϲ�һ�ξʹ������е��������ж�һ����
			if (cnt == N - 1) {  //N������������ܹ���ϲ�N-1�Σ��������Ѿ������һ��������
				ans = ::min(ans,edges2[R].weight - edges2[L].weight); //���������������һ����R��С��һ����L����Ϊ���Ź���
				break; //��ʱ������չR������õ���С�Ĵ�
			}
		}
	}
	return ans==INF?-1:ans;
}
int main() {

	while (EOF!=scanf("%d %d", &N, &M) && (N || M)) {
			
		edges2.clear();

		for (int i = 0; i < M; i++) {
			int from, to, weight;
			scanf("%d %d %d", &from, &to, &weight);
			insert(from, to, weight);  
		}
		
		printf("%d\n", solve());
		
	}
	return 0;
}