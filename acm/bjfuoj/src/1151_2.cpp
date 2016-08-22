#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{

	stack<char> s1;
	char data[1000005];
	int length,count = 0;
	scanf("%d%s",&length,data);
	char last;
	for (int i = 0; i < length; ++i)
	{
		if(s1.empty())
		{
			s1.push(data[i]);
			
			continue;
		}

		last = s1.top();
		s1.pop();
		if(s1.empty()){
			s1.push(last);
			s1.push(data[i]);
			continue;
		}

		if(s1.top() == 'O' && last == 'r' && data[i] == 'z'){
			s1.pop();
			count++;
			continue;
		}
		s1.push(last);
		s1.push(data[i]);


	}

	printf("%d\n", count);

	return 0;
}