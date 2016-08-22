//AC
#include <cstdio>
#include <cstdlib> //abs(int)
using namespace std;
int main () {
	int n, x;
	while (EOF != scanf("%d %d", &n, &x)) {
		int startAt[n];
		int res[n];
		for (int i = 0; i < n; i++) { 
			scanf("%d", &startAt[i]);
			res[i] = abs(startAt[i] - x) * 5;
		}
		for (int i = 0; i < n; i++) {
			int stopSum;
			scanf("%d", &stopSum);
			for (int j = 0; j < stopSum; j++) {
				int fl;
				scanf("%d", &fl);
				if ((startAt[i] > x && fl < startAt[i] && fl > x) || 
						startAt[i] <= x && fl < x && fl > startAt[i]) {
						res[i] += 15;
				}
			}
		}
		for (int i = 0; i < n; i++)
			printf(i==n-1?"%d\n":"%d ", res[i]);
	}
	return 0;
}
