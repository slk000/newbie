#include <cstdio>
int main(int argc, char const *argv[])
{
	int length = 0;
	scanf("%d", &length);
	int result = length;
	int arr[length];
	//int *arr = new int[length];
	for (int i = 0; i < length; ++i)
	{
		scanf("%d", &arr[i]);
	}
	
	int removeEle = 0;
	scanf("%d", &removeEle);
	for (int i = 0; i < length; ++i)
	{
		if (arr[i] == removeEle)
		{
			result--;
		}
	}
	printf("%d\n", result);
	//delete []arr;
	return 0;
}