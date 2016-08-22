//AC
//Manacher 算法
#include <cstdio>
#include <string>
#include <iostream>
#include <memory.h>
#include <algorithm>
using namespace std;
int solve(string &str) {
	string strWithSharp = "#";
	for (string::iterator it = str.begin(); it != str.end(); it++)
	{
		strWithSharp.push_back(*it);
		strWithSharp.push_back('#');
	}

	int *p = new int[strWithSharp.length()];
	memset(p, 0, sizeof(int)*strWithSharp.length());
	int maxCenter = 0;
	int maxRightBorder = maxCenter + p[maxCenter];
	int maxP = -0x3f3f3f;
	for (int i = 1; i < strWithSharp.length() - 1; i++)
	{
		if (i < maxRightBorder)
		{
			p[i] = min(p[2 * maxCenter - i], maxRightBorder - i);
			for (int j = i + p[i] + 1; j < strWithSharp.length() && (2 * i) - j >= 0; j++)
			{
				if (strWithSharp[2 * i - j] == strWithSharp[j])
				{
					p[i]++;
					if (j > maxRightBorder)
					{
						maxCenter = i;
					}
				}
				else
				{
					break;
				}
			}
		}
		else
		{
			for (int j = i + 1; j < strWithSharp.length() && (2 * i - j >= 0); j++)
			{
				if (strWithSharp[2 * i - j] == strWithSharp[j])
				{
					p[i]++;
					if (j > p[maxCenter] + maxCenter)
					{
						maxCenter = i;
					}
				}
				else
				{
					break;
				}

			}
		}
		maxRightBorder = maxCenter + p[maxCenter];
		if (p[i] > maxP) maxP = p[i];
	}
	delete[] p;
	return maxP;
}
int main() {
	string str = "bbbb";

	int T;
	scanf("%d", &T);
	while (T--) {
		cin >> str;
		int res = solve(str);
		if (res == 1) res = 0;
		printf("%d\n", res);
	}

	//system("pause");
	return 0;
}