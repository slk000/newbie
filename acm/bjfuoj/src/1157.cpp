#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	long long iA,iB;
	string sB;
	int i;
	

	while(cin >> iA >> sB){
		iB = 0;
		bool flag = true;
		for (i = 0; i < sB.length(); i++)
		{
			if(sB[i] == '0' && flag == true)
				continue;
			else{
				flag = false;
				sB = sB.substr(i,sB.length());
				break;
				}

		}
		
		for (i = 0; i < sB.length(); i++)
		{

			iB += (long long)pow(10.,(double)i) * (sB[i] - 48);
		}
		cout << iA+iB<< endl;

	}
	return 0;
}