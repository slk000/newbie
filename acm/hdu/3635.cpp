//AC
//并查集 
#include <iostream>
#include <cstdio>
#include <memory.h>
#define NN 10010
using namespace std;
typedef struct Ball{
    int loc;//没用 
    int time;//直接移动次数 （即作为根移动的次数） 
};
int cityCnt[NN];//记录每个城市龙珠的个数 
Ball ball[NN];
class DisjointSet {
private:
    int *father, *rank;
public:
    DisjointSet(int size) {
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; ++i) {
            father[i] = i;
            rank[i] = 0;
        }
    }
    ~DisjointSet() {
        delete[] father;
        delete[] rank;
    }
    int find_set(int node) {
        int res = node;
        if (father[res] != res ){
            res = find_set(father[res]);
            //ball[node].time += ball[res].time;
        }
        return res;
    }
    int getTimes(int node){//每一个结点的实际移动次数=它的直接移动次数+它父节点们的移动次数 
        int sum = ball[node].time;
        while(father[node] != node){
            node=father[node];
            sum += ball[node].time;
        }
        //sum += ;
        return sum;
    }
    bool merge(int from, int to) {
        int ancestor1 = find_set(from);
        int ancestor2 = find_set(to);
        if (ancestor1 != ancestor2) {
            
            cityCnt[ancestor2] += cityCnt[ancestor1];
            //cityCnt[ancestor1]=0;
            
            ball[ancestor1].loc=ancestor2;
            ball[ancestor1].time++;
            //if (from != ancestor1) ball[from].time+=ball[ancestor1].time;
            father[ancestor1] = ancestor2;
            //father[from]=ancestor2;
            return true;
        }
        return false;
    }
};

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++){
        memset(ball, 0, sizeof(ball));
        memset(cityCnt, 0, sizeof(cityCnt));
        printf("Case %d:\n",t);
        int N, Q; //ball,statement
        scanf("%d %d", &N, &Q);
        for (int i = 0; i <= N; i++) {
            cityCnt[i]=1;
            ball[i].loc = i;
            ball[i].time = 0;
        }
        
        DisjointSet dsu(N+1);
        
        for(int i = 0; i < Q; i++) {
            char op;
            int A, B;
            
            scanf("%*c%c", &op);
            
            if(op == 'T'){
                scanf("%d %d", &A, &B);
                dsu.merge(A,B);
            }
            else if(op == 'Q'){
                scanf("%d",&A);
                int X = dsu.find_set(A);
                // X (the id of the city Ath ball is in), 
                //Y (the count of balls in Xth city),
                //Z (the tranporting times of the Ath ball)
                printf("%d %d %d\n", X, cityCnt[X], dsu.getTimes(A));              
            }
        } 
    }
    return 0;
}                                                                        
