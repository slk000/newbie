#include <stdio.h>
int main(void)
{
	int amo, sum =0, i, in;

	scanf("%d",&amo);

	for (i = 0; i < amo; i++)
	{
		scanf("%d",&in);
		if (in%2)
		{
			sum += in;
		}
	}
	printf("%d\n", sum);
	return 0;
}