#include <stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	char num[] = "1740948824551711527614232000";
	while(scanf("%d",&N) != EOF)
	{
		int i, mod = 0;

		num[25] = N/100 + '0';
		num[26] = N/10%10 + '0';
		num[27] = N%10 +'0';

		for (i = 0; num[i] != '\0'; ++i)
		{
			mod  =  10  *  mod  +  num[i]  -  '0';
			mod  %=  N; 
		}
		printf("1740948824551711527614232%03d\n", N - mod);
	}
	return 0;
}