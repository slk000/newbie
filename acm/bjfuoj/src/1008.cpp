//AC
#include <cstdio>
int main () {
	int T;
	scanf("%d", &T);
	while (T--) {
		int sum;
		double ave = 0;
		scanf("%d", &sum);
		for (int i = 0; i < sum; i++) {
			double num;
			scanf("%lf", &num);
			ave += num / (double)sum;
		}
		printf("%d\n", (int)ave);
	}
}
