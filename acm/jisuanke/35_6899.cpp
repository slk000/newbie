//AC
//http://www.jisuanke.com/course/35/6899
#include <cstdio>
using namespace std;
void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}
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
    void output(){


    }
};
int main (){
    int n, m;
    scanf("%d%d", &n, &m);
    DisjointSet dsu(n);
    int mergeTimes = 0;
    for (int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        mergeTimes += dsu.merge(a, b);
    }
    printf("%d\n", n - mergeTimes);
    return 0;
}