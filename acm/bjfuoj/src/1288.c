#include <stdio.h>
#include <string.h>
int main(int argc, char const *argv[])
{
	int T;
	scanf("%d", &T);
	while(T--){
		char num1[1001], num2[1001];
		int count1 = 0,count2 = 0, i, ans = 1;
		scanf("%s%s", num1, num2);
		for (i = 0; i < strlen(num1); ++i)
		{
			if(*(num1+i) == '1'){
				count1++;
			}
			else{
				break;
			}
		}
		if(count1 == strlen(num1)) count1 /= 2;
		for (i = 0; i < strlen(num2); ++i)
		{
			if(*(num2+i) == '1'){
				count2++;
			}
			else{
				break;
			}
		}
		if(count2 == strlen(num2)) count2 /= 2;

		ans = 10*(count2  - count1);

		ans += *(num2 + count2)-'0' - (*(num1+count1)-'0')+1;
		printf("%d\n", ans);
	}
	return 0;
}