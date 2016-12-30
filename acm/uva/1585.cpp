//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4460
#include <cstdio>
#include <cstring>

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    getchar();
    while(T--){
        char ch;
        int cntO = 1;
        int ans = 0;
        while(scanf("%c", &ch) && ch != '\n'){
            if(ch == 'O'){
                ans += cntO++;
            }
            else if(ch == 'X'){
                cntO = 1;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}