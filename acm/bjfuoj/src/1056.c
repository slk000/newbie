#include <stdio.h>
long long qp(long long a, long long b, long long p){
    long long ans = 1;
    a = a % p;
    while(b > 0){
         
        if (b % 2 == 1)
            ans = (ans * a) % p;
        b = b/2;
        a = (a*a) % p;
         
    }
    return ans;
}
int main(int argc, char const *argv[])
{
	printf("%lld\n", qp(2222,62,9223372036854775807LL));
	return 0;
}