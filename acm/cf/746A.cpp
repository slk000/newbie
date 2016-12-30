//AC
//http://codeforces.com/problemset/problem/746/A
#include<cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int Min = 0x3f3f3f3f;
    Min = min(Min, a / 1);
    Min = min(Min, b / 2);
    Min = min(Min, c / 4);

    printf("%d\n", Min + Min * 2 + Min * 4);
    return 0;
}