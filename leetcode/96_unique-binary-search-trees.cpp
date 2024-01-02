#include <iostream>
using namespace std;

class Solution {
public:
    int n;
    int cnt = 0;
    int dfs(int root, uint32_t status){
        // if(status == (1<<n)-1){ // if all nums used. root == n is wrong
        //     return 1;
        // }
        cout << root << endl;
        int left = 0;
        int right = 0;
        for(int i = 1; i < root; i++){
            int mask = 1 << (i-1);
            if(status & mask) continue;
            left += dfs(i, status | mask);
        }
        for(int i = root+1; i <= n; i++){ // TODO: wrong boundry n
            int mask = 1 << (i-1);
            if(status & mask) continue;
            right += dfs(i, status | mask);
        }
        if(left == 0 && right == 0) return 1;
        if(left != 0 && right != 0) return left*right;
        return left+right;
    }
    int numTrees(int n) {
        cnt = 0;
        int res = 0;
        this->n = n;
        for(int i = 1; i <= n; i++){
            int cnt = dfs(i, 1<<(i-1));
            cout << "root: " << i  << " " << cnt << endl;
            res += cnt;
        }
        return res;
    }
};

int main(){
    int n;
    while(cin >>n){
        cout << Solution().numTrees(n) << endl;
    }
    return 0;
}