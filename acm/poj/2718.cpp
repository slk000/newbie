//AC
//http://poj.org/problem?id=2718
//greedy&force
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 11

int digits[MAX];
const int pows[] = { 1,10,100,1000,10000,100000,1000000,10000000 };
int solve(int n) {
	if (n == 2) {
		return digits[1] - digits[0];
	}
	int half = n >> 1;//奇数个时A有half+1位B有half位；偶数个时都有half个
	if (n & 1) {  //奇数个
		int a = 0, b = 0; // a>=b
		if (!digits[0]) {
			swap(digits[0], digits[1]); //
		}
		int i = 0;
		for (i = 0; i < half + 1; i++) {  //选择一个非0的最小数字作为A的最高位，然后剩下的half个位置组成的数字尽可能小（即按升序排）；
			a += digits[i] * ::pows[half - i]; 
		}
		for (; i < n; i++) {
			b += digits[i] * ::pows[i - half - 1]; //剩下half个降序排组成B
		}
		return a - b;
	}
	else {  //偶数
		bool vis[MAX];
		memset(vis, true, sizeof(vis));
		int minDiff = INF, minRes = INF;
		vector<pair<int, int> > ve;
		for (int i = 0; i < n - 1; i++) {  //找出所有差值最小的数字对
			vis[digits[i]] = vis[digits[i + 1]] = false;
			if (digits[i] && digits[i + 1]) {
				if (digits[i + 1] - digits[i] < minDiff) { //有更小的，清空以前的
					minDiff = digits[i + 1] - digits[i];
					ve.clear();
				}
				if (digits[i + 1] - digits[i] == minDiff) {
					ve.push_back(make_pair(digits[i], digits[i + 1]));
				}
			}
		}
		bool bak[11];
		memcpy(bak, vis, sizeof(vis));
		for (int i = 0; i < ve.size(); i++) { //对于每种最高位的钦定情况
			memcpy(vis, bak, sizeof(bak));
			vis[ve[i].first] = vis[ve[i].second] = true;
			int tmpA = pows[half - 1] * ve[i].second; //最小差值的数对较大的数
			int tmpB = pows[half - 1] * ve[i].first;
			int j = 0, jj = 1; //j在digits上遍历，jj代表计算到哪一位上（从左）
			for (j = 0, jj = 1; jj < half; j++) { //对于最高位更高的数tmpA，剩下的数字在后面的数位上升序
				if (!vis[digits[j]]) {
					vis[digits[j]] = true;
					tmpA += pows[half - 1 - jj] * digits[j];
					jj++;  //升序
					
				}
			}
			for (jj = half-1; j < n; j++) {
				if (!vis[digits[j]]) {
					vis[digits[j]] = true;
					tmpB += pows[half - 1 - jj] * digits[j];
					jj--;  //降序

				}
			}
			if (minRes > tmpA - tmpB)minRes = tmpA - tmpB;
		}
		return minRes;
	}
 	
}
int main() {
	int T;
	scanf("%d%*c", &T);
	while(T--){
		char ch;
		int i = 0;
		for (i = 0; scanf("%c", &ch) && ch != '\n';) {
			if(ch!=' ')
				digits[i++] = ch - '0';
		}
		sort(digits, digits + i);
		printf("%d\n", solve(i));
	}
	return 0;
}