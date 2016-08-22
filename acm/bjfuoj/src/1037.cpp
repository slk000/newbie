#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int num, sum , i;
	while(cin >> num)
	{
		sum = 0;
		for (i = 0; i < num; i++)
		{
			int t;
			cin >> t;
			sum += t;
		}
		cout << sum << endl;
	}
	return 0;
}