//AC
//greedy
//http://poj.org/problem?id=3069 
#include <cstdio>
#include <cstring>
#include <algorithm>
//#include <vector>
using namespace std;
//vector<int> pos(1010);
int pos[1010];
int main (){
    int R, sum;
    while(EOF != scanf("%d %d", &R, &sum) && R!=-1 && sum!=-1){
    //    pos.clear() ;
        memset(pos, 0, sizeof(pos));
        for (int i = 0; i < sum; i++) {
  //          int tmp;
            scanf("%d", &pos[i]);
//            pos.push_back(tmp);
        }
        sort(pos, pos+sum);
        int cnt = 0;
        sum = unique(pos, pos+sum) - pos;
        for (int i = 0; i < sum; i++){
            int j;
            for (j = i; pos[i]+R >= pos[j]; j++);j--; //ѡ���i���Ҳ���Զ��Ϊ��ǵ� 
            cnt++;
            int k;
            for (k = j; pos[j]+R >= pos[k]; k++); //��ǵ��Ҳ໹�ܸ���һЩ 
            i = k;
            i--;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
