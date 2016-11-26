//AC
//http://codeforces.com/problemset/problem/260/A
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 100000
int arr[MAX + 10];
int main(){
    int a, b, n;
    scanf("%d %d %d", &a, &b, &n);
    if(a%b==0){
        printf("%d", a);
        for (int i = 0; i < n; i++){
            printf("0");
        }
        printf("\n");
        return 0;
    }
    else{
        for(int i = 0; i <= 9; i++){
            if((a*10+i)%b==0){
                printf("%d", a*10+i);
                for (int i = 0; i < n-1; i++){
                    printf("0");
                }
                printf("\n");
                return 0;
            }
        }
    }
    printf("-1");
    return 0;
}