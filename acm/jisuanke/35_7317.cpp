#include <cstdio>
#include <memory.h>
#include <vector>
#include <queue>
#define INF 0x3f3f3f
using namespace std;
int main (){
    int N, M, C;
    scanf("%d %d %d", &N, &M, &C);
    bool visited[N];
    // printf("%d\n", sizeof(visited));
    memset(visited, false, sizeof(visited));
    vector<int> G[N];
    queue<int> bfs;

    for (int i = 0; i < M; ++i)
    {
    	int from, to;
    	scanf("%d %d", &from, &to);
    	G[from].push_back(to);
    	G[to].push_back(from);
    }
    bfs.push(C);
    visited[C] = true;
    while(!bfs.empty()){
    	int front = bfs.front();
    	// printf("%d ", front);
    	
    	bfs.pop();
    	for (int i = 0; i < G[front].size(); ++i)
    	{

    		int next = G[front][i];
    		// printf("n:%d\n", next);
    		if (!visited[next])
    		{
    			visited[next] = true;
    			bfs.push(next);
    		}
    	}

    }


    return 0;
}
