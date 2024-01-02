#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bs(vector<int> &nums, int target) {
        int l = 0, r = nums.size();
        int mid;
        while (l < r) {
            mid = (r-l)/2 + l;
            if (nums[mid] >= target) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }
        return l;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tail(1); // tail[i]代表长度为i子序列的末尾数字（需要尽可能小）
        tail[0] = nums[0]; // 开始时序列只有一个数字
        for (int i = 1; i < n; i++) {
            if (nums[i] > tail.back()) { // nums[i]的加入可以构成更长的序列
                tail.push_back(nums[i]);
            }
            else { // 若nums[i]更小，可以取代【原长度为idx的子序列末尾】
                int idx = bs(tail, nums[i]);
                tail[idx] = min(tail[idx], nums[i]);
            }
            
            // for (int v : tail) {
            //     cout << v<< " ";
            // }
            // cout << endl;
        }
        return tail.size();
    }
};

int main() {
    vector<int> nums{10,9,2,5,3,7,101,18};
    cout << Solution().lengthOfLIS(nums);

}
