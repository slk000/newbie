//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4114
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 1000
#define MAX_M 50
int cnt[MAX_N+10][26];
char str[MAX_M+10][MAX_N+10];
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while(T--){
        int m, n;
        memset(cnt, 0, sizeof(cnt));
        scanf("%d %d", &m, &n);
        getchar();


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                char ch;
                scanf("%c", &ch);
                str[i][j] = ch;
                cnt[j][ch-'A']++;
            }
            getchar();
        }
        int dis = 0;
        for (int i = 0; i < n; i++){

            int MaxI = -1;
            int Max = -INF;
            for(int j = 0; j < 26; j++){
                if (cnt[i][j] > Max){
                    Max = cnt[i][j];
                    MaxI = j;
                }
            }

            printf("%c", MaxI+'A');
            for(int j = 0; j < m; j++){
                dis += (MaxI+'A' != str[j][i]);
            }
        }
        printf("\n%d\n", dis);
    }

    return 0;
}