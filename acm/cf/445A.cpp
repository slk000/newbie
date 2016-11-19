//AC
//http://codeforces.com/problemset/problem/445/A
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
#define MAX 110
char map[MAX][MAX];
bool vis[MAX][MAX];
const int rr[] = { -1,1,0,0 };
const int cc[] = { 0,0,-1,1 };
int R, C;
void dfs(int r, int c, bool cur) {
    vis[r][c] = 1;
    if (map[r][c] == '.') {
        map[r][c] = cur ? 'B' : 'W';
    }
    for (int i = 0; i < 4; i++) {
        int nr = rr[i] + r;
        int nc = cc[i] + c;
        if (nr >= 0 && nr < R&&nc >= 0 && nc < C && !vis[nr][nc]) {
            dfs(nr, nc, !cur);
        }
    }
}
int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", map[i]);
    }
    dfs(0, 0, 1);
    for (int i = 0; i < R; i++) {
        printf("%s\n", map[i]); 
    }
    return 0;
}
