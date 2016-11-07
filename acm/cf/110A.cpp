//AC
//http://codeforces.com/problemset/problem/110/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
    char ch;
    int cnt = 0;
    int cnt4 = 0;
    while (EOF != scanf("%c", &ch) && ch != '\n' && ch != '\r') {
        if (ch == '7'|| ch == '4') cnt++;
    }
    if ((cnt == 7) ||( cnt == 4) ) {
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }
    return 0;
}
