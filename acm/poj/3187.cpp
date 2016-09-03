//AC
//http://poj.org/problem?id=3187
//force
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 10
const int pasc[MAX][MAX] = {
	{ 1 },
	{ 1,1 },
	{ 1,2,1 },
	{ 1,3,3,1 },
	{ 1,4,6,4,1 },
	{ 1,5,10,10,5,1 },
	{ 1,6,15,20,15,6,1 },
	{ 1,7,21,35,35,21,7,1 },
	{ 1,8,28,56,70,56,28,8,1 },
	{ 1,9,36,84,126,126,84,36,9,1 }
};
int arr[MAX] = { 1,2,3,4,5,6,7,8,9,10 };
int main() {

	int n,aim;
	scanf("%d %d", &n, &aim);

	while (1) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i] * pasc[n - 1][i];
		}
		if (sum == aim) {
			for (int i = 0; i < n; i++)
				printf("%d ", arr[i]);
			printf("\n");
			break;
		}
		next_permutation(arr, arr + n);
	}
	return 0;
}