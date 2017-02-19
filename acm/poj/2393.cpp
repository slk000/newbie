//AC
//http://poj.org/problem?id=2393
//greedy
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <functional>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 10000
int C[MAX_N + 10];
int Y[MAX_N + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, S;
    while (cin >> N >> S) {
        memset(C, 0, sizeof(C));
        memset(Y, 0, sizeof(Y));
        for (int i = 0; i < N; i++) {
            cin >> C[i] >> Y[i];
        }
        long long res = 0;
        for (int i = 0; i < N; i++) {
            long long sum = 0; //从i到j周共需销售多少
            int j = 0;
            long long fee = 0; //存储需要的总花费
            for (j = 0; C[i]+j*S<=C[i+j]; j++) { // 如果第i+j周的单价(第i周的成本+存j周的费用)比(i+j)周的单价还便宜的话，就在i周全生产出来存起
                sum += Y[j + i];
                fee += S*j*Y[j + i];
            }
            res += sum*C[i];
            res += fee;
            i += j-1;
        }
        cout << res << '\n';
    }
    return 0;
}