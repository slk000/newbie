//AC
//http://poj.org/problem?id=3190
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <functional>
#include <set>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 1000000
//typedef pair<int, int> PII;
class PII {
public:
    int first, second;
    int no, room;
    bool operator<(const PII &b) const { 
        return second > b.second;
    }
};
bool cmp(PII &a, PII &b) {
    return a.first < b.first;
}
vector<PII> v;
int arr[MAX_N + 10];
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    while (cin >> N) {
        memset(arr, 0, sizeof(arr));
        v.clear();
        for (int i = 0; i < N; i++) {
            PII t;
            cin >> t.first >> t.second;
            t.room = t.no = i;
            v.push_back(t);
        }
        sort(v.begin(), v.end(), cmp);
        priority_queue<PII, vector<PII>, less<PII> > q;
        int cnt = 1;
        for (int i = 0; i < N; i++) {
            //    while (!v.empty()) {
            PII &t = v[i];
            PII early = { 0,0,0,cnt };
            if (!q.empty()) {
                early = q.top();
            }

            if (t.first > early.second) { // combine
                if (!q.empty())q.pop();
                t.room = early.room;
                //t.second = early.second;
                arr[t.no] = early.room;
            }
            else {
                cnt++;
                arr[t.no] = cnt;
                t.room = cnt;
            }

            q.push(t);
            //cout << cnt << '\n';
        }
        cout << cnt << '\n';
        for (int i = 0; i < N; i++) {
            cout << arr[i] << '\n';
        }
        cout <<'\n';
    }
    return 0;
}