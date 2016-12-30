//AC
//http://codeforces.com/problemset/problem/747/B
#include<cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    int N;
    cin >> N;
    int n = N / 4;
    string str;
    cin >> str;
    int cntA = 0, cntG = 0, cntC = 0, cntT = 0;
    stack<int> pos;
    for (int i = 0; i < N; i++) {
        cntA += str[i] == 'A';
        cntG += str[i] == 'G';
        cntC += str[i] == 'C';
        cntT += str[i] == 'T';
        if (str[i] == '?') pos.push(i);
    }
    if (cntA > n || cntG > n || cntC > n || cntT > n) {
        puts("===");
        return 0;
    }
    while (n!= cntA  && !pos.empty()) {
        int p = pos.top();
        pos.pop();
        str[p] = 'A';
        cntA++;
    }
    while (n!=cntG && !pos.empty()) {
        int p = pos.top();
        pos.pop();
        str[p] = 'G';
        cntG++;
    }
    while (n!=cntC && !pos.empty()) {
        int p = pos.top();
        pos.pop();
        str[p] = 'C';
        cntC++;
    }
    while (n!=cntT && !pos.empty()) {
        int p = pos.top();
        pos.pop();
        str[p] = 'T';
        cntT++;
    }
    if (!pos.empty()) {
        puts("===");
    }
    else {
        cout << str << "\n";
    }
    return 0;
}