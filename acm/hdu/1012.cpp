//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1012
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
int f(int n) {
	if (n == 0) return 1;
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res *= i;
	}
	return res;
}
double e(int n) {
	double res = 0;
	for (int i = 0; i <= n; i++) {
		res += 1.0 / f(i);
	}
	return res;
}
int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	/*
	printf("n e\n- -----------\n");
	for (int n = 0; n <= 9; n++) {
		printf(n<=2?"%d %g\n":"%d %.9lf\n", n, e(n));
	}*/
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");
	printf("3 2.666666667\n");
	printf("4 2.708333333\n");
	printf("5 2.716666667\n");
	printf("6 2.718055556\n");
	printf("7 2.718253968\n");
	printf("8 2.718278770\n");
	printf("9 2.718281526\n");

	return 0;
}