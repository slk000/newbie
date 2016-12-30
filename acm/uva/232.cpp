//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=168
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f

char Map[10+2][10+2];
char num[10+2][10+2];
inline bool chk(int i, int j){
    return (Map[i-1][j]=='*'||Map[i][j-1]=='*')&&Map[i][j]!='*';
}
int main(){
    //std::ios::sync_with_stdio(false);
    //std::cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // ONLINE_JUDGE
    //int T;
    //cin >> T;
    memset(Map, '*', sizeof(Map));
    int R, C;

    int T = 0;
    while(EOF!=scanf("%d", &R) && R){
        if(T)printf("\n");
        int cnt = 0;
        memset(num, 0, sizeof(num));
        scanf("%d", &C);
        getchar();
        for (int i = 1; i <= R; i++){
            for (int j = 1; j <= C; j++){
                char t;
                scanf("%c", &t);
                if (t == '\n') scanf("%c", &t);
                Map[i][j] = t;
                if (chk(i,j)){
                    num[i][j] = ++cnt;
                }

            }

        }
        printf("puzzle #%d:\n", ++T);
        printf("Across\n");
        bool first = true;
        bool hasAny = false;
        for(int i = 1; i <= R; i++){
            bool start = true;
            for(int j = 1; j <= C; j++){
                if(Map[i][j]!='*'){

                    if(start){
                        if(first){
                            printf(" %2d.", num[i][j]);
                            first = false;
                        }
                        else{
                            printf("\n %2d.", num[i][j]);
                        }
                        start = false;
                    }
                    printf("%c", Map[i][j]);
                    hasAny = true;
                }
                else{
                    start = true;
                }
            }
        }
        if(hasAny)
            printf("\n");
        printf("Down\n");
        string down[101];
        //for(int i = 0; i < 101; i++)down[i].clear();

        int index = 0;
        for(int i = 1; i <= C; i++){

            bool start = true;
            for(int j = 1; j <= R; j++){
                if(Map[j][i]!='*'){

                    if(start){
                        if(first){
                            //printf("%d.", num[j][i]);
                            //down[num[j][i]]+=num[j][i]+'.';
                            first = false;
                        }
                        else{
                            //printf("\n%d.", num[j][i]);
                            //down[num[j][i]]+=num[j][i]+'.';
                        }
                        index = num[j][i];
                        start = false;

                    }
                    //printf("%c", Map[j][i]);
                    down[index].push_back(Map[j][i]);
                }
                else{
                    start = true;
                }
            }
        }
        for (int i = 0; i < 101; i++){
            if(down[i][0]){
                cout << ' ';
                cout << setw(2) <<i;
                cout<<'.' <<down[i] << '\n';
            }
            //printf("%s\n", down[i].c_str());
        }

    }


    return 0;
}