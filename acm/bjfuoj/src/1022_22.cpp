#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LL __int64
void shit(int);
long long randNum();
double random(double start, double end);
long long a,n,numCount=0;
int ext;

FILE* fp2,*fp3;

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
	fp3 = fopen("3.txt","a+");//
	fp2 = fopen("2.txt","a+");
	cin >> ext;
    double random(double,double);
    srand(unsigned(time(0)));
	while(ext>=0){
		a = (long long)random(0,4294967295);
		fprintf(fp2, "num:%lld\n", a);
		shit(2);
		shit(8);
		shit(10);
		shit(16);
		fprintf(fp2, "\n");
		
	
	
	


    
    LL s[4]={2,8,10,16};
    LL n,j;
    LL i;
    int m;
    LL ans;
    n = a;
    fprintf(fp3, "num:%lld\n", n);
    //scanf("%I64d",&n);
   // while(n <= 4294967295)
    //{
        for(j=0;j<4;j++)
        {
            ans=1;
            i=fuc(n,s[j]);
            for(m=0;m<i;m++)
                ans*=s[j];
            i=fuc2(i,s[j])-(ans-1-n)*i;
            //printf("%I64d\n",i);
            fprintf(fp3, "%I64d\n", i);//
        }
        fprintf(fp3, "\n");//
        
    //}
        ext--;

}
fclose(fp2);
fclose(fp3);

	return 0;
}

void shit(int base){
	for (n = 0, numCount = 0; a >= pow((double)base,(double)n); n++)
		numCount += pow((double)base,(double)(n - 1)) * n * ( base - 1 );
	numCount += n * (1 + a - pow((double)base,(double)(n-1)));
	//cout << numCount << endl;
	fprintf(fp2, "%lld\n", numCount);
	
}
double random(double start, double end)
{
    return start+(end-start)*rand()/(RAND_MAX + 1.0);
}
