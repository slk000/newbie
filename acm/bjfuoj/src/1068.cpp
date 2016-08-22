#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	int sum,i=0;
	cin >> sum;
	string* count[sum];
	string data[sum];
	
	for (i = 0; i < sum; i++)
	{
		cin >> data[i];
		count[i] = &data[i];
	}
	

	for(i = 0;i<sum;i++){
		cout << *count[i] << endl;
	}
	return 0;
}