class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
       for(auto num:nums){
        totalSum += num;
       }

       if(totalSum % 2 != 0){
        return false;
       }
       
       int target = totalSum/2;
       vector<bool>dp(target+1,false);
       dp[0]=true;

       for(auto num:nums){
        for(int j=target;j>=num;j--){
            dp[j]=dp[j]||dp[j-num];
        }
       }
        return dp[target];
    }
};
