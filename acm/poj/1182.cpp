//AC
//http://poj.org/problem?id=1182
//并查集
//
#include <cstdio>
#include <utility>
using namespace std;
class DisjointSet{
private:
    int *father;
    int *rank;
public:
    DisjointSet(int size){
        father = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++){
            father[i] = i;
            rank[i] = 0;
        }
    }
    ~DisjointSet(){
        delete[] father;
        delete[] rank;
    }
    int find_root(int node){
        if (node != father[node]){
            father[node] = find_root(father[node]);
        }
        return father[node];
    }
    
    bool merge(int node1, int node2){
        int root1 = find_root(node1);
        int root2 = find_root(node2);
        if (rank[root1] < rank[root2]){
            swap(root1, root2);
        }
        father[root2] = root1;
        
        return root1!=root2;
    }
    void output(int c){
        for(int i = 0; i < c; i+=3)
            printf("%dA:%d%c, %dB:%d%c, %dC:%d%c\n", i/3+1,father[i]/3+1,father[i]%3+'A',i/3+1,father[i+1]/3+1,father[i+1]%3+'A',i/3+1,father[i+2]/3+1,father[i+2]%3+'A');
        
    }

};

int main(){
    int amount = 0, asserts = 0;
    int ans = 0;
    scanf("%d %d", &amount, &asserts);
    DisjointSet djset((amount+10) * 3);//因为每种动物具体是ABC哪个不清楚，所以每个动物都有三种假设。那个10是纯属多写几个
    int type =0, x = 0, y = 0;
    for (int i = 0; i < asserts; i++) {
        scanf("%d %d %d", &type, &x, &y);
        x--;y--;//输入是从1开始的，而并查集内部是从0 
        if (x >= amount || y >= amount || (type == 2 && x == y) ) {
            
            ans++;
            // printf("err1 \t total:%d\n", ans);
            continue;
        }
                // printf("//////////// Before /////////////\n");
                // djset.output(amount*3);
                // printf("/////////////////////////////////\n");
        
        //三种属性，xy在一组里、x吃y、y吃x
        //因为下面merge时三种假设都同时做了，每个相等的比较都是捆绑的，所以这里用&& 
        bool isSameGroup = (djset.find_root(x*3)==djset.find_root(y*3) && djset.find_root(x*3+1)==djset.find_root(y*3+1) && djset.find_root(x*3+2)==djset.find_root(y*3+2));
        bool isYEatX = (djset.find_root(y*3)==djset.find_root(x*3+1) && djset.find_root(y*3+1)==djset.find_root(x*3+2) && djset.find_root(y*3+2)==djset.find_root(x*3));
        bool isXEatY = (djset.find_root(x*3)==djset.find_root(y*3+1) && djset.find_root(x*3+1)==djset.find_root(y*3+2) && djset.find_root(x*3+2)==djset.find_root(y*3));
        // printf("%s\n%s\n%s\n", isSameGroup?"same":"diff", isYEatX?"Y eats X":"Y don't eat X",isXEatY?"X eats Y":"X don't eat Y");
        
        switch (type){
            case 1:{
                
                if (isXEatY || isYEatX ) {
                    
                    {
                        ans++;
                        // printf("err2 \t total:%d\n", ans);
                        continue;
                    }
                }
                
                djset.merge(x*3, y*3);//x-A 与 y-A合并到一组，表示若x属于A那么y也必定属于A
                djset.merge(x*3+1, y*3+1);//x-B 与 y-B合并到一组，表示若x属于B那么y也必定属于B
                djset.merge(x*3+2, y*3+2);//同上
                break;
            }
            case 2:{ // 
                
                
                if (isSameGroup || isYEatX) {//自相残杀和y吃x可情况是不正确的

                    {
                        ans++;
                        // printf("err3 \t total:%d\n", ans);
                        continue;
                    }
                }
                //（因为x吃y有三种情况：x属于A则y属于B、x属于B则y属于C、x属于C则y属于A）
                djset.merge(x*3, y*3+1);//合并x-A与y-B，代表若x属于A那么y一定属于B（x吃y）
                djset.merge(x*3+1, y*3+2);//同上
                djset.merge(x*3+2, y*3);
                break;
            }
        }
                // printf("//////////// After /////////////\n");
                // djset.output(amount*3);
                // printf("/////////////////////////////////\n");
        
    }
    
    printf("%d\n", ans);
    
    return 0;
}