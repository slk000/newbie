#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> &nums, int start) {
        res.emplace_back(path); // dfs过程中，加入所有出现的path（注意这行的位置）
        if (start == nums.size()) {
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) continue;//去重
            path.push_back(nums[i]);
            dfs(nums, i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};

int main() {
    vector<int> nums{1,2,3};
    auto vv = Solution().subsets(nums);
    for (auto v : vv) {
        for (auto i : v) {
            cout << i << "\t";
        }
        cout << endl;
    }
}
