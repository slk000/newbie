//AC
//http://poj.org/problem?id=3253
/* //normal solution 
#include <cstdio>
#include <algorithm>
using namespace std;
int L[20010];
long long res;
int SUM;

int main() {
    
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
        SUM += L[i];
    }
    while(N>1)
    {
        int min1index=0, min2index = 1;
        if (L[min1index] > L[min2index]) swap(min1index, min2index) ;

        for (int i = 2; i < N; i++){ //L[min1index] < L[min2index]
            if (L[i] < L[min1index]){
                min2index = min1index; 
                min1index = i;
            }
            else if (L[i] < L[min2index]){
                min2index = i;
            }
        }

        int t = L[min1index]+L[min2index];
        res+=t;

        if(min1index == N-1){
            swap(min1index, min2index);
        }
        
        L[min1index] = t;
        L[min2index] = L[N-1];

        N--;
    }
    
    printf("%lld\n", res);
    return 0;
} 
*/

#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
priority_queue<int, vector<int>, greater<int> > qu;

int main (){
    int N;
    long long res = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        int tmp;
        scanf("%d", &tmp);
        qu.push(tmp);
    }
    
    while(qu.size()>=2){
        int t = qu.top();
        qu.pop();
        
        t += qu.top();
        qu.pop();
        
        qu.push(t);
        res += t;
        
    }
    printf("%lld\n",res);
    return 0;
}

