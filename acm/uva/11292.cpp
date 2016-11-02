//AC
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2267
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 20000
int n, m; //heads, knights
int heads[MAX+10], knights[MAX+10];
int main() {
	//freopen("in.txt", "r", stdin);
	while (~scanf("%d %d", &n, &m) && n && m) { 
		for (int i = 0; i < n; i++) scanf("%d", &heads[i]);
		for (int i = 0; i < m; i++) scanf("%d", &knights[i]);
		sort(heads, heads + n);
		sort(knights, knights + m);
		int ans = 0;
		int i, j;
		for (i = 0, j = 0; i < n && j < m; ) { //i for heads, j for knights
			if (heads[i] <= knights[j]) { // if a knight can completely win the head
				i++;
				ans += knights[j];
				j++;
			}
			else {
				j++;
			}
		}
		if (i == n) {
			printf("%d\n", ans);
		}
		else {
			printf("Loowater is doomed!\n");
		}
	}
	return 0;
}