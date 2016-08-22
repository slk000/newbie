//http://acm.bjfu.edu.cn/acmhome/problemdetail.do?&method=showdetail&id=1087
//AC
//分解质因数
//快速幂求余
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//a^b % p
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
int main(){
    int x=30;
    //while(EOF!=scanf("%d", &x) && x)
    while(x)
    {
        int ans =
            (qp(2,2*x+1,29)-1) *
            (qp(10,x+1,29)-1) * 13;
        ans = ans % 29;
        printf("%d\n", ans);
        x--;
    }
     
    return 0;
}
// 答案有规律
// #include <stdio.h>
// int main(){
// 	int x;
// 	char a[28] = {1,19,19,12,14,1,7,21,12,1,5,19,2,13,2,2,16,21,11,21,3,28,19,16,14,8,28,0};
// 	while(EOF!=scanf("%d", &x) && x)
// 		printf("%d\n", a[x%28]);
// 	return 0;
// }