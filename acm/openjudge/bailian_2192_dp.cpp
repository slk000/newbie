//http://bailian.openjudge.cn/practice/2192/

#include <cstdio>
#include <cstring>
#include <memory.h>
#define LEN 201
char str1[LEN], str2[LEN], str3[LEN*2];
char tmp[LEN];
bool hasSolution1, hasSolution2;
int dp[2][LEN*2][LEN*2]; //dp[k][i][j] str3.substr(0,j) 中 包含strk.(0,i)的长度
int len1, len2, len3;
int max(int a, int b) {return a>b?a:b;}
int min(int a, int b) {return a>b?b:a;}
void solve(){
    for (int i = 0; i < max(len1, len2); i++) {
        for (int j = i; j < len3; j++) {
            if (i < len1) {
                if (str1[i] == str3[j]) {
                    if (i==0||j==0)
                        dp[0][i][j] = 1;
                    else
                        dp[0][i][j] = dp[0][i-1][j-1]+1;
                }
                else
                    dp[0][i][j] = max(dp[0][i-1][j], dp[0][i][j-1]);
            }
            if (i < len2) {
                if (str2[i] == str3[j]) {
                    if (i==0||j==0)
                        dp[1][i][j] = 1;
                    else
                        dp[1][i][j] = dp[1][i-1][j-1]+1;
                }
                else
                   dp[1][i][j] = max(dp[1][i-1][j], dp[1][i][j-1]);
            }
        }
    }

}
int main (){




    int n;
    scanf("%d", &n);
    for (int T = 1; T <= n; T++) {
        hasSolution1 = hasSolution2 = false;
        memset(dp, 0, sizeof(dp));
        scanf("%s %s %s", str1, str2, str3);
        len1 = strlen(str1);
        len2 = strlen(str2);
        len3 = strlen(str3);
        solve();
        hasSolution1 = (dp[0][len1-1][len3-1] == len1);
        hasSolution2 = (dp[1][len2-1][len3-1] == len2);
/*
for (int i = 0; i < max(len1, len2); i++) {
        for (int j = 0; j < len3; j++) {
            if (i < len1) {
                printf("%d ", dp[0][i][j]);
            }
            if (i < len2) {
                if (str2[i] == str3[j]) {
                    if (i==0)
                        dp[1][i][j] = 1;
                    else
                        dp[1][i][j] = max(dp[1][i-1][j], dp[1][i][j])+1;
                }
            }
        }
        printf("\n");
    }*/
        printf("Data set %d: %s\n", T, (hasSolution1&&hasSolution2)?"yes":"no");
    }
    return 0;
}
