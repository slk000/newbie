//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1007
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemId=1107
//分治
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
typedef struct P { double x, y; } P;
vector<P> v;
vector<P> tvl;
vector<P> tvr;
bool sortByY(P &a, P &b) {
	return a.y < b.y;
}
bool sortByX(P &a, P &b) {
	return a.x < b.x;
}
inline double dis(P &a, P &b) {
	return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}
double findMinCrossing(int low, int mid, int high, double d, vector<P> &arr) { 
	tvl.clear();
	tvr.clear();
	double ret = INF;
	/*
	for (int i = mid; i >= low; i--) {
		if (arr[mid].x - arr[i].x <= d) {
			tv.push_back(arr[i]);
		}
		else {
			break;
		}
	}
	for (int i = mid + 1; i <= high; i++) {
		if (arr[i].x - arr[mid].x <= d) {
			tv.push_back(arr[i]);
		}
		else {
			break;
		}
	}*/
	
	for (int i = mid; i >= low; i--) {
		if (fabs(arr[i].x - arr[mid].x) <= d) {
			tvl.push_back(arr[i]);
		}
		else {
			break;
		}
	}
	for (int i = mid+1; i <= high; i++) {
		if (fabs(arr[i].x - arr[mid].x) <= d) {
			tvr.push_back(arr[i]);
		}
		else {
			break;
		}
	}
	sort(tvl.begin(), tvl.end(), sortByY);
	
	for (int i = 0; i < tvl.size(); i++) {
		for (int j = 0, cnt = 0; j < tvr.size() && cnt <8; j++,cnt++) { //
			if (fabs(tvl[i].y - tvr[j].y) <= d) {
				double t = dis(tvl[i], tvr[j]);
				ret = min(ret, t);
			}
		}
	}
	
	return ret;
}
double findMinDis(int low, int high, vector<P> &arr) {
	if (low == high) {
		return INF;
	}
	if (low + 1 == high) {
		return dis(arr[low], arr[high]);
	}
	if (low + 2 == high) {
		double ret = min(min(dis(arr[low], arr[low + 1]), dis(arr[low], arr[low + 2])), dis(arr[low + 1], arr[low + 2]));
		return ret;
	}

	int mid = (low + high) >> 1;
	double left = findMinDis(low, mid, arr);
	double right = findMinDis(mid, high, arr);
	double d = min(left, right);
	double center = findMinCrossing(low, mid, high, d, arr);
	return min(d, center);

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n && n) {
		v.clear();
		for (int i = 0; i < n; i++) {
			P t;
			cin >> t.x >> t.y;
			v.push_back(t);
		}
		sort(v.begin(), v.end(), sortByX);
		double res = findMinDis(0, n - 1, v);
		cout << setiosflags(ios::fixed) << setprecision(2) << sqrt(res) / 2. << '\n';
	}
	return 0;
}