//AC
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool cmp(const string &s1, const string &s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();
	return s1 < s2;
}
int main () {
	int T;
	scanf("%d", &T);
	while(T--) {
		int sum;
		scanf("%d", &sum);
		string str[sum];
		for (int i = 0; i < sum; i++) {
			cin >> str[i];
		}
		sort(str, str+sum, cmp);
		for (int i = 0; i < sum; i++) {
			cout << str[i] << endl;
		}
	}
	return 0;
}
