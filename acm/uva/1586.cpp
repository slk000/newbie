//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=4461
#include <cstdio>
#include <cstring>
char str[100];
bool isNum(char ch){
    return ch>='0'&&ch<='9';
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif // ONLINE_JUDGE
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        int n = strlen(str);
        double ans = 0;
        for (int i = 0;i < n; i++){
            int t = 1;
            if(i+2<n&&isNum(str[i+1])&&isNum(str[i+2])){
                t = (str[i+1]-'0')*10+str[i+2]-'0';
            }
            else if(i+1<n&&isNum(str[i+1])){
                t = str[i+1]-'0';
            }
            switch(str[i]){
                case 'C':
                    ans += 12.01*t;
                    break;
                case 'H':
                    ans += 1.008*t;
                    break;
                case 'O':
                    ans += 16.00*t;
                    break;
                case 'N':
                    ans += 14.01*t;
                    break;
            }
        }
        printf("%.3lf\n", ans);
    }
    return 0;
}