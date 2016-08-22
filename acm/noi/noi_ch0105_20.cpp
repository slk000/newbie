#include <cstdio>
int main(){
	int m, n;
	int count=0;
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; ++i)
	{
		int sum;
		scanf("%d",&sum);

		if (m >= sum)
		{
			count++;
			m = m - sum;
		}
	}

	printf("%d\n", n-count);


	return 0;
}