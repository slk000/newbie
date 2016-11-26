//AC
//http://codeforces.com/problemset/problem/431/B
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int arr[5] = {1-1,2-1,3-1,4-1,5-1};
int mat[5][5];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    int cnt = 120;//全排列
    int Max = -INF;
    while (cnt--) {
        
        /*for (int i = 0; i < 5; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");*/
        int t = mat[arr[0]][arr[1]] + mat[arr[1]][arr[0]] + mat[arr[2]][arr[3]] + mat[arr[3]][arr[2]];
        t += mat[arr[1]][arr[2]] + mat[arr[2]][arr[1]] + mat[arr[4]][arr[3]] + mat[arr[3]][arr[4]];
        t += mat[arr[2]][arr[3]] + mat[arr[3]][arr[2]];
        t += mat[arr[3]][arr[4]] + mat[arr[4]][arr[3]];
        Max = max(Max, t);
        next_permutation(arr, arr + 5);
    }
    printf("%d\n", Max);
    return 0;
}