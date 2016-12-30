//AC
//http://codeforces.com/problemset/problem/747/A
#include<cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n;
    scanf("%d", &n);
    int N = ceil(sqrt(n));
    int minDiff = 0x3f3f3f3f;
    int J = 0;
    int I = 0;
    for (int i = 1; i <= N; i++) {
        if (n%i == 0) {
            int j = n / i;
            if ( (abs(j - i)) < minDiff) {
                minDiff = abs(j - i);
                J = j;
                I = i;
            }
        }
    }
    if (I > J)swap(I, J);
    printf("%d %d\n", I, J);

    return 0;
}