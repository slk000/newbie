//AC
#include <cstdio>
#include <algorithm>
using namespace std;
int main (){
	int T;
	scanf("%d", &T);
	while (T--) {
		int sum;
		scanf("%d", &sum);;
		int numbers[sum];
		for (int i = 0; i < sum; i++) {
			scanf("%d", &numbers[i]);
		}
		sort(numbers, numbers+sum);
		printf("%d\n", (sum&1)?numbers[sum/2]:numbers[sum/2 - 1]);
	}
	return 0;
}
