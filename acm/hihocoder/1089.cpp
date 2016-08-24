//AC

#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_NODE 110
int N, M;
int matrix[MAX_NODE][MAX_NODE];
void init(){
    memset(matrix, 0x3f, sizeof(matrix));
    for(int i = 0; i < N; i++) matrix[i][i] = 0;
}
inline void insert(int x, int y, int weight) {
    #define NON_DIRECTED
    matrix[x][y] = weight;
#ifdef NON_DIRECTED
    matrix[y][x] = weight;    //ÎÞÏòÍ¼
#endif
}
int dist[MAX_NODE][MAX_NODE];
void floyd(){
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k]+matrix[k][i]);
            }
        }
    }
}
int main (){
    scanf("%d %d", &N, &M);
    init();
    for (int i = 0; i < M; i++){
        int from, to, dis;
        from--;to--;
        scanf("%d %d %d", &from, &to, &dis);
        if(matrix[from][to] > dis){
            insert(from,to,dis);
        } 
    }
    
    floyd();
    
    for(int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
