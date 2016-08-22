#include <stdio.h>
int main()
{
    int T,n,max,min,num;
    scanf ("%d",&T);
        while(T--)
        {
            max=-1000000;
            min=1000000;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&num);
                if(max<num) max=num;
                if(min>num) min=num;
            }
            printf("%d %d\n",min,max);
        }
    
    return 0;
}