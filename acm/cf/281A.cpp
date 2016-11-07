//AC
//http://codeforces.com/problemset/problem/281/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[10010];

int main() {
    scanf("%s", str);
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }
    printf("%s\n", str);
    return 0;
}
