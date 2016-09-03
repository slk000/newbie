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
	int half = n >> 1;//������ʱA��half+1λB��halfλ��ż����ʱ����half��
	if (n & 1) {  //������
		int a = 0, b = 0; // a>=b
		if (!digits[0]) {
			swap(digits[0], digits[1]); //
		}
		int i = 0;
		for (i = 0; i < half + 1; i++) {  //ѡ��һ����0����С������ΪA�����λ��Ȼ��ʣ�µ�half��λ����ɵ����־�����С�����������ţ���
			a += digits[i] * ::pows[half - i]; 
		}
		for (; i < n; i++) {
			b += digits[i] * ::pows[i - half - 1]; //ʣ��half�����������B
		}
		return a - b;
	}
	else {  //ż��
		bool vis[MAX];
		memset(vis, true, sizeof(vis));
		int minDiff = INF, minRes = INF;
		vector<pair<int, int> > ve;
		for (int i = 0; i < n - 1; i++) {  //�ҳ����в�ֵ��С�����ֶ�
			vis[digits[i]] = vis[digits[i + 1]] = false;
			if (digits[i] && digits[i + 1]) {
				if (digits[i + 1] - digits[i] < minDiff) { //�и�С�ģ������ǰ��
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
		for (int i = 0; i < ve.size(); i++) { //����ÿ�����λ���ն����
			memcpy(vis, bak, sizeof(bak));
			vis[ve[i].first] = vis[ve[i].second] = true;
			int tmpA = pows[half - 1] * ve[i].second; //��С��ֵ�����Խϴ����
			int tmpB = pows[half - 1] * ve[i].first;
			int j = 0, jj = 1; //j��digits�ϱ�����jj������㵽��һλ�ϣ�����
			for (j = 0, jj = 1; jj < half; j++) { //�������λ���ߵ���tmpA��ʣ�µ������ں������λ������
				if (!vis[digits[j]]) {
					vis[digits[j]] = true;
					tmpA += pows[half - 1 - jj] * digits[j];
					jj++;  //����
					
				}
			}
			for (jj = half-1; j < n; j++) {
				if (!vis[digits[j]]) {
					vis[digits[j]] = true;
					tmpB += pows[half - 1 - jj] * digits[j];
					jj--;  //����

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