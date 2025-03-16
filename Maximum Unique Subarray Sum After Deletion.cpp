class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int  maxsum=nums[0];

        for(int i =1;i<nums.size();i++){
            if(maxsum < 0 ) maxsum=0;
            if(nums[nums.size()-1]<0) return nums[nums.size()-1];
            if(nums[i] != nums[i-1]){
                maxsum+=nums[i];

                
            }
        }
        return maxsum ;
    }
};
