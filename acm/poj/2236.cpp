//AC
//http://poj.org/problem?id=2236
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1002
pair<double,int> dist[MAX][MAX];
int x[MAX];
int y[MAX];
bool isRepaired[MAX];

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
int main() {
	//freopen("in.txt", "r", stdin);
    int N;
	double D;
    scanf("%d %lf", &N, &D);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for (int i = 0; i <= N; i++) {
        for (int j = i; j < N; j++) {
            dist[i][j] = make_pair(sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j])), j);
            dist[j][i] = dist[i][j];
			dist[j][i].second = i;
        }
    }
    DisjointSet d(N + 1);

    char op; int a;
    //pair<double,int> tmpDist[MAX];
	getchar();
    while (EOF != scanf("%c %d", &op, &a)) {
		a--;
        switch (op)
        {
		case 'O': {
			pair<double, int> *tmpDist = dist[a];
			//memcpy(tmpDist, dist[a], sizeof(dist[a]));
			//sort(tmpDist, tmpDist + N);
			for (int i = 0; i < N; i++) {
				if (isRepaired[tmpDist[i].second] && tmpDist[i].first <= D) {
					d.merge(a, tmpDist[i].second);
					//printf("merge %d and %d\n", a, tmpDist[i].second);
				}
			}
			isRepaired[a] = true;
			break;
		}
        case 'S': {
            int b;
            scanf("%d", &b);
			b--;
            bool isOk = d.find_set(a) == d.find_set(b);
            printf(isOk ? "SUCCESS\n" : "FAIL\n");
            break;
        }
        default:
            break;
        }
    }
    return 0;
}
