#include <cstdio>
int fa[2000];
// 还记得之前阅读课里讲的并查集算法
// father函数返回的是节点x的祖先节点
int father(int x) {
    if (fa[x] != x) fa[x] = father(fa[x]);
    return fa[x];
}
// 合并两个节点所在集合，同时判断两个点之前是否在一个集合里
// 函数返回true则之前两个点不在一个集合中
bool join(int x, int y) {
    int fx = father(x), fy = father(y);
    if (fx != fy) {
        fa[fx] = fy;
        return true;
    } else {
        return false;
    }
}
// 初始化一个n个点的并查集
void init(int n) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
}

int main (){
    int res = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    init(m);
    for (int i = 0; i < n; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if(!join(a, b)) res++;
    }
    // res = m - res;
    printf("%d\n", res);
    return 0;
}