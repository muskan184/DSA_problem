class Solution {
public:    void func(int ind, vector<int>&nums, vector<int> &ds,vector<vector<int>> &sumSubset){
            sumSubset.push_back(ds);
            for(int i=ind; i<nums.size();i++){
                if(i!=ind && nums[i]==nums[i-1]) continue;
                ds.push_back(nums[i]);
                func(i+1,nums,ds,sumSubset);
                ds.pop_back();
            }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
           int N= arr.size();
        vector<vector<int>>sumSubset;
        vector<int>ds;
        sort(arr.begin(),arr.end());
        func(0,arr,ds,sumSubset);
        return sumSubset;
      
    }
};
