#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int T,j;
	cin >> T;
	for(j = 1; j <= T; j++)
	{
		string str;
		cin >> str;
		int nextValue = 1,res=0;
		for (int i = 0; i < str.length(); ++i)
		{	
			switch(str[i]){
				case 'O':
					res += nextValue++;
					break;
				case 'X':
					nextValue = 1;
					break;
			}
		}
		cout << "Case " << j << ": " <<res <<endl;
	}
	return 0;
}

