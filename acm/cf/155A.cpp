//AC
//http://codeforces.com/problemset/problem/155/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum = 0;
    scanf("%d", &sum);
    int Max, Min;
    int cnt = 0;
    for (int i = 0; i < sum; i++) {
        int a;
        scanf("%d", &a);
        if (i == 0) {
            Max = Min = a;
        }
        else {
            if (Max < a) {
                Max = a;
                cnt++;
            }
            if(Min > a) {
                Min = a;
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
