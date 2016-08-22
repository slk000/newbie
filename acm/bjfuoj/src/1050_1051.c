#include <stdio.h>
int main(int argc, char const *argv[])
{
	long long a, b;
	while(scanf("%lld%lld",&a, &b) != EOF)
	{	
		long long ora = a,orb = b;
		int fix = 1;
		while(~a&1LL && ~b&1LL){
			a = a >> 1;
			b = b >> 1;
			fix*=2;
		}
		
		while(a != b) (a>b) ? (a-=b) : (b-=a);
	//1050
	//	printf("%lld\n",a*fix );
	//1050

	//1051
		long long res = (ora/(a*fix))*orb;
		printf("%lld\n",res );
	}
	return 0;
}