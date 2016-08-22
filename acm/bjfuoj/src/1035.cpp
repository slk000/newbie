#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int num, i,j;
	cin >> num;
	string vocabularies[num];

	for (i = 0; i < num; i++)
	{
		cin >> vocabularies[i];
	}

	for (i = 0; i < num; i++)
	{
		for (j = vocabularies[i].length() - 1; j >= 0 ; j--)
		{
			cout << vocabularies[i][j];
		}
		cout << endl;
	}
	return 0;
}