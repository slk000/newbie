//AC
#include <iostream>
#include <string>
#include <memory.h>
#include <algorithm>

using namespace std;
class Solution {
public:
	string longestPalindrome(string tmp) {
		if (tmp.length() == 1) return tmp;//leetcode说一个字符也算
		string str = "";
		
		for (string::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			str.push_back(*it);
			str.push_back('#');
		}
		int *p = new int[str.length()];
		memset(p, 0, sizeof(int)*str.length());
		int maxCenter = 0;
		int maxP = -0x3f3f3f;
		int maxI = 0;
		for (int i = 1; i < str.length() - 1; i++)
		{
			p[i] = min(p[2 * maxCenter - i], maxCenter + p[maxCenter] - i);
			if (p[i] < 0)p[i] = 0;
			for (int j = i + p[i] + 1; j < str.length() && (2 * i) - j >= 0 && str[2 * i - j] == str[j]; p[i]++, j++)
			{
				if (j > maxCenter + p[maxCenter]) maxCenter = i;
			}

			if (p[i] > maxP) {//记录回文最长的中点
				maxI = i;
				maxP = p[i];
			}
		}
		string resWithSharp = str.substr(maxI - p[maxI], 2 * p[maxI] + 1);
		string res;
		for (int i = 0; i < resWithSharp.length(); i++)
		{
			if (resWithSharp[i] != '#') res.push_back(resWithSharp[i]);
		}
		//if (res.length() == 1) res = "";
		delete[] p;
		return res;
	}
};

int main(){
	Solution s;
	string str;
	cin >> str;

	cout << s.longestPalindrome(str) << endl;
	return 0;
}