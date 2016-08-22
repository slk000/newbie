//AC
//http://bailian.openjudge.cn/practice/2677/
//http://bailian.openjudge.cn/2016acmmid/a/
#include <cstdio>
#define MAX_N 100
int map[MAX_N][MAX_N];
int n;
bool isEdge(int r, int c) {
    return (r == 0 || map[r-1][c]>50) || //肿瘤的边界点的个数称为肿瘤的周长!!!!不是边的条数！！！！！！
    (r == n-1 || map[r+1][c]>50) ||
    (c == 0 || map[r][c-1]>50) ||
    (c == n-1 || map[r][c+1]>50);
}
int main (){
    int S, C;
    S = C = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &map[i][j]);
            if (map[i][j]<=50) S++;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j]<=50){
                C+=isEdge(i, j);
            }
        }
    }
    printf("%d %d\n", S, C);
    return 0;
}
