class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int num:nums){
            freq[num]++;
        }

        vector<vector<int>>ans;

        for(auto &[num,count]:freq){
            for(int i=0;i<count;i++){
                if(ans.size() <= i){
                    ans.push_back({});
                }
                 ans[i].push_back(num);
            }  
        }
        return ans;
    }
};
