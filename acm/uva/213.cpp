//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=149
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
char arr[8][1<<8];
char getChar() {
    char ret = 0;
    while (ret = getchar()) {
        if (ret != '\n' && ret != '\r') return ret;
    }
}
int getInt(int len) {
    int ret = 0;
    while (len--)ret = 2 * ret + getChar() - '0';
    return ret;
}
bool readCodes() {
    memset(arr, 0, sizeof(arr));
    char t;
    for (int i = 1; i <= 7; i++) {
        for (int j = 0; j < (1 << i) - 1; j++) {
            t = getchar();
            if (t == EOF) return 0;
            if (t == '\n') return 1;
            arr[i][j] = t;
        }
    }
    return 1;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //std::cin.tie(0);
    while (readCodes()) {
             
        while (1) {
            int len = getInt(3);
            if (len == 0) break;
            int num;
            while ((num = getInt(len)) != (1 << len) - 1) {
                putchar(arr[len][num]);
            }
        }
        putchar('\n');
        getchar();
    }
    return 0;
}