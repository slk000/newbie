//AC
//http://hihocoder.com/problemset/problem/1098
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
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
            if (rank[ancestor1] > rank[ancestor2]) {
                swap(ancestor1, ancestor2);
            }
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
priority_queue<Edge, vector<Edge>, greater<Edge> > edges;

void insert(int x, int y, int weight) {
    Edge tmp = { x, y, weight };
    edges.push(tmp);
}
int N, M;
int kruskal(int N) {
    DisjointSet d(N+1);
    int total_weight = 0;
    while (!edges.empty()) {
        Edge e = edges.top();
        edges.pop();
        if (d.find_set(e.from) != d.find_set(e.to)) {
            d.merge(e.from, e.to);
            total_weight += e.weight;
        }
    }
    return total_weight;
}
int main() {
    
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int from, to, weight;
        scanf("%d %d %d", &from, &to, &weight);
        insert(from, to, weight);
    }
    printf("%d\n", kruskal(N));
    return 0;
}
