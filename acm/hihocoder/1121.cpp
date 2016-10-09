//AC
//http://hihocoder.com/problemset/problem/1121
//floodfill
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
#define MAX_V 10010
#define INF 0x3f3f3f3f

typedef struct Edge {
	int from, to;
	Edge() { }
	Edge(int f, int t) : from(f), to(t){ }
} Edge;

vector<Edge>* G;
int color[MAX_V];
int N,M;
void insert(int from, int to){
	G[from].push_back(Edge(from, to));
	G[to].push_back(Edge(to, from));
}

bool floodfill(int start){
	for (int i = 0; i < N; i++){
		if (color[i] == 0){
			color[i] = 1;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int cur = q.front();q.pop();
				for (int j = 0; j < G[cur].size(); j++){
					Edge &e = G[cur][j];
					if (color[e.to] == 0){
						color[e.to] = (color[cur]==1?2:1);
						q.push(e.to);
					}
					else if(color[e.to] == color[cur]){
						return false;
					}
				}
			}
		}
	}
	return true;
}
int main() {
	int T;
	scanf("%d", &T);
	while(T--){
		G = new vector<Edge>[MAX_V];
		memset(color, 0, sizeof(color));
		scanf("%d %d", &N, &M);
		for (int i = 0; i < M; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			insert(u, v);
		}
		printf("%s\n",floodfill(1)?"Correct":"Wrong");
	}
	
	return 0;
}