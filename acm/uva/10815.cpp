//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1756
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
#include <set>
#include <sstream>
using namespace std;
#define INF 0x3f3f3f3f
set<string> s;
char func(char &a) {
    if (a >= 'A' && a <= 'Z') return a - 'A' + 'a';
    if (a >= 'a' && a <= 'z') return a;
    return ' ';
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    ios::sync_with_stdio(false);
    std::cin.tie(0);
    string str = "";
    char ch;
    
    while (cin >> str) {
        for (int i = 0; i < str.length(); i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] - 'A' + 'a';
            }
            else if (str[i] >= 'a' && str[i] <= 'z') {
            }
            else {
                str[i] = ' ';
            }
            
        }
        stringstream ss(str);
        while (ss >> str) {
            s.insert(str);
        }
    }
    
    for (set<string>::iterator it = s.begin(); it != s.end(); it++) {
        cout << *it << '\n';
    }
    return 0;
}