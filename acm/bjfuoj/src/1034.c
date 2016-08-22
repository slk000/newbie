//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1034
//Ac
//a^b&p
//快速幂求余 http://www.cnblogs.com/PegasusWang/archive/2013/03/13/2958150.html http://blog.chinaunix.net/uid-26602509-id-3299184.html 
//模运算 http://blog.csdn.net/ld326/article/details/7880429
#include <stdio.h>
int qp(int a, int b, int p){
	int ans = 1;
	a = a % p;
	while(b > 0){
		
		if (b % 2 == 1)
			ans = (ans * a) % p;
		b = b/2;
		a = (a*a) % p;
		
	}
	return ans;
}
int main(int argc, char const *argv[])
{
	int a, b, ans;
	while(EOF != scanf("%d%d", &a, &b)){
		if(a == 0 && b == 0) break;
		printf("%d\n", ((ans=qp(a,b,9))||!a)?ans:9);//余数为零时表示数字和为9，除了a=0时
	}
	
	return 0;
}