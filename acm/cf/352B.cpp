//AC
//http://codeforces.com/contest/352/problem/B
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define MAX 100000
int a[MAX + 10];
int pos[MAX + 10];
int period[MAX + 10];
bool valid[MAX + 10];
int cnt[MAX + 10];
typedef pair<int, int> pii;
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif // !ONLINE_JUDGE
    memset(pos, -1, sizeof(pos));
    memset(period, -1, sizeof(period));
    memset(valid, 1, sizeof(valid));
    int n, tmpN;
    scanf("%d", &n);
    tmpN = n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (!valid[a[i]]) {
            continue;
        }
        if (pos[a[i]] == -1) {//第一次出现
            pos[a[i]] = i;
            cnt[a[i]]++;
        }
        else if (pos[a[i]] != -1 && period[a[i]] == -1) {//第二次出现，计算周期
            //pos[a[i]] = i;
            period[a[i]] = i - pos[a[i]];
            cnt[a[i]]++;
        }
        else if (pos[a[i]] != -1 && period[a[i]] != -1) {//第3+次，验证
            int last = i - period[a[i]];
            if (last >= 0 && a[last] != a[i]) {
                valid[a[i]] = 0;
            }
        }
    }
    vector<pii> res;
    for (int i = 0; i <= MAX; i++) {
        if (pos[i] != -1 && period[i] >= -1 && valid[i]) {
            //printf("%d %d\n", i, period[i] == -1 ? 0 : period[i]);
            res.push_back(make_pair(i, period[i] == -1 ? 0 : period[i]));
        }
    }
    printf("%d\n", res.size());
    for (int i = 0; i < res.size(); i++) {
        printf("%d %d\n", res[i].first, res[i].second);
    }
    return 0;
}