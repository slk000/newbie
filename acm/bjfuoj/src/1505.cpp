//AC
#include <cstdio>
#include <cstring>
int main (){
	char a[55];
	char b[55];
	while (EOF != scanf("%s\n%s", a,b)) {
		int i;
		for (i = 0; i < strlen(a); i++) {
			if (a[i]-'0' && b[i]-'0') ;
			else if (a[i]-'0' || b[i]-'0') a[i]='0';
			else if (!(a[i]-'0') && !(b[i]-'0')) a[i]='1';
		}
		printf("%s\n", a);
	}
	return 0;
}
