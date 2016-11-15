//AC
//http://codeforces.com/problemset/problem/208/A
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

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    string str;
    cin >> str;
    int it;
    while ((it = str.find("WUB")) != -1) {
        if (it == 0) {
            str = str.substr(3, str.length());
        }
        else if (it == str.length() - 3) {
            str = str.substr(0, str.length()-3);
        }
        else if (it-1>=0&&str[it - 1] != ' ') {
            str.replace(it, 3, " ");
        }
        else if (it - 1 >= 0 && str[it - 1] == ' ') {
            str.erase(it, 3);
        }
    }

    cout << str << endl;
    return 0;
}
