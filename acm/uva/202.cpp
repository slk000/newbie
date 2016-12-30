//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=138
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_A 3000
#define MAX_B 3000
int vis[MAX_B];
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int a, b,A,B;
    vector<int> remnants;
    bool first = true;
    while(EOF!=scanf("%d %d", &a, &b)){
        if(!first){
            printf("\n");
        }
        first = false;
        A=a,B=b;
        memset(vis, -1, sizeof(vis));
        remnants.clear();
        while(a>=b) a%=b; // caution! judge the case a=b, thus >= not >
        for(int i = 0;  ; i++){
            if(vis[a] != -1) break;
            vis[a] = i;
            if(a<b)a*=10;
            int c = a/b;

            //printf("%d\n", c);
            a %= b;

            remnants.push_back(c);

        }
        printf("%d/%d = %d.", A,B,A/B);
        int cnt = 0;
        for (int i = 0; i < 50 && i < remnants.size(); i++){
            if(i == vis[a]){
                printf("(");
                cnt=0;
            }
            printf("%d", remnants[i]);
        }
        if(remnants.size()>50) printf("...");
        printf(")\n");
        printf("   %d = number of digits in repeating cycle\n", remnants.size()-vis[a]);
    }
    printf("\n");
    return 0;
}