//AC
//http://codeforces.com/problemset/problem/459/B
#include <cstdio>
#include <algorithm>
#define INF 0x7f7f7f7f7f7f7f7f
int main(){
    long long n;
    scanf("%lld", &n);
    long long Max = -INF, Min = INF, cntMax = 0, cntMin = 0;
    for (int i = 0; i < n; i++) {
        long long t;
        scanf("%lld", &t);
        if (t == Min) {
            cntMin++;
        }
        else if (t < Min) {
            Min = t;
            cntMin = 1;
        }
        if (t == Max) {
            cntMax++;
        }
        else if (t > Max) {
            Max = t;
            cntMax = 1;
        }
    }
    
    if (Max == Min)
        printf("0 %lld\n", cntMax*(cntMax-1LL)/2LL);
    else
        printf("%lld %lld\n", Max-Min, cntMax*cntMin);
    return 0;
}