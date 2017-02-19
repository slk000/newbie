//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1005
//类似朴素的斐波那契求法，又有7*7的循环结
#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 49
int a, b, n;
int fib[MAX+10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> a >> b >> n && a && b && n)  {
        n--;
        fib[0] = fib[1] = 1;
        for (int i = 2; i < 49; i++) {
            fib[i] = ((a * fib[i - 1])%7 + (b * fib[i - 2])%7)%7;
        }
        cout << fib[n%49] << '\n';
       
    }
    return 0;
}