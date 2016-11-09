//AC
//http://codeforces.com/problemset/problem/450/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
    int childs, candy;
    scanf("%d %d", &childs, &candy);
    int Max = -INF, maxi = -1;
    for (int i = 1; i <= childs; i++) {
        int c;
        scanf("%d", &c);
        c = ceil((double)c / (double)candy); //calc how many times of assignment to this child
        if (c >= Max) {
            Max = c;
            maxi = i;
        }
    }
    printf("%d\n", maxi);
    return 0;
}
