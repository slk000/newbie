//AC
//http://codeforces.com/problemset/problem/61/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[110];

int main() {
    
    scanf("%s", str);
    getchar();
    char ch;
    int cnt = 0;
    while (EOF != scanf("%c", &ch) && ch != '\n' && ch != '\r') {
        if (str[cnt] != ch) {
            printf("1");
        }
        else {
            printf("0");
        }
        cnt++;
    }
    printf("\n");
    return 0;
}
