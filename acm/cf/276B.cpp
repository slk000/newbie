//AC
//http://codeforces.com/problemset/problem/276/B
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 100000
int cntAlp[26];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int cntOdd = 0, cntEven = 0;
    char ch;
    while (EOF != scanf("%c", &ch) && ch != '\n' && ch != '\r') {
        cntAlp[ch - 'a']++;
        if (cntAlp[ch - 'a'] & 1) {
            if (cntEven)cntEven--;
            cntOdd++;
        }
        else {
            if (cntOdd)cntOdd--;
            cntEven++;
        }
    }
    if (cntOdd & 1 || cntOdd == 0) {
        puts("First");
    }
    else {
        puts("Second");
    }
    return 0;
}