//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1184
//AC
#include <stdio.h>
int main(){
	int T;
	scanf("%d", &T);
	char data[101];
	char *mo[26] = {".-", "-...", "-.-"/*题目有误实为-.-.*/, "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
	while(T--){
		scanf("%s", data);
		int i;
		for (i = 0; data[i]!='\0'; ++i)
		{
			printf("%s", mo[data[i]-'A']);
		}
		printf("\n");
	}
	return 0;
}