class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) {
        const int n=nums.size();
        unordered_map<int, int> mp;
        mp[0]=1;
        mp.reserve(n);
        long long ans=0;
        int prefix=0;
        for(int i=0; i<n; i++){
            prefix+=((nums[i]%mod)==k);
            ans+=mp[(prefix+mod-k)%mod];
            mp[prefix%mod]++;
        }
        return ans;
    }
};
