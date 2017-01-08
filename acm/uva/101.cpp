//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37
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
#define MAX 25
vector<int> arr[MAX + 10];
int n, a, b;
void recover(int p, int h) {
    //for (int i = arr[p].size() - 1; i >= h+1; i--) {
    for (int i = h + 1; i < arr[p].size(); i++) {
        int c = arr[p][i];
        arr[c].push_back(c);
    }
    arr[p].resize(h + 1);
}
void search(int t, int &p, int &h) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            if (arr[i][j] == t) {
                p = i;
                h = j;
                return;
            }
        }
    }
}
void onto(int h, int p, int p2) {
    for (int i = h; i < arr[p].size(); i++) {
        arr[p2].push_back(arr[p][i]);
    }
    arr[p].resize(h);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif // !ONLINE_JUDGE
    //ios::sync_with_stdio(false);
    //std::cin.tie(0);
    
    char str[8];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        arr[i].push_back(i);
    }
    while (EOF != scanf("%s", str) && 0 != strcmp("quit", str)) {

        int pa = -1, pb = -1, ha = -1, hb = -1;
        if ('m' == str[0]) {
            scanf("%d", &a);
            scanf("%s", str);
            scanf("%d", &b);

            search(a, pa, ha);
            search(b, pb, hb);
            if (pa == pb || pa == -1 || pb == -1) continue;
            recover(pa, ha);
            if ('n' == str[1]) { // move onto
                
                recover(pb, hb);
                onto(ha, pa, pb);
            }
            else if ('v' == str[1]) { // move over
                
                onto(ha, pa, pb);
            }
        }
        else if ('p' == str[0]) {
            scanf("%d", &a);
            scanf("%s", str);
            scanf("%d", &b);

            search(a, pa, ha);
            search(b, pb, hb);
            if (pa == pb || pa == -1 || pb == -1) continue;
            if ('n' == str[1]) { // pile onto
                recover(pb, hb);
                onto(ha, pa, pb);
            }
            else if ('v' == str[1]) { // pile over
                onto(ha, pa, pb);
            }
        }
        
    }
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < arr[i].size(); j++) {
            printf(" %d", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}