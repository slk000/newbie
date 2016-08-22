#include <iostream>
#include <time.h>
using namespace std;
//，闰年的年份是400的倍数，或者是4的倍数但不是100的倍数
int main(int argc, char const *argv[])
{	
	long cha;
	int inYear,inMon,inDay;
	int days[]={31,0,31,30,31,30,31,31,30,31,30,31};
	string sInData;
	while(cin >> sInData){
		if(sInData[4] == '-'&& sInData[7] == '-'  && sInData.length() == 10)
			sInData = sInData.substr(0,4) + sInData.substr(5,2) +sInData.substr(8,2);
		else if (sInData[2] == '/' && sInData[5] == '/' && sInData.length() == 10)
			sInData = sInData.substr(6,4) + sInData.substr(0,2) +sInData.substr(3,2);
		else{
			cout << "Error" << endl;
			continue;
		}
		if((inYear = atoi(sInData.substr(0,4).c_str())) % 400 == 0 || (inYear % 4 == 0 && inYear % 100 != 0) )
			days[1] = 29;
		else
			days[1] = 28;
		if( inYear < 2000 || (inMon = atoi(sInData.substr(4,2).c_str())) > 12 || inMon < 1 || (inDay =atoi(sInData.substr(6,2).c_str())) < 1 || inDay > days[inMon-1])
			cout << "time error" << endl;
		struct tm tInData = {0,0,0,inDay,inMon-1,inYear-1900};
		cha = mktime(&tInData) - 946656000;
		cout << cha / 86400 << endl;
}
	return 0;
}