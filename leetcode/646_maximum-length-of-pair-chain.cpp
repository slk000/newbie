#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), 
            [](vector<int> &a, vector<int> &b){return a[0] > b[0];});
        return 0;
    }
};

int main(){
    vector<vector<int>> v = {{1,2},{2,3},{3,4}};
    cout << Solution().findLongestChain(v) << endl;
    return 0;
}