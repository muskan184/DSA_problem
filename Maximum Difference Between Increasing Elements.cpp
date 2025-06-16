class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;          
        int mn  = nums[0];     

        for (int i = 1; i < n; ++i) {
            if (nums[i] > mn) {
                ans = max(ans, nums[i] - mn);   
            } else {
                mn = nums[i];                   
            }
        }
        return ans;
    }
};
