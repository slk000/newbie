//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=829&page=show_problem&problem=4459
#include <cstdio>
#include <cstring>
char str[110];
int comp(char *str, int a, int b, int n){
    int res=0;
    for (int i=0;i<n;i++){
        if(str[(a+i)%n]==str[(b+i)%n]){

        }
        else if(str[(a+i)%n]>str[(b+i)%n]){
            return 1;
        }
        else if(str[(a+i)%n]<str[(b+i)%n]){
            return -1;
        }
    }
    return 0;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%s", str);
        int n = strlen(str);
        //int Min = 0x3f3f3f3f;
        int MinI = 0;
        for (int i = 0; i < n; i++){
            if(comp(str, i, MinI,n) == -1){
                MinI = i;
            }
        }
        for (int i = 0; i<n;i++){
            printf("%c", str[(i+MinI)%n]);
        }
        printf("\n");
    }
    return 0;
}