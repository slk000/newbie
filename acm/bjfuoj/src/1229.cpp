#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int T, i;

	scanf("%d" ,&T);

	for (i = 1; i <= T; ++i)
	{
		stack<char> ori_data, res;
		char str[21];
		scanf("%s", str);
		int j;
		for (j = strlen(str) - 1; j >= 0; --j)
		{
			char tmp = str[j];
			if (tmp >= 'A' && tmp <= 'Z')
			{
				tmp = tmp - 'A' + 'a';
			}
			else if(tmp >= 'a' && tmp <= 'z')
			{

			}
			else continue;

			res.push(tmp);

		}

		bool flag = true;
		while(!res.empty()){
			char tmp = res.top();
			res.pop();
			if(flag){
				cout << "Case #"<<i<<": ";
				tmp = tmp + 'A' - 'a';
				flag = false;
			}
			cout << tmp;
		}
		cout << endl;
	}
	return 0;
}