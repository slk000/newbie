#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int amount, i;
	while(cin >> amount){
		int data[amount];

		for(i = 0; i < amount ; i++)
		{
			int t;
			cin >> t >> data[i];

			data[i] += t;

		}

		for ( i = 0; i < amount; i++)
		{
			cout << data[i] << endl;
		}
	}
	return 0;
}