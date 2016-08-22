//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1011
//AC
//小数化分数 http://blog.csdn.net/xinghongduo/article/details/6231107
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
__int64 gcd(__int64 a,__int64 b)  
{  
    return (!a)?b:gcd(b%a,a);
}  
int main(int argc, char const *argv[])
{
	__int64 ago[16] = {1,10,100,1000,10000,100000,1000000,10000000,100000000LL,1000000000LL,10000000000LL,100000000000LL,1000000000000LL,10000000000000LL,100000000000000LL,1000000000000000LL};
	string strNum;
	while(cin >> strNum){
		int len = strNum.length();
		__int64 a, b, Gcd;
		if (strNum[len - 1] == ')')
		{
			int cyclicStart = strNum.find('(', 2);
			string strCyclic = strNum.substr(cyclicStart+1, len-cyclicStart-2);
			string strAcyclic = strNum.substr(2, cyclicStart - 2);
			__int64 intAcyclic = atoll(strAcyclic.c_str());
			__int64 intAll = atoll((strAcyclic+strCyclic).c_str());
			a = intAll - intAcyclic;
			b = ago[strCyclic.length()+strAcyclic.length()] - ago[strAcyclic.length()];
		}
		else{
			a = atoll(strNum.substr(2, len - 2).c_str());
			b = ago[len-2];
		}
		Gcd = gcd(a,b);
		printf("%lld/%lld\n", a/Gcd,b/Gcd); 
	}
	return 0;
}