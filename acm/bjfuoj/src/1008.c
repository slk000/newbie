#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	while(N--){
		int n, i;
		float ave = 0.;
		scanf("%d", &n);
		for (i = 0; i < n; ++i)
		{
			float curNum;
			scanf("%f", &curNum);
			ave += curNum/n;
		}
		printf("%.0f\n",ave);
	}
	return 0;
}