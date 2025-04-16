class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        long long cnt=0;
        int left =0;
        for(int i=0;i<nums.size();i++){
            k-=mp[nums[i]]++;
            while(k<=0) 
            k+= --mp[nums[left++]];
            cnt+=left;
        }
        return cnt;

    }
};
