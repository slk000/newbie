//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1040
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f3f3f3f3f
int arr[1000 + 10];
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n; 
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		for (int i = 0; i < n; i++) {
			cout << arr[i];
			if (i != n - 1)cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}