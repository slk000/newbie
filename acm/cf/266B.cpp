//AC
//http://codeforces.com/problemset/problem/266/B
//swap G and B n times;
#include <cstdio>
#include <algorithm>
using namespace std;
char queue[60];
int main() {
    int sum, time;
    scanf("%d %d", &sum, &time);
    scanf("%s", queue);
    
    while (time--) {
        for (int cnt = 0, i = 0; i < sum - 1; i++) {
            if (queue[i] == 'B'&&queue[i + 1] == 'G') {
                swap(queue[i], queue[i + 1]);
                i++;
            }
        }
    }
    printf("%s\n", queue);
    return 0;
}