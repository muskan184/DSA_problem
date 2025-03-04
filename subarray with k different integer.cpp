class Solution {
public:
int count(vector<int> &nums,int k){
    int n =nums.size();
     unordered_map<int,int>mp;

        int i=0,j=0,c=0;

        while(j<n){
            mp[nums[j]]++;

            while(i<=j && mp.size()>k){
                if(--mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
            }
            c+=(j-i+1);
            j++;
        }
        return c;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return count(nums,k)-count(nums,k-1);
    }
};
