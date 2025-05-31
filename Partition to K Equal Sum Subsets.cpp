class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % k != 0) return false;

        int target = totalSum / k;
        int maxMask = 1 << n;
        vector<int> dp(maxMask, -1);
        dp[0] = 0; 

        for (int mask = 0; mask < maxMask; ++mask) {
            if (dp[mask] == -1) continue;
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i)) && dp[mask] + nums[i] <= target) {
                    int nextMask = mask | (1 << i);
                    dp[nextMask] = (dp[mask] + nums[i]) % target;
                }
            }
        }

        return dp[maxMask - 1] == 0; 
    }
};
