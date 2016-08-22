#include <cstdio>
#include <cstring>
int main (){
	int Ca = 0;
	scanf("%d", &Ca);
	for (int i = 0; i < Ca; ++i)
	{
		char str1[110];
		char str2[110];
		scanf("%s %s",str1,str2);
		int res = 0;
		for (int j = 0; j < strlen(str1); ++j)
		{
			res += str1[j]-'0';
		}
		for (int j = 0; j < strlen(str2); ++j)
		{
			res += str2[j]-'0';
		}
		printf("Case %d: %d\n", i+1,res);
	}
	return 0;
}