//AC
//http://codeforces.com/problemset/problem/272/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
    int friends;
    scanf("%d", &friends);
    int fingers = 0;
    int ans = 0;
    for (int i = 0; i < friends; i++) {
        int a;
        scanf("%d", &a);
        fingers += a;
    }
    friends++; //himself
    for (int i = 5; i >= 1; i--) {
        if ((fingers + i) % friends != 1) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
