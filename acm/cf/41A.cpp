//AC
//http://codeforces.com/problemset/problem/41/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
char str1[110];
char str2[110];
int main() {
    scanf("%s", str1);
    scanf("%s", str2);
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if (n1 != n2) {
        printf("NO\n");
        return 0;
    }
    for (int i = 0; i < n1; i++) {
        if (str1[i] != str2[n2 - i - 1]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
