//最长公共子序列
#include <stdio.h>
int max(int a, int b) {return a>b?a:b;}
int max(int a, int b, int c) {return max(a>b?a:b,c);}
int main(int argc, char const *argv[])
{
	
 
    int num1, num2;
    while(scanf("%d%d",&num1, &num2) != EOF){
        int arr1[num1], arr2[num2], i, j;
        unsigned char data[num1 + 1][num2 + 1];
        for (i = 0; i < num1; ++i)
        {
            scanf("%d",&arr1[i]);
            data[i][0] = 0;
        }
        data[i][0] = 0;
        for (i = 0; i < num2; ++i)
        {
            scanf("%d",&arr2[i]);
            data[0][i] = 0;
        }
        data[0][i] = 0;
 
        for (i = 0; i <= num1; ++i)
        {
            for (j = 0; j <= num2; ++j)
            {
                
                // printf("(%d,%d)\n", j,i);
                // data[i][j] = (data[i-1][j] > data[i][j-1]) ? data[i-1][j] : data[i][j-1];

                if(arr1[j] == arr2[i]){
                    // data[i][j]++;
                    // printf("%d=%d,++\n",arr1[j-1] ,arr2[i-1]);
                    //data[i][j] = max(data[i-1][j-1]+1, data[i-1][j],data[i][j-1]);
                    data[i+1][j+1] = data[i][j]+1;
                }
                else {
                	data[i+1][j+1] = max(data[i][j+1], data[i+1][j]);
                }
            }
        }
 
     // for (int i = 0; i <= num1 ; ++i)
     // {
     //     for (int j = 0; j <= num2 ; ++j)
     //     {
     //         printf("%d ",data[i][j]);
     //     }
     //     printf("\n");
     // }
 
       printf("%d\n", data[num1][num2]);
    }
    return 0;
}