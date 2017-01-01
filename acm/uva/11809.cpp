//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=830&page=show_problem&problem=2909
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_M 9
#define MAX_E 30
double sheet[MAX_M + 1][MAX_E+5];
double M[MAX_M+5], E[MAX_E+5];
int main() {
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //std::cin.tie(0);
    for (int i = 0; i <= MAX_M; i++) {
        M[i] = 1.0 - pow(0.5, i+1);
        for (int j = 1; j <= MAX_E; j++) {
            E[j] = pow(2, j ) - 1;
            sheet[i][j] = log10(M[i]) + E[j] * log10(2);
        }
    }
    double f;
    double e;
    char buf[101];
    while (EOF != scanf("%s", buf)) {
        char *p = buf + strlen(buf)-1;
        while (*p != 'e')p--;
        *p = 's';
        sscanf(buf, "%lfs%lf", &f, &e);

        double t = log10(f) + e;
        for (int i = 0; i <= MAX_M; i++)
            for (int j = 1; j <= MAX_E; j++) {
                if (fabs(sheet[i][j] - t) < 1e-4) {
                    printf("%d %d\n", i, j);
                    goto end;
                }
            }
    end:;
    }

    return 0;
}