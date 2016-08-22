//AC
//DFS
//http://bailian.openjudge.cn/2016acmmid/d/
//http://bailian.openjudge.cn/practice/4123/
#include <cstdio>
#include <memory.h>
#define MAX_R 11
#define MAX_C 11

int rr[] = {-1,-2,-2,-1,1,2,2,1};
int cc[] = {-2,-1,1,2,2,1,-1,-2};
int R, C;
bool vis[MAX_R][MAX_C];
int res;
int stepCnt = 1;
int d(int r, int c){
    //if (r < 0 || r >= R || c < 0 || c >= C || vis[r][c]) return 0;
    //printf("(%d, %d)\n", r,c);
    //stepCnt++;
    //printf("%d\n", stepCnt);
    vis[r][c] = true;
    if (stepCnt == R*C) {
            res++;
    }
    else {
        for (int i = 0; i < 8; i++) {
            int nr = r+rr[i], nc = c+cc[i];

            if (nr >= 0 && nr < R && nc >= 0 && nc < C && !vis[nr][nc]){
                vis[nr][nc] = true;
                stepCnt++;
                d(nr, nc);
                stepCnt--;
                vis[nr][nc] = false;
            }

        }
    }


    return 0;
}
int main (){
    int T;
    scanf("%d", &T);
    while(T--){
        res = 0;
        stepCnt = 1;
        int startR, startC;
        scanf("%d %d %d %d", &R, &C, &startR, &startC);
        memset(vis, false, sizeof(vis));
        d(startR, startC);
        vis[startR][startC]=true;
        printf("%d\n", res);
    }
    return 0;
}
