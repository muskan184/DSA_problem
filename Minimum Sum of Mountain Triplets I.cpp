class Solution {
public:
    int minimumSum(vector<int>& nums) {
        int n = nums.size(),res=INT_MAX;
        vector<int> lMin(n),rMin(n);
        lMin[0]=nums[0],rMin[n-1]=nums[n-1];
        for(int i=1;i<n;i++) {
            lMin[i]=min(lMin[i-1],nums[i]);   
        }
        for(int i=n-2;i>=0;i--) {
            rMin[i]=min(rMin[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++) {
            if(lMin[i]<nums[i] && rMin[i]<nums[i]) {
                res = min(res,lMin[i]+rMin[i]+nums[i]);
            }
        }
        if(res==INT_MAX)
            return -1;
        return res;
    }
};
