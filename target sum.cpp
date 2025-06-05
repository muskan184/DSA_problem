int dp[21][1001];
class Solution {
public:

    int countSubsetSum(vector<int>&nums,int sum){
        int n =nums.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }

       for(int i = 1; i <= n; i++){
    for(int j = 0; j <= sum; j++){
        if(nums[i - 1] <= j){
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        } else {
            dp[i][j] = dp[i - 1][j];
        }
    }
}
            return dp[n][sum];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
       int totalSum=0;
       for(int num:nums) totalSum+=num;
       if(totalSum < abs(target) || (totalSum+target) % 2 != 0) return 0;

       int subsetSum = (totalSum+target) / 2;
       return countSubsetSum(nums,subsetSum);
    }
};
