//AC
//¶þ·Ö 
#include <cstdio>
#include <iostream>
#include <algorithm> 
#include <memory.h>
#include <vector> 
using namespace std;
#define MAX_S 1000
#define MAX 500
int num[3][MAX];
int queryNum[MAX_S];
vector<int> ab;
bool res[MAX_S];
int sum[3];
int Case;
bool bs(int l, int r, int t){
    int mid = (l+r)/2;
    while (l<=r){
        mid = (l+r)/2;
        if (ab[mid] == t) return true;
        if (ab[mid] < t) l = mid+1;
        else if (ab[mid] > t) r = mid-1;
    }
    return false;
} 
int main (){
   while(scanf("%d %d %d", &sum[0],&sum[1],&sum[2]) != EOF)
    {
        Case++;
        memset(num, 0, sizeof(num));
        memset(res, 0, sizeof(res));
        memset(queryNum, 0, sizeof(queryNum));
        ab.clear();
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < sum[i]; j++) {
                scanf("%d", &num[i][j]);
            }
        }
        for (int i = 0; i < sum[1];i++){
            for (int j = 0; j < sum[0];j++){
                ab.push_back(num[1][i]+num[0][j]);
                //printf("%d\t", num[1][i]+num[0][j]);
            }
            //printf("\n");
        }
        sort(ab.begin(), ab.end());
        int querySum;
        
        scanf("%d", &querySum);
        for (int i = 0; i < querySum; i++) {
            scanf("%d", &queryNum[i]);
        }
        printf("Case %d:\n", Case);
        for(int i = 0; i < querySum; i++) {
            for(int j = 0; j < sum[2];j++){
                res[i] = (res[i] || bs(0,ab.size()-1,queryNum[i]-num[2][j]));
            }
            printf("%s\n", res[i]?"YES":"NO");
        }
        
            
    }
    return 0;
}
