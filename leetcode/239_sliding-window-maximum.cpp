// multiset
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        int n = nums.size();

        vector<int> res;
        res.reserve(n-k+1);
        for (int i = 0; i < k; i++) {
            s.insert(nums[i]);
        }
        res.push_back(*s.rbegin()); // 找set中最大的那个数
        for (int i = k; i < n; i++) {
            auto it = s.find(nums[i-k]);
            if (it != s.end()) {
                s.erase(it); // 删除滑出窗口的那个数
            }
            s.insert(nums[i]);
            res.push_back(*s.rbegin());
        }
        return res;
    }
};

int main (int argc, char *argv[]) {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = Solution().maxSlidingWindow(nums, k);
    for (int v : res) {
        cout << v << endl;
    }
    
    return 0;
}
