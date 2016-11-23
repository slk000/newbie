//AC
//http://codeforces.com/problemset/problem/738/B
//Codeforces Round #380 Div. 2 B
//先一行行看，第i行如果有1，res+=此行0的个数；如果有0夹在两个1之间，res再+=这种0的个数。依次再一列列看
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <functional>
#include <queue>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1000
int map[MAX + 10][MAX + 10];
int cnt1inN[MAX + 10], cnt1inM[MAX + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                cnt1inN[i]++;
                cnt1inM[j]++;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        int start1 = -1; int end1 = -1;
        if (cnt1inN[i] >= 2) {
            int cnt0 = 0;
            for (int j = 0; j < m; j++) {
                if (start1 == -1 && map[i][j] == 1) {
                    start1 = j;
                }
                else if (start1 != -1 && map[i][j]==1) {
                    end1 = j;
                }
            }
            for (int j = start1; j < end1; j++) {
                if (map[i][j] == 0) {
                    cnt0++;
                }
            }
            res += cnt0;
            res += (m - cnt1inN[i]);
        }
        else if(cnt1inN[i]==1){
            res += (m - cnt1inN[i]);
        }
    }
    for (int i = 0; i < m; i++) {
        int start1 = -1; int end1 = -1;
        if (cnt1inM[i] >= 2) {
            int cnt0 = 0;
            for (int j = 0; j < n; j++) {
                if (start1 == -1 && map[j][i] == 1) {
                    start1 =j;
                }
                else if (start1 != -1 && map[j][i] == 1) {
                    end1 = j;
                }
            }
            for (int j = start1; j < end1; j++) {
                if (map[j][i] == 0) {
                    cnt0++;
                }
            }
            res += cnt0;
            res += (n - cnt1inM[i]);
        }
        else if (cnt1inM[i] == 1) {
            res += (n - cnt1inM[i]);
        }
    }
    cout << res << endl;
    return 0;
}