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
		int n = 1 << R; //ÿ���з��벻������ѡ�� һ��2^R�����
		int res = -1;
		for (int i = 0; i < n; i++) { //����ÿһ�������i��ÿλ����һ�з��벻��
			for (int r = 0; r < R; r++) {  //
				if (1 & (i >> r)) {  //��i��rλΪ1��
					b[r].flip();
				}
			}
			int cntAll = 0;  //��¼��ǰ���ʱ�������ĸ���
			for (int c = 0; c < C; c++) {  //һ������
				int cntCol = 0;
				for (int r = 0; r < R; r++) {
					cntCol += !b[r][c];  //0���������
				}
				if (cntCol < (R >> 1) + 1 ) cntCol = R - cntCol; //�������������������һ�е�����һ���һ����Ӧ�÷���һ�У�����֮��cntCol=R-cntCol
				cntAll += cntCol;
			}
			res = max(res, cntAll);
			for (int r = 0; r < R; r++) {  //�ָ�
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