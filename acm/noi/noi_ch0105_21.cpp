#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	int max=0;
	int count=0;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (a>=90&&a<=140 && b>=60 &&b<=90)
		{
			count++;

		}
		else{
			max = count>max?count:max;
			count = 0;
		}
	}
	max = count>max?count:max;
	printf("%d\n", max);
	return 0;
}