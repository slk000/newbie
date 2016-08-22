//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1089
//AC
#include <stdio.h>
int main() {
	int T;
	scanf("%d", &T);
	int res[T];
	int r, e, c, i;
	for (i = 0; i < T; ++i)
	{
		scanf("%d%d%d", &r, &e, &c);
		res[i] = e - c - r;
	}
	for (i = 0; i < T; ++i)
	{
		if(res[i] > 0)
			printf("advertise\n");
		else if(res[i] < 0)
			printf("do not advertise\n");
		else
			printf("does not matter\n");
	}
	return 0;
}