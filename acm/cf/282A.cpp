//AC
//http://codeforces.com/problemset/problem/282/A
// = =
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int sum;
    char str[4];
    scanf("%d", &sum);
    int x = 0;
    for (int i = 0; i < sum; i++) {
        scanf("%s", str);
        if (str[1] == '+') x++;
        else if (str[1] == '-') x--;
    }
    printf("%d\n", x);
    return 0;
}
