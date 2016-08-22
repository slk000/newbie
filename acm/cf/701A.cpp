#include <cstdio>
int num[100];
int main (){

    int n, sum=0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        sum+=num[i];
    }
    int avg = sum / (n/2);
    //printf("%d\n",avg);
    bool skip=false;
    for (int i = 0; i < n; i++) {
        skip=false;
        for (int j = i+1; j < n; j++) {
            if (num[i]+num[j] == avg) {
                printf("%d %d\n", i+1,j+1);
                skip=true;
                break;
            }
        }
        //if(skip) continue;
    }
    return 0;
}
