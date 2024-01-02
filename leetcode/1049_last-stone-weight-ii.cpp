/*
问题转化为：分成两堆重量相近的石头，这样粉碎之后剩下的石头是最轻的
所以期望的一堆石头的重量是 target=总重量/2
用stones里的石头来**尽量**凑target
与分割等和子集（https://leetcode.cn/problems/partition-equal-subset-sum/）相似
*/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        int n = stones.size();
        for (int v : stones) {
            sum += v;
        }
        int target = sum/2;

        vector<int> dp(target+1); // 压缩数组
        for (int stone = 0; stone < n; stone++) { // 取物
            for (int weight = target; weight >= 0; weight--) {
                if (weight-stones[stone] >= 0) {
                    dp[weight] =max(dp[weight], dp[weight-stones[stone]] + stones[stone]);
                }
                // else { // 保持
                //     dp[weight] = dp[weight];
                // }
                
            }
            // for (int i = 0 ; i <= target; i++) {
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
        }


        // 分成了两堆，重量分别为 dp[target] sum-dp[target]
        // 相差abs(dp[target]-sum+dp[target]) = abs(2dp[target]-sum)
        return abs(2*dp[target] - sum);
    }
};
