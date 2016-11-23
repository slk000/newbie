//AC
//http://codeforces.com/problemset/problem/416/A
////wannafly union 1F
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
char op[3];
int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    int r = INF, l = -INF;
    bool containR = false, containL = false;
    char ans;
    int o;
    for (int i = 0; i < n; i++) {
        scanf("%s %d %c", op, &o, &ans);
        if (ans == 'N') {
            
            op[1] = op[1]?0:'=';
            op[0] = (op[0] == '>') ? '<' : '>';
        }
        if (strcmp(op, ">") == 0) {
            if (o > l) {
                l = o; containL = false;
            }
            else if (o == l) {
                containL = false;
            }
        }
        else if (strcmp(op, "<") == 0) {
            if (o < r) {
                r = o; containR = false;
            }
            else if (o == r) {
                containR = false;
            }
        }
        else if (strcmp(op, ">=") == 0) {
            if (o > l) {
                l = o; containL = true;
            }
            else if (o == l) {
                containL = true;
            }
        }
        else if (strcmp(op, "<=") == 0) {
            if (o < r) {
                r = o; containR = true;
            }
            else if (o == r) {
                containR = true;
            }
        }
        
    }
    if (l > r) {
        printf("Impossible\n");
    }
    else if (l == r) {
        if (!containL || !containR) {
            printf("Impossible\n");
        }
        else {
            printf("%d\n", r);
        }
    }
    else if (l < r) {
        if (containL) {
            printf("%d\n", l);
        }
        else if (containR) {
            printf("%d\n", r);
        }
        else if (l + 1<r) {
            printf("%d\n", l + 1);
        }
        else {
            printf("Impossible\n");
        }
    }
    return 0;
}
