#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
	stack<char> num1, num2,*p;
	char ch;
	p = &num1;
	while (ch = getchar()){
		if(ch == ' ') p=&num2;
		else if(ch == '\n') break;
		else p->push(ch);
	}

	int count = 0, j = 0, flag1 = false, flag2 = false;
	char num1top, num2top;
	while(!num1.empty() || !num2.empty()){
		if(num1.empty()){
			num1top = '0';
		}
		else{
			num1top = num1.top();
			num1.pop();
		} 
		if(num2.empty()){
			num2top = '0';
		}
		else{
			num2top = num2.top();
			num2.pop();
		} 
		//cout << num1top-'0' << "+" <<num2top-'0'<<endl;
		if(num1top -'0'+ num2top-'0' + j >=10){
			count++;
			j = 1;
		}
		else
			j = 0;

	}
	cout << count << endl;
	return 0;
}