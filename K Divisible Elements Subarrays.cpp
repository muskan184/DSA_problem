class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        
         int n = nums.size();
         set <vector<int>>ans;

         for(int i=0;i<n;i++){
            vector<int>cnt;
            int count=0;
            for(int j=i;j<n;j++){
                cnt.push_back(nums[j]);
                if(nums[j]%p == 0) count++;

                if(count > k)break;
                ans.insert(cnt);
            }

         }
         return ans.size();
    }
};
