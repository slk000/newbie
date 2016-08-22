#include <stdio.h>
int main(int argc, char const *argv[])
{
    /*
    //creat data array
    int data[41] = {0,1};
	for (int i = 2; i < 41; ++i)
    {
        data[i] = data[i-1]+data[i-2];
    }
    for (int i = 0; i < 41; ++i)
    {
        printf("%d,",data[i]);
    }
    */
    int data[41] = {0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155};
    int N;
    while(EOF != scanf("%d",&N)){
        printf("%d\n", data[N]);
    }
	return 0;
}