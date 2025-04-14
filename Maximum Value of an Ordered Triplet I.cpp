class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long result = 0;
        long long imax = 0, dmax = 0;
        for(int k = 0; k < n; k++){
            result = max(result, dmax * nums[k]);
            dmax = max(dmax, imax - nums[k]);
            imax = max(imax, (long long)nums[k]);
        }
        return result;
    }
};
