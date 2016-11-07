//AC
//http://codeforces.com/problemset/problem/266/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[55];
int main() {
    int n; 
    scanf("%d", &n);
    scanf("%s", str);
    char *end = unique(str, str + n);
    printf("%d\n", n-(end-str));
    return 0;
}
