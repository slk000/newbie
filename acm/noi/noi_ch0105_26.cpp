#include <cstdio>
#include <cstring>
int main(){

	char num[12];
	scanf("%s", num);
	int length = strlen(num);
	
	bool isBack = true;
	bool isPos = (num[0] == '-');
	
	if (isPos) printf("-");
	for (int i = length-1; i > 0; --i)
	{
		if (num[i] != '0')
		{
			isBack = false;
		}
		if(isBack && num[i]=='0')
			continue;
	
			printf("%c", num[i]);
	}
	
	if (!isPos) printf("%c", num[0]);
	printf("\n");
	return 0;
}