class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi =0;
        int num=0;
        int n =nums.size();
        int l=0,r=0;
        while(r<n){
            while(num & nums[r]){
                num ^=nums[l];
                l++;
            }
            num |= nums[r];
            maxi = max(maxi,r-l+1);
            r++;
        }
        return maxi;
     }
};
