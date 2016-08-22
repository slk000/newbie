#include <cstdio>
int main (){

	int *data;
	int n, m;
	scanf("%d%d", &n, &m);
	data = new int[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &data[i]);
	}


	int a, b, count;
	for (int i = 0; i < m; ++i)
	{
		count=0;
		scanf("%d%d", &a, &b);
		for (int j = 0; j < n; ++j)
		{
			count+=(data[j]<=b && data[j]>=a);
		}
		printf("%d\n", count);
	}

	
	delete []data;

	return 0;
}