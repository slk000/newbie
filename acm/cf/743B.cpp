//AC
//http://codeforces.com/problemset/problem/743/B
//与二进制的1有关
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    long long k;
    scanf("%*lld %lld", &k);
    
    printf("%d\n", __builtin_ffsll(k));
    return 0;
}