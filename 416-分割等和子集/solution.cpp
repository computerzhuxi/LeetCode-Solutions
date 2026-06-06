class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxVal = 0;
        
        // 1. 计算总和与最大值
        for (int num : nums) {
            sum += num;
            maxVal = max(maxVal, num);
        }
        
        int target = sum / 2;
        
        // 2. 不可能的情况直接返回
        if (sum % 2 != 0 || maxVal > target) {
            return false;
        }
        
        // 3. 一维 DP 数组
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        
        // 4. 0‑1 背包
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                if (dp[j - num]) {
                    dp[j] = true;
                }
            }
            // 可选优化：如果已经找到答案，提前结束
            if (dp[target]) break;
        }
        
        return dp[target];
    }
};