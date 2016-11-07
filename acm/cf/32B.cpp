//AC
//http://codeforces.com/problemset/problem/32/B
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[210];
int len;
int get(int i) {
    if (i + 1 < len){
        if (str[i] == '-'&&str[i + 1] == '-')return 2;
        if (str[i] == '-'&&str[i + 1] == '.')return 1;
    }
    
    if (str[i] == '.')return 0;
    return -1;
}
int main() {
    scanf("%s", str);
    len = strlen(str);
    
    int a;
    for (int i = 0; i < len; ) {
        a = get(i);
        if (a != -1) {
            printf("%d", a);
            i += (a) ? 2 : 1;
        }
    }
    printf("\n");
    return 0;
}