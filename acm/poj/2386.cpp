//AC
//DFS
//http://poj.org/problem?id=2386
#include <cstdio>
#include <iostream>

using namespace std;

char map[1000][1000];
int N, M;
int countW;

bool dfs(int y, int x){
    int dx[] = {/*-1,  0,  1, -1,*/1, -1, 0, 1};
    int dy[] = {/*-1, -1, -1, 0, */0,  1, 1, 1};
    map[y][x]='.';
    for (int i = 0; i < 8; i++) {
        int newPx = x+dx[i], newPy = y+dy[i];
        if (newPx < M && newPx >= 0 && newPy < N && newPy >= 0 && map[newPy][newPx]=='W'){
            
            dfs(newPy, newPx);
        }

    }
    
    return true;
}
int main(){

    scanf("%d%d", &N, &M);
    //getchar();
    for (int i = 0; i < N; i++) {
        // for (int j = 0; j < M; j++) {
            scanf("%s", map[i]);
        // }
        // getchar();
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(map[i][j] == 'W'){
                dfs(i, j);
                // map[i][j] = '.';
                countW++;
            }
            //if(!sign) count++;
            
        }
    }
    
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         printf("%c", map[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n", countW);
    return 0;
}