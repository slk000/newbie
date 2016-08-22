#include <stdio.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d",&T);
	while(T--){
		int year = 0;
		scanf("%d",&year);
		char *str[12] = {"hou","ji","gou","zhu","shu","niu","hu","tu","long","she","ma","yang"};
		year = year%12;
		printf("%s\n", str[year]);
	}
	return 0;
}