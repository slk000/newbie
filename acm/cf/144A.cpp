//AC
//http://codeforces.com/problemset/problem/144/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum;
    scanf("%d", &sum);
    int num;
    int maxi, mini;
    int Max = -INF, Min = INF;
    for (int i = 0; i < sum; i++) {
        scanf("%d", &num);
        if (num <= Min) { //选择最靠右的最小值
            Min = num;
            mini = i;
        }
        if (num > Max) { //选择最靠左的最大值
            Max = num;
            maxi = i;
        }
    }
    
    if (mini == maxi) {
        printf("0\n");
    }
    else {
        int res = (maxi - 0) + ((sum - 1) - mini);
        if (mini < maxi) { //如果移动时会相遇，要少算一次
            res--;
        }
        printf("%d\n", res);
    }
    return 0;
}
