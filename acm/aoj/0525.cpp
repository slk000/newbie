//AC
//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0525
//force 
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <set>
#include <string>
#include <stack>
#include <bitset>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX_R 11
#define MAX_C 10010
bitset<MAX_C> b[MAX_R];
int main() {
	//freopen("e:/0525-input.txt", "r", stdin);
	int R = 0, C = 0;
	while (EOF!=scanf("%d %d", &R, &C) && R && C) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				int a;
				scanf("%d", &a);
				b[i][j] = (bool)a;
			}
		}
		int n = 1 << R; //每行有翻与不翻两种选择， 一共2^R种情况
		int res = -1;
		for (int i = 0; i < n; i++) { //遍历每一种情况，i的每位代表一行翻与不翻
			for (int r = 0; r < R; r++) {  //
				if (1 & (i >> r)) {  //若i的r位为1则翻
					b[r].flip();
				}
			}
			int cntAll = 0;  //记录当前情况时可以卖的个数
			for (int c = 0; c < C; c++) {  //一列列数
				int cntCol = 0;
				for (int r = 0; r < R; r++) {
					cntCol += !b[r][c];  //0代表可以卖
				}
				if (cntCol < (R >> 1) + 1 ) cntCol = R - cntCol; //如果可卖的数量不及这一列的总数一半加一，则应该翻这一列，翻完之后cntCol=R-cntCol
				cntAll += cntCol;
			}
			res = max(res, cntAll);
			for (int r = 0; r < R; r++) {  //恢复
				if (1 & (i >> r)) {
					b[r].flip();
				}
			}
		}
		printf("%d\n", res);
		/*
		for (int i = 0; i < R; i++) {
			cout << b[i].to_string().substr(MAX_C - C, C) << endl;
		}*/
	}
	return 0;
}