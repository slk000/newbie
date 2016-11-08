//AC
//http://codeforces.com/problemset/problem/228/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int data[4];
    for (int i = 0; i < 4; i++)
        scanf("%d", &data[i]);
    sort(data, data + 4);
    printf("%d\n", 4 - (unique(data, data + 4) - data));
    return 0;
}
