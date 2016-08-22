#include <stdio.h>
int main(int argc, char const *argv[])
{	
	int T;
	scanf("%d",&T);
	while(T--){
		char *d="22233344455566677778889999";
		char c[41];
		scanf("%s",c);
		int i;
		for (i = 0; c[i] != '\0'; ++i)
		{
			c[i] = d[c[i]-97];
		}
		printf("%s\n", c);
	}
	return 0;
}