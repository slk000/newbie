//AC
//http://codeforces.com/problemset/problem/34/A
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
int Data[1010];
//inline int abs(int &a) { return a < 0 ? -a : a; }
int main() {
	
	//freopen("in.txt", "r", stdin);
   
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &Data[i]);
    }
    
    int Min = INF, mini1 = -1, mini2 = -1;
    for (int i = 0; i < n - 1; i++) {
        int t = abs(Data[i] - Data[i + 1]);
        if (t < Min) {
            Min = t;
            mini1 = i;
            mini2 = i + 1;
        }
    }
    int t = abs(Data[0] - Data[n-1]);
    if (t < Min) {
        Min = t;
        mini1 = n-1;
        mini2 = 0;
    }
    printf("%d %d\n", mini1+1, mini2+1);
    return 0;
}
