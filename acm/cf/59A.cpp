//AC
//http://codeforces.com/problemset/problem/59/A
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[110];
char upper[110];
char lower[110];
int main() {
    scanf("%s", str);
    int cntUpper = 0, cntLower = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) { // deal with upper and lower in one turn.
        if (str[i] >= 'a' && str[i] <= 'z') {
            upper[i] = str[i] - 'a' + 'A';
            lower[i] = str[i];
            cntLower++;
        }
        else {
            lower[i] = str[i] - 'A' + 'a';
            upper[i] = str[i];
            cntUpper++;
        }
    }
    if (cntUpper > cntLower) {
        printf("%s\n", upper);
    }
    else {
        printf("%s\n", lower);
    }
    return 0;
}
