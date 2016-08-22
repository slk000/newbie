#include <iostream>
using namespace std;
string rmInt(string intNum);
string rmFlt(string intNum);
bool flagI = true, flagF = true;

int main(int argc, char const *argv[])
{
	int i,point;
	string data,sF,sI;
	

	while(cin >> data){
		point = data.find('.');

		if(data[data.length() - 1 ]=='.'){
			cout << rmInt(data.substr(0,point)) << endl;

		}

		else if(point == EOF)
			cout << rmInt(data) << endl;
		else{
			sI = data.substr(0,point);
			
			sF = data.substr(point+1,data.length()-point);
			cout << rmInt(sI) << rmFlt(sF) <<endl;
		}
	}
}

string rmInt(string intNum){
	
	int i;
	flagI = true;
	for (i = 0; i < intNum.length(); i++)
	{
		if(intNum[i] == '0' && flagI == true)
			continue;
		else{
			flagI = false;
			intNum = intNum.substr(i,intNum.length());
			break;
			}
	}
	if(flagI)
		intNum = "0";

	return intNum;
}

string rmFlt(string fltNum){
	int i;
	flagF = true;
	for (i = fltNum.length() - 1; i >= 0; i--)
	{
		
		if(fltNum[i] == '0' && flagF == true)
			continue;
		else{
			flagF = false;
			fltNum = fltNum.substr(0,i+1);
			break;
			}
	}

	if(flagF)
		fltNum = "";
	else
		fltNum = "." + fltNum;
	return fltNum;

}