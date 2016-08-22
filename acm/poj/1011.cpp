#include <cstdio>

int main(){
    int sum;
    while(scanf("%d", &sum) && sum){
        int lengths[sum];
        int maxPiece = 0;
        int sumLength = 0;
        for (int i = 0; i < sum; i++){
            scanf("%d", &lengths[i]);
            if(lengths[i] > maxPiece) maxPiece = lengths[i];
            sumLength += lengths[i];
        }
        
        printf("max:%d sum:%d\n", maxPiece, sumLength);
        for (int i = maxPiece;; i++){
            if (sumLength % i == 0) {
                printf("%d\n", i);
                break;
            }
        }
        
    }
    return 1;
}