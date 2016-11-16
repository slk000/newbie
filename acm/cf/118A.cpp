//AC
//http://codeforces.com/problemset/problem/118/A
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

int main() {
    char ch;
    while (EOF != scanf("%c", &ch) && ch != '\r'&&ch != '\n') {
        if (ch >= 'A'&&ch <= 'Z')ch = ch - 'A' + 'a';
        switch (ch)
        {
            case 'a':
            case 'o':
            case 'y':
            case 'e':
            case 'u':
            case 'i':
                break;
            default:
                printf(".%c", ch);
                break;
        }
    }
    printf("\n");
    return 0;
}
