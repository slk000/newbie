//AC
//http://hihocoder.com/problemset/problem/1082
#include <iostream>
#include <string>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{
	string str;
	string mode = "marshtomp";

	while(getline(cin, str)){
		int strLength = str.length();
		int isInStr = 0;
		for (int i = 0; i < strLength; ++i)
		{
			if (tolower(str[i]) == mode[isInStr])
			{
				isInStr++;
			}
			else isInStr = 0;
			
			if (isInStr == 9)
			{
				str = str.replace(i-8, 9, "fjxmlhx");
				i-=2;
				//printf("%d\n%d", isInStr,i);
				isInStr = 0;
			}
			//cout << i << " " << isInStr << ",";
		}
		cout << str << endl;
	}
	return 0;
}