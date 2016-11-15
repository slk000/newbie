//AC
//http://codeforces.com/problemset/problem/219/A
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
int alpCnt[26];
int alp[26];
int main() {
    int k;
    scanf("%d", &k);
    getchar();
    char ch;
    while (EOF != scanf("%c", &ch) && ch && ch != '\n' && ch != '\r') {
        alpCnt[ch - 'a']++;
    }
    int kind = 0;
    for (int i = 0; i < 26; i++) {
        if (alpCnt[i] % k != 0) {
            printf("-1\n");
            return 0;
        }
        if (alpCnt[i]) {
            alp[kind] = i;
            kind++;
        }
    }
    for (int a = 0; a<k;a++)
    for (int i = 0; i < kind; i++) {
        for (int j = 0; j < alpCnt[alp[i]]/k; j++) {
            printf("%c", 'a' + alp[i]);
        }
    }
    printf("\n");
    return 0;
}
