#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long num;
	while(EOF!=scanf("%lld", &num)){
		printf("%d\n", (num-1)%9+1);
	}
	return 0;
}