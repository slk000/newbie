//AC
//http://codeforces.com/problemset/problem/586/D
//wannafly union 1A
//dfs
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_C 100
char map[3][MAX_C + 10];
int N, k;
int rr[] = { -1,1,0 }; //up down right
bool vis[3][MAX_C + 10];
const int R = 3;
inline bool check(int r, int c) {
    return r >= 0 && r < R && c >= 0 && map[r][c]=='.'&&!vis[r][c];
}
bool res = false;
void dfs(int r, int c) {
    vis[r][c] = 1;
    if (c >= N - 1 - 1 || res) {
        res = true;
        return;
    }
    for (int i = 0; i < 3; i++) {
        
        if (r + rr[i] < 0 || r + rr[i] >= 3)continue;
        int nr = r + rr[i], nc = c;
        bool isOk = (map[r][nc + 1] == '.'); //1.右一步
        isOk &= (map[nr][nc + 1] == '.');   //2.上/下/不动并往右一步
        isOk &= (map[nr][nc + 2] == '.');//2.上/下/不动并往右两步
        isOk &= (map[nr][nc + 3] == '.');//2.上/下/不动并往右三步
        //都得可走
        if (isOk && !vis[nr][nc+3]) {
            dfs(nr, nc + 3);
        }
    }

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d", &T);

    while (T--) {
        res = false;
        memset(vis, 0, sizeof(vis));
        fill((char*)map, (char*)map + 3 * (MAX_C + 10), '.');
        int startR;
        scanf("%d %d", &N, &k);
        for (int i = 0; i < 3; i++) {
            scanf("%s", map[i]);
            map[i][N] = '.'; // fuck \0
            if (map[i][0] == 's') {
                startR = i;
            }
        }
        dfs(startR, 0);
        puts(res?"YES":"NO");
    }
    return 0;
}
