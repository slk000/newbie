//AC
#include <cstdio>
#include <memory.h>
int guess[1005];
int ans[1005];
int cnt[11]; // cnt frequence in ans
int cnt2[11];// cnt in guess
int Case;
int min(int a, int b){return a<b?a:b; }
int main() {
    int length;
    while(scanf("%d", &length) && length) {
        printf("Game %d:\n", ++Case);
        memset(cnt, 0, sizeof(cnt));
        
        for (int i = 0; i < length; i++) {
            scanf("%d", &ans[i]);
            cnt[ans[i]]++;
        }
        //int guess = 0;
        
        while(1) {
            int A = 0, B = 0;
            memset(cnt2,0,sizeof(cnt2));
            for (int i = 0; i < length; i++){
                scanf("%d", &guess[i]);
            }
            if (guess[0] == 0) break;
            for (int i = 0; i < length; i++) {
                cnt2[guess[i]]++;
                if (guess[i] == ans[i]) {
                    A++;
                }
            }
            for (int i = 1; i <= 9; i++) {
                B+=min(cnt[i],cnt2[i]);
            }
            printf("    (%d,%d)\n", A,B-A);
        }
        
        
    }
    return 0;
}
