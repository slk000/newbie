#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int a, b;
	while(cin >> a >> b){
		cout << abs(a-b) << endl;
	}
	return 0;
}