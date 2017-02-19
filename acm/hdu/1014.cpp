//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1014
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
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int s,m;
	
	while (scanf("%d %d", &s, &m)!=EOF) {
		if (1 == gcd(s, m)) {
			printf("%10d%10d    Good Choice\n\n", s, m);
		}
		else {
			printf("%10d%10d    Bad Choice\n\n", s, m);
		}
	}

	return 0;
}