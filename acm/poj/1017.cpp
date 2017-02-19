//AC
//http://poj.org/problem?id=1017
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=247
//http://acm.zju.edu.cn/onlinejudge/showProblem.do?problemCode=1307
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;
#define INF 0x3f3f3f3f
int a, b, c, d, e, f;// 6种边长
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int res = 0;
	while (cin >> a >> b >> c >> d >> e >> f && (a || b || c || d || e || f)) {
		int validA = 0, validB = 0;
		res = f + e + d; // 每个边长为4、5、6的必须装到一个新箱子里
		validA = 11 * e; // 边长为5的每装一个箱就空出11个边长为1的位子
		validB = 5 * d; // 边长为4的每装一个箱就空出5个边长为2的位子
		res += ceil((double)c / 4.0); // 装边长为3的箱子个数
		int toomanyC = c % 4; // 最后一个用来装边长3的箱子里只装了几个3
		if (toomanyC == 1) { // 只装了1个，则能空出5个2，7个1
			validB += 5;
			validA += 7;
		}
		else if (toomanyC == 2) {
			validB += 3;
			validA += 6;
		}
		else if (toomanyC == 3) {
			validB += 1;
			validA += 5;
		}

		if (b > validB) { // 如果能当前剩的2的位子不够，则看用完之后需不需要补箱子，并更新空出的1
			b -= validB;
			validB = 0;
			res += ceil((double)b / 9.0);
			int toomanyB = b % 9;
			validA += 36 - 4 * toomanyB; //剩余的都给1
			validB = 0;
		}
		else { //如果够装2，就都用掉。
			validB -= b;
		}
		validA += validB * 2 * 2; //最后装1，把所有大小的空位都归入1
		validB = 0;
		a -= validA;
		if (a > 0) {
			res += ceil((double)a / 36.0);
		}
		cout << res << '\n';
	}
	return 0;
}