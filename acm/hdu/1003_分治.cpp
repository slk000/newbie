//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1003
//分治
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#define INF 0x3f3f3f3f
typedef struct Part { int sum, low, high; } Part;
int T;
vector<int> v;
bool operator<(const Part &a, const Part &b) {
	return a.sum < b.sum;
}
Part findMaxCrossing(int low, int mid, int high, vector<int> &arr) { //查找跨越中点的最大子数组
	int maxRight = mid;
	int maxLeft =  mid;
	int maxSumLeft = -INF;
	int tmpMaxSum = 0;
	for (int i = mid; i >= low; i--) { //往左
		tmpMaxSum += arr[i];
		if (maxSumLeft <= tmpMaxSum) {
			maxLeft = i;
			maxSumLeft = tmpMaxSum;
		}
	}
	int maxSumRight = -INF;
	tmpMaxSum = 0;
	for (int i = mid + 1; i <= high; i++) { //往右
		tmpMaxSum += arr[i];
		if (maxSumRight <= tmpMaxSum) {
			maxRight = i;
			maxSumRight = tmpMaxSum;
		}
	}
	Part ret = { maxSumLeft + maxSumRight, maxLeft, maxRight };
	return ret;
}
Part findMaxSubarr(int low, int high, vector<int> &arr) {
	//if (low > high) return Part{0,-1,-1};
	if (low == high) {
		Part ret = { arr[low], low, high };
		return ret;
	}
	int mid = (low + high) >> 1;
	Part left = findMaxSubarr(low, mid, arr);
	Part center = findMaxCrossing(low, mid, high, arr);
	Part right = findMaxSubarr(mid+1, high, arr);
	return max(max(left, center), right);

}
int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> T;

    for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++) {
			int t;
			cin >> t;
			v.push_back(t);
		}

		Part res = findMaxSubarr(0, n - 1, v);
		cout << "Case " << t << ":\n";
		cout << res.sum << ' ' << res.low+1 << ' ' << res.high+1 << '\n';
		if (t != T)cout << '\n';
    }
    return 0;
}