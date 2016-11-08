//AC
//http://codeforces.com/problemset/problem/133/A
// = =
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    char ch;
    //bool flag = false;
    while (EOF != scanf("%c", &ch) && ch != '\r' && ch != '\n') {
        if (ch == 'H' || ch == 'Q' || ch == '9') {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
