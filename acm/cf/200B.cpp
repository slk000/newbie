//AC
//http://codeforces.com/problemset/problem/200/B
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum;
    scanf("%d", &sum);
    int num;
    int S = 0;
    for (int  i = 0; i < sum; i++)
    {
        scanf("%d", &num);
        S += num;
    }
    printf("%.12lf\n", (double)S / (double)sum);
    return 0;
}
