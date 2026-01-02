class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
    int ans=0;
    unordered_map<int,int>mp;

    for(int n : nums) {
        mp[n]++;

        if(mp[n] > 1) return n;
      }
     return -1;
    }
};
