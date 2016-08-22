#include <stdio.h>
int main()
{
    int begin,end;
    int i,j,p;
    while(scanf("%d%d",&begin,&end)!=EOF)
    {
        for(p=begin;p<=end;p++)
        {
            for(i=1;i<p;i++)
            {
                for(j=i;j<p;j++)
                {
                    if(i*i+j*j==p*p)
                        printf("%d %d\n",i,j);
                }
            }
        }
    }
    return 0;
}