#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	string data;
	int pos,c = 0;
	cin >> pos >> data;
	while((pos = data.find("Orz",0)) != string::npos){
		c++;
		if(pos != 0)
			data = data.substr(0,pos) + data.substr(pos + 3,data.length()-3);
		else
			data = data.substr(pos + 3,data.length()-3);
		//cout << data << endl;
	}

	cout << c << endl;
	return 0;
}