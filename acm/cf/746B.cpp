//AC
//http://codeforces.com/problemset/problem/746/B
#include<cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int n;
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n;
    //getchar();
    string ans="";
    vector<char> v;
    char ch;
    for (int i = 0; i < n; i++) {
        cin >> ch;
        v.push_back(ch);
    }
    int i = 0;
    if (n & 1) {
        ans.push_back(v[0]);
        i++;
    }
    for (; i < n; i+=2) {
        ans.insert(0,1,v[i]);
        ans.push_back(v[i + 1]);
    }
    cout << ans << "\n";
    return 0;
}