#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        // 排序，从最小负数开始遍历，尽量全翻转为正数。如果还有剩余翻转次数（说明负数不够用），且为奇数次，翻转绝对值最小的那个数
        sort(nums.begin(), nums.end()); 
        int n = nums.size();

        int res = 0;
        int i = 0;
        int minIdx = 0; // 绝对值最小的数的下标 用来消耗剩余翻转次数
        for (; i < n; i++) {
            // cout << k << endl;
            if (abs(nums[i]) < abs(nums[minIdx])) {
                minIdx = i;
            }
            if (k && nums[i] < 0) {
                res += -nums[i];
                k--;
            }
            else {
                res += nums[i];
            }
        }
        k %= 2;
        if (k == 1) {
            int m = nums[minIdx];
            if (m < 0) { // res 中已经包含nums[minIdx]了，需要加倍返还
                res += 2*m;
            }
            else {
                res -= 2*m;
            }
        }
        
        return res;
    }
};

int main() {
    vector<int> nums{4,2,3};
    cout << Solution().largestSumAfterKNegations(nums, 1) << endl;
}
