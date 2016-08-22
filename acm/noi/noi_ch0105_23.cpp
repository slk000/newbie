#include <cstdio>
int main(){
	int T;
	scanf("%d", &T);
	int count = 0;
	for (int i = 0; i < T; ++i)
	{
		int num;
		scanf("%d", &num);
		int a, b, c, d;
		a = num / 1000;
		b = (num % 1000) / 100;
		c = (num % 100) / 10;
		d = (num % 10);
		if (d-a-b-c>0)
		{
			  count++;
		}
	}
	printf("%d\n", count);
	return 0;
}