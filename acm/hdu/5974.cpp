//AC
//http://acm.hdu.edu.cn/showproblem.php?pid=5974
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long LL;
int gcd(int a, int b) { return !b ? a : gcd(b, a%b); }

int main() {
	int a, b;
	while (EOF != scanf("%d %d", &a, &b)) {
		int c = gcd(a, b);
		
		int ac = a / c;
		int bc = b / c;
		int z1_z2 = ac*ac - 4 * bc;
		if (z1_z2 < 0) {
			printf("No Solution\n");
			continue;
		}
	
		int sqrtz1_z2 = sqrt(z1_z2);
		if (sqrtz1_z2*sqrtz1_z2 != z1_z2) {
			printf("No Solution\n");
			continue;
		}
		
		int X = (-sqrtz1_z2*c + a) >> 1; //???
		int Y = a - X;
		printf("%d %d\n", X, Y);
		
	}	
	return 0;
}
