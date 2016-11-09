//AC
//http://codeforces.com/problemset/problem/224/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f

int main() {
    
    //freopen("in.txt", "r", stdin);
   
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    printf("%d\n", 4*(int)(sqrt(a*c / b) + sqrt(b*c / a)+sqrt(a*b / c)));
    return 0;
}
