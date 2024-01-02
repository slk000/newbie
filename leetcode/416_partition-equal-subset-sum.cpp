// 如果数字总和sum是奇数，那肯定不能分割
// 如果是偶数，那么单个子集的和为sum/2
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }

        if (sum & 1) return false;
        int targetSum = sum/2;
        int maxBagSize = nums.size()-1;
        
        // 01背包，但是将nums[i]同时看作是物品体积及大小，当存在dp[targetSum]=targetSum时代表答案存在
        vector<int> dp((200*100)/2+1); // dp[背包大小]=背包内价值
        /*
            dp[0] = 0
            dp[1] = 1
            
            dp[6] = max(dp[6-nums[j]]+nums[j],dp[6])=max(dp[6-5]+5, dp[6])
        */
        dp[0] = 0;
        
        for (int j = 0; j < nums.size(); j++) { // 注意嵌套顺序和遍历顺序
            for (int bagSize = targetSum; bagSize >= 0; bagSize--) {// 更新所有数字在当前bagSize下的dp
                if (bagSize-nums[j] < 0) continue;
                dp[bagSize] = max(dp[bagSize-nums[j]]+nums[j], dp[bagSize]);
            }
        }
        // for (int v : dp) {
        //     cout << v <<" ";
        // }
        return dp[targetSum] == targetSum;
    }
};
