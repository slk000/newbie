//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=3666
#include <cstdio>
#include <cstring>
int cnt[10];
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    int n;
    while(T--){
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            int t = i;
            while(t){
                cnt[t%10]++;
                t /= 10;
            }
        }
        for (int i = 0; i <= 9; i++){
            printf(i==9?"%d":"%d ", cnt[i]);
        }
        printf("\n");


    }
    return 0;
}