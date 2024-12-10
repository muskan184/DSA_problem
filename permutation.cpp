class Solution {
public:
void rp(vector<int>&ds ,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
    int n=nums.size();
    if(ds.size()==n){
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<n;i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i]=1;
            rp(ds,nums,ans,freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int>ds;
        int freq[nums.size()];
         for(int i=0;i<nums.size();i++) freq[i]=0;
         rp(ds,nums,ans,freq);
         return ans;


    }
};
