#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	long long n;
	while(EOF != scanf("%lld",&n))
	{
		n %= 26;
		char str[101];

		scanf("%s",str);
		int i;
		for (i = 0; i < strlen(str); ++i)
		{
			str[i]=str[i]+n;
			if(str[i]>90)
				str[i]=str[i]-26;
		}

		printf("%s\n", str);
	}
	return 0;
}