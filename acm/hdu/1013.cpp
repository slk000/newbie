//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1013
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
int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	char ch;
	int res = 0;
	while (EOF != scanf("%c", &ch)) {
		if (ch == '\n') {
			//cout << res << '\n';
			if (res == 0) return 0;
			res %= 9;
			if (res == 0) {
				res = 9;
			}
			printf("%d\n", res);
			res = 0;
			continue;
		}
		res += ch - '0';

	}
	return 0;
}