#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(int argc, char const *argv[])
{
	stack<string> a;
	char data[202];
	scanf("%s", data);

	for (int i = 0; i < strlen(data)-2; )
	{
		string tmp;
		while(*(data+i) != ' '){
			tmp += *(data+i++);
			//i++;
			cout << tmp;
		}
		//a.push(tmp);
//		cout << tmp;
	}

	while(!a.empty()){
		cout << a.top()<<endl;
		a.pop();
	}

	return 0;
}