#include <iostream>
#include <string>

using namespace std;
int main(){
	string str;
	getline(cin, str);
	int i;
		
	for (i = str.length(); str[i] != ' ' && i > 0; i--);

	if(i == 0)
		return 0;
	else
		cout << str.length() - i - 1;
	return 0;
}