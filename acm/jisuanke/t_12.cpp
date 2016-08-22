#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main (){
	string str;
	int res;
	stringstream in;
	getline(cin, str);
	in.clear();
	in.str(str);
	while(in >> str){
		res = str.length();
	}
	printf("%d\n", res);
	return 0;
}