//AC
//http://poj.org/problem?id=1328
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_N 1000
typedef pair<double, double> PII;

PII islands[MAX_N + 10];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,d;
	int Case = 1;
	
	while ((cin >> n >> d) && n) {
		bool flag = true;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			double t = sqrt(d*d - y*y);
			if (y > d || d < 0) {
				flag = false;
			}
			islands[i].first = x - t;
			islands[i].second = x + t;
		}
		if (!flag) {
			cout << "Case " << Case++ << ": -1\n";
			continue;
		}
		sort(islands, islands + n);
		int ans = 0;
		double r = -INF;//right
		for (int i = 0; i < n; i++) {
			if (islands[i].first > r) {
				ans++;
				r = islands[i].second;
			}
			else if (islands[i].second < r)r = islands[i].second;
		}
		cout <<"Case " << Case++ <<": "<< ans << '\n';
	}
	return 0;
}