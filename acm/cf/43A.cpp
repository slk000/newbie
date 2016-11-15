//AC
//http://codeforces.com/problemset/problem/43/A
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
char str1[15], str2[15];
char tmp[15];
int main() {
    int n;
    int cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            scanf("%s", str1);
            cnt1++;
        }
        else {
            scanf("%s", tmp);
            if (0 == strcmp(tmp, str1)) {
                cnt1++;
            }
            else if (!str2[0] && 0 != strcmp(tmp, str1)) {
                strcpy(str2, tmp);
                cnt2++;
            }
            else {
                cnt2++;
            }
        }
    }
    printf("%s\n", cnt1 > cnt2 ? str1 : str2);
    return 0;
}
