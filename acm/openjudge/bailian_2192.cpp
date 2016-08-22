//http://bailian.openjudge.cn/practice/2192/
//DFS
#include <cstdio>
#include <cstring>
#define LEN 201
char str1[LEN], str2[LEN], str3[LEN * 2];
bool hasSolution;
void solve(int str1RIndex, int str2RIndex, int str3RIndex) {
    if (hasSolution) return;
    if (str3RIndex == -1) {
		hasSolution = true;
		return;
	}
    if ( str1[str1RIndex] != str3[str3RIndex] && str2[str2RIndex]!=str3[str3RIndex]) return;
	if (str1[str1RIndex] == str3[str3RIndex]) solve(str1RIndex-1, str2RIndex, str3RIndex-1);
	if (str2[str2RIndex] == str3[str3RIndex]) solve(str1RIndex, str2RIndex-1, str3RIndex-1);
	return;
}
int main() {
	int n;
	scanf("%d", &n);
	for (int T = 1; T <= n; T++) {
		hasSolution=false;
		scanf("%s %s %s", str1, str2, str3);
		solve(strlen(str1)-1, strlen(str2)-1, strlen(str3)-1);
		printf("Data set %d: %s\n", T, hasSolution? "yes" : "no");
	}
	return 0;
}
