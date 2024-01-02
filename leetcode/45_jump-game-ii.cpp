#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> steps(n);
        steps[0] = -1;
        int rightMost = nums[0];
        int where = 0; // 从哪个下标可以跳到这个rightMost

        for (int i = 0; i < n; i++) {
            int newRightMost=rightMost, newWhere=where; // 遍历途中找到的新rightMost
            int j = i;
            for (; j <= min(rightMost,n-1); j++) {
                cout << "j: " << j << endl;
                // rightMost区间内的位置都可以一步跳过来
                steps[j] = steps[where]+1;
                if (nums[j]+j > newRightMost) {
                    newRightMost = nums[j]+j;
                    newWhere = j;
                }
            }

            // if (newRightMost == -1) {
            //     // 没有找到更远的
                
            // }
            rightMost = newRightMost;
            where = newWhere;
            i = --j; // O(n)
        }

        return steps[n-1];
    }
};

int main() {
    // vector<int> nums{2,3,1,1,4};
    vector<int> nums{2,3,0,1,4};
    cout << Solution().jump(nums) << endl;

}
