#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL __int64
FILE* fp;
LL fuc(LL x,LL y)
{
    return ceil(log(x+1)/log(y));
}
LL fuc2(LL x,LL y)
{
    int i;
    LL ans=1;
    for(i=0;i<x;i++)
        ans*=y;
    return x*ans-(1-ans)/(1-y);
}

int main()

{
    fp = fopen("3.txt","a+");//
    LL s[4]={2,8,10,16};
    LL n,j;
    LL i;
    int m;
    LL ans;
    scanf("%I64d",&n);
    while(n <= 4294967295)
    {
        for(j=0;j<4;j++)
        {
            ans=1;
            i=fuc(n,s[j]);
            for(m=0;m<i;m++)
                ans*=s[j];
            i=fuc2(i,s[j])-(ans-1-n)*i;
            //printf("%I64d\n",i);
            fprintf(fp, "%I64d\n", i);//
        }
        fprintf(fp, "\n");//
        n++;//
    }
    return 0;
} 