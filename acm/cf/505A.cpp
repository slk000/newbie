//AC
//http://codeforces.com/problemset/problem/505/A
////wannafly union 1B
//ac就是坠吼的
//假设删掉第i个字符，如果剩下的是回文就在i对面添个str[i]
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
#define MAX 200000
bool isPa(string &str) {
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    //freopen("in.txt", "r", stdin);
    string str,tmp, tmp2;
    cin >> str;
    int len = str.length(); 
    if (isPa(str)) {
        if (len % 2 == 0) {
            cout << str.substr(0, str.length() / 2) << "y" << str.substr(str.length() / 2);
            return 0;
        }
        else if (len % 2 != 0) {
            cout << str.substr(0, str.length() / 2) << str[str.length() / 2] << str.substr(str.length() / 2);
            return 0;
        }
    }
    for (int i = 0; i < len; i++) {
        tmp = str;
        tmp.erase(tmp.begin() + i);

        bool a = isPa(tmp);
        
        if (a) {
            string res = str;
            res.insert(len - i +((i>len/2)?-1:0) , 1, str[i]);
            cout << res << endl;
            return 0;
        }
    }
    cout << "NA" << endl;
    return 0;
}
