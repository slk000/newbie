#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n;
	while(cin >> n)
		cout << (long long)pow(2,(double)n) << endl;
	return 0;
}