#include <cstdio>
int main(){
    int sum;
    scanf("%d", &sum);
    int arr[sum];
    for (int i = 0; i < sum; i++){
        scanf("%d", &arr[i]);
    }
    int target;
    scanf("%d", &target);
    
    int left = 0, right = sum-1, mid = right/2;
    while(left < right){
        //printf("%d:%d\n", left, right);
        //printf("%d\n", mid);
        if(arr[mid] > target){
            right = mid-1;
        }
        else if(arr[mid] < target){
            left = mid+1;
        }
        else{
            break;
        }
        mid = (right + left)/2;

    }

    printf("%d\n", (arr[mid] < target)?mid+1:mid);
    return 0;
}