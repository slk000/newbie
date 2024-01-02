class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        /*
            问题转化为：nums分成两个集合：一个集合P中的数前面放正号，另一个集合N的放负号。目标是凑出放正号的集合，剩下的就是放负号。
            (+a +b +c +d) -e -f -g -h = target
            => (+a +b +c +d) - (+e +f +g +h) = target
            => sum(P) - sum(N) = target ————(式1)

            sum(P) + sum(N) = sum(nums) ————(式2)

            为了消除N
            式1+式2 = 2sum(P) = target+sum(nums)
            => sum(P) = (target+sum(nums)) / 2
            所以要凑的正数集合的sum如上

            以样例1为例：sum(P) = (5+3)/2=4
            代表结果中的5中组合方法中均有4个正数
        */
        int n = nums.size();
        int sum = 0;
        for (int v : nums) {
            sum += v;
        }
        if ((target + sum) & 1) return 0; // 如果无法分割，则没有构造的方法。（证明?）
        // target有限制：-sum <= target <= sum   
        if (abs(target) > sum) return 0;
        int sumPTarget = (target + sum)/2;
        
        vector<int> dp(sumPTarget+1); // dp[i]存的是能凑成数字i的组合的个数
        dp[0] = 1;
        for (int num = 0; num < n; num++) { // 取数
            for (int size = sumPTarget; size >= nums[num]; size--) { // bag size
                if (size-nums[num] >= 0) {
                    dp[size] = dp[size] + dp[size-nums[num]]; //这个背包是，求组合的数量，所以是用加法将子问题加起来，而不是用max取一个值
                }
                // else {
                //     dp[size] = dp[size];
                // }
            }
            // for (int i = 0; i <= sumPTarget; i++) {
            //     cout << dp[i] << " ";
            // }
            // cout << endl;
        }
        return dp[sumPTarget];
    }
};
