#include <iostream>
#include <stack>

using namespace std;
int main(int argc, char const *argv[])
{
	char data[8][4] = {
		{'A','B','C'},
		{'D','E','F'},
		{'G','H','I'},
		{'J','K','L'},
		{'M','N','O'},
		{'P','Q','R','S'},
		{'T','U','V'},
		{'W','X','Y','Z'}
	};

	string str;
	stack<char> res;
	int T;
	cin >> T;
	while(T--)
	{	cin >> str;
		int i;
		for (i = 0; i < str.length()-1; i += 2)
		{
			res.push(data[str[i]-48-2][str[i+1]-48-1]);
			//cout << str[i]-48-2<<str[i+1]-48-1<<" ";
		}
		while(!res.empty()){
			cout << res.top();
			res.pop();
		}
		cout << endl;
	}
	return 0;
}