class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixMax(n), suffixMax(n);
        // 算前缀
        for(int i = 0; i < n; i++)
        {
            if(i % k == 0)
            {
                prefixMax[i] = nums[i];
            }
            else
            {
                prefixMax[i] = max(nums[i], prefixMax[i-1]);
            }
        }
        // 算后缀
        for(int i = n - 1; i >= 0; i--)
        {
            if(i == n - 1 || (i + 1) % k == 0)
            {
                suffixMax[i] = nums[i];
            }
            else
            {
                suffixMax[i] = max(nums[i], suffixMax[i + 1]);
            }
        }

        vector<int> ans;
        for(int i = 0; i <= n - k; i++)
        {
            ans.push_back(max(suffixMax[i], prefixMax[i + k -1]));
        }

        return ans;
    }
};