//AC
//http://hihocoder.com/problemset/problem/1097
//最小生成树模板题
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {
    int vertex, weight;
};

class Graph {
private:
    int n;
    bool * visited;
    vector<Edge> * edges;
public:
    int * dist;
    Graph (int input_n) {
        n = input_n;
        edges = new vector<Edge>[n];
        dist = new int[n];
        visited = new bool[n];
        memset(visited, false, n * sizeof(bool));
        memset(dist, 0x3f, n * sizeof(int));
    }
    ~Graph() {
        delete[] dist;
        delete[] visited;
        delete[] edges;
    }
    void insert(int x, int y, int weight) {
        Edge tmp = {y, weight};
        edges[x].push_back(tmp);
        
    }
    int prim(int v) {  //钦定一个点v作为最小生成树的顶点
        int total_weight = 0;
        dist[v] = 0;    //这个顶点距离最小生成树的距离为0
        for (int i = 0; i < n; i++) {    //查找距离最小生成树最近的点（第一次时找的的min_vertex为v）
            int min_dist = INF, min_vertex;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && dist[j] < min_dist) { //用visited可以区分最小生成树点集和原树点集
                    min_dist = dist[j];
                    min_vertex = j;
                }
                
            }
            total_weight += min_dist;
            visited[min_vertex] = 1;
            for (int k = 0; k < edges[min_vertex].size(); k++){//for (Edge &j : edges[min_vertex]) { //将这个边连到的新点周围的边的长度加到dist中
                Edge &j = edges[min_vertex][k];
                if (!visited[j.vertex] && j.weight < dist[j.vertex]) {
                    dist[j.vertex] = j.weight;
                }
            }
        }
        return total_weight;
    }
};


int main() {
    int n, m;
    cin >> n;
    Graph g(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            int tmp;
            cin >> tmp;
            g.insert(i,j,tmp);
        }
        
    }
    
    cout << g.prim(0) << endl;
    return 0;
}
