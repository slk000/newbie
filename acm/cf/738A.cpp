//AC
//http://codeforces.com/problemset/problem/738/A
//Codeforces Round #380 Div. 2 A
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
#define MAX_C 100
typedef pair<int, int> pii;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n;
    string str;
    cin >> n;
    cin >> str;
    int it;
    vector<pii> its;
    for (int i = 0; i < n; i++) {
        it = str.find("ogo", i);
        i = it;
        if (it != -1) {
            int last = its.size() - 1;
            if (last == -1) {
                its.push_back(make_pair(it, 3));
            }
            else if (it-its[last].first >= its[last].second)//扩展上一个点的长度（重叠部分都只换成三个*）
                its.push_back(make_pair(it,3));
            else {
                its[last].second += 2/*it - its[last].first*/;
                //i += /*it - its[last].first-1*/1;
                i = it + 1;
            }
        }
        else {
            break;
        }
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
        if (c < its.size()) {
            if (i == its[c].first) {
                cout << "***";
                i += its[c].second-1;
                c++;
                continue;
            }
            else {

            }
        }
        cout << str[i];

    }
    //cout << str << '\n';
    return 0;
}