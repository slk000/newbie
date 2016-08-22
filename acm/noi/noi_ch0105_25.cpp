#include <cstdio>
#include <cstring>
int main(){

	char num[10];
	scanf("%s", num);
	int length = strlen(num);

	for (int i = length-1; i >= 0; --i)
	{
		printf("%c ", num[i]);
	}
	printf("\n");
}