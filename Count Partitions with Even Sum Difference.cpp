class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum=0;
        int count=0;
        for(int num:nums){
            totalSum+=num;
        }
        int leftSum=0;
        for(int i=0;i<nums.size()-1;i++){
            leftSum+=nums[i];
            int rightSum = totalSum-leftSum;
            if((leftSum-rightSum) % 2==0){
                count++;
            }
        }
        return count;
    }
};
