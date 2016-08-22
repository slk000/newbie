#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a, b;

	while(cin >> a >> b){
		cout <<  a+b << endl << a-b << endl << a*b << endl << a/b << endl << a%b << endl;
	}
	return 0;
}