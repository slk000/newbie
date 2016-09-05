#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <functional>
#include <set>
#include <string>
#include <stack>
using namespace std;
#define INF 0x3f3f3f3f
#define MAX 1000
int lengths[MAX];
bool vis[MAX];
int sum;
int assumeLen;
bool d(int requireSum, int requireLength) {
	if (requireSum == 0 && requireLength == 0)
		return true;
	if (requireLength == 0) requireLength = assumeLen;
	for (int i = 0; i < sum; i++) {
		if (!vis[i] && lengths[i] <= requireLength) {
			vis[i] = true;
			if (d(requireSum - 1, requireLength - lengths[i])) {
				return true;
			}
			vis[i] = false;
		}
	}
	return false;
}
int main() {
	
	while (scanf("%d", &sum) && sum) {
		
		int maxLength = 0;
		int sumLength = 0;
		for (int i = 0; i < sum; i++) {
			scanf("%d", &lengths[i]);
			if (lengths[i] > maxLength) maxLength = lengths[i];
			sumLength += lengths[i];
		}
		sort(lengths, lengths + sum, greater<int>());

		for (assumeLen = maxLength; assumeLen < (sumLength >> 1 )+ 1; assumeLen++) {
			memset(vis, false, sizeof(vis));
			if (sumLength % assumeLen == 0) {
				
				if (d(sum, assumeLen)) {
					printf("%d\n", assumeLen);
					break;
				}
			}
		}

	}
	return 0;
}