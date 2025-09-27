class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int n =nums.size();

        for(int k = 0;k<n-2;k++){
            if(nums[k+1]+nums[k+2] > nums[k])
            return nums[k]+nums[k+1]+nums[k+2];
    }
    return 0;
    }
};
