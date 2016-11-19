//AC
//http://poj.org/problem?id=3617
#include <cstdio>
int main(){

	int length;
	scanf("%d", &length);
	getchar();
	char * str = new char[length+1];
	char * res = new char[length+1];
	str[length] = '\0';
	res[length] = '\0';
	char buf;
	for (int i = 0; i < length; ++i)
	{
		scanf("%c", &str[i]);
		getchar();
	}
	// printf("%s\n", str);
	char *head=str, *tail=str+length-1;
	// printf("%c%c\n", *head,*tail);

	for (int i = 0; i < length; ++i)
	{
		if (*head > *tail) res[i] = *(tail--);
		else if (*head < *tail) res[i] = *(head++);
		else {
			char *tmpHead = head;
			char *tmpTail = tail;
			while(*(--tmpTail) == *(++tmpHead));
			//printf("%c and %c\n", *tmpHead,*tmpTail);
			if(*tmpHead > *tmpTail) res[i] = *(tail--);
			else res[i] = *(head++);
		}


	}

	// printf("%s", res);
	for (int i = 1; i <= length; ++i)
	{
		putchar(res[i-1]);
		if(i%80==0) putchar('\n');
	}
	
	delete[] str;
	delete[] res;
	return 0;
}