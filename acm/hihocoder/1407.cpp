//AC
//http://hihocoder.com/problemset/problem/1407
//suffix array
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define MAX_N 100010
#define INF 0x3f3f3f3f
int Rank[MAX_N];
int sa[MAX_N];
int N, K, k;
bool cmp_sa(int a, int b) {
	if (Rank[a] != Rank[b]) return Rank[a] < Rank[b];
	a += k; b += k;
	a = a > N ? -1 : Rank[a];
	b = b > N ? -1 : Rank[b];
	return a < b;
}
void get_sa(vector<int> &str) {
	for (int i = 0; i <= N; i++) {
		Rank[i] = str[i];
		sa[i] = i;
	}
	Rank[N] = -1;

	int tmp_rank[MAX_N];
	for (k = 1; k <= N; k *= 2) {
		tmp_rank[sa[0]] = 0;
		sort(sa, sa + N + 1, cmp_sa);
		for (int i = 1; i <= N; i++) {
			tmp_rank[sa[i]] = tmp_rank[sa[i - 1]] + (int)cmp_sa(sa[i - 1], sa[i]);
		}
		for (int i = 0; i <= N; i++) {
			Rank[i] = tmp_rank[i];
		}

	}
}
int height[MAX_N];
/*
void getHeight(string &str) {
height[0] = height[1] = 0;
for (int i = 2; i <= N; i++) {
if(str[sa[i]] == str[sa[i-1]]){
int j = height[i - 1] - 1;
if (j < 0)j = 0;
for (; j <= N&&str[sa[i] + j] == str[sa[i - 1] + j]; j++);
height[i] = j;
}
else {
height[i] = 0;
}
}
}
*/

/* refer http://hihocoder.com/contest/hiho120/solution/943855 */
void getHeight(vector<int> &r)
{
	int i, j, k = 0;
	for (i = 1; i <= N; i++)  Rank[sa[i]] = i;
	for (i = 0; i<N; i++)
	{
		if (k)
			k--;
		else
			k = 0;
		j = sa[Rank[i] - 1];
		while (r[i + k] == r[j + k])
			k++;
		height[Rank[i]] = k;
	}
}
/* refer end */
bool chk(int k) {
	int maxi = -1, mini = -1;
	for (int i = 2; i <= N; i++) {
		if (height[i] >= k && mini == -1) { //分组开始
			mini = i - 1;
		}
		else if (height[i] < k && mini != -1) { //分组结束
			maxi = i - 1;
			if (abs(sa[mini] - sa[maxi]) >= k) {
				return true;
			}
			maxi = mini = -1;
		}
	}
	return false;
}

int main() {
	//freopen("in.txt", "r", stdin);
	cin >> N;
	vector<int> str(N+1);
	
	for (int i = 0; i < N; i++) {
		cin >> str[i];
	}
	
	get_sa(str);
	getHeight(str);

	int l = 1, r = N, ans=0;
	while (l <= r) //二分假定答案
	{
		int mid = (l + r) / 2;
		if (chk(mid))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	printf("%d\n", ans);

	return 0;
}