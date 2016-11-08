//AC
//http://codeforces.com/problemset/problem/339/A
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define INF 0x3f3f3f3f
int main() {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;
    char ch;
    while (EOF != scanf("%c", &ch) && ch != '\r' && ch != '\n') {
        switch (ch)
        {
        case '1':
            cnt1++;
            break;
        case '2':
            cnt2++;
                break;
        case '3':
            cnt3++;
            break;
        default:
            break;
        }
    }
    
    
    string ans = "";
    for (int i = 0; i < cnt1; i++) {
        ans.push_back('1');
        ans.push_back('+');
    }
    for (int i = 0; i < cnt2; i++) {
        ans.push_back('2');
        ans.push_back('+');
    }
    for (int i = 0; i < cnt3; i++) {
        ans.push_back('3');
        ans.push_back('+');
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}
