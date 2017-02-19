//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1008
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 49
int a, b, n;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> n && n)  {
        int now = 0;
        int res = 0;

        for (int i = 0; i < n; i++) {
            int t;
            cin >> t;
            if (t > now)
                res += (t - now) * 6;
            else
                res += (now - t) * 4;
            now = t;
        }
        res += n * 5;
        cout << res << '\n';
    }
    return 0;
}