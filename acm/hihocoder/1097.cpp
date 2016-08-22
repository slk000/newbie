//AC
//http://hihocoder.com/problemset/problem/1097
//��С������ģ����
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
    int prim(int v) {  //�ն�һ����v��Ϊ��С�������Ķ���
        int total_weight = 0;
        dist[v] = 0;    //������������С�������ľ���Ϊ0
        for (int i = 0; i < n; i++) {    //���Ҿ�����С����������ĵ㣨��һ��ʱ�ҵĵ�min_vertexΪv��
            int min_dist = INF, min_vertex;
            for (int j = 0; j < n; j++) {
                if (!visited[j] && dist[j] < min_dist) { //��visited����������С�������㼯��ԭ���㼯
                    min_dist = dist[j];
                    min_vertex = j;
                }
                
            }
            total_weight += min_dist;
            visited[min_vertex] = 1;
            for (int k = 0; k < edges[min_vertex].size(); k++){//for (Edge &j : edges[min_vertex]) { //��������������µ���Χ�ıߵĳ��ȼӵ�dist��
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
