class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] % 2 ==0){
                ans.push_back(0);
            }else{
                ans.push_back(1);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
