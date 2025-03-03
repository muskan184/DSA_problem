class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;

        int cnt =0,i=0,j=0;
        int n=s.size();
        while(j<n){
            mp[s[j]]++;
            while(mp['a'] && mp['b'] && mp['c']){
                cnt+=n-j;
                mp[s[i]]--;
                i++;
            }
            j++;
        }
        return cnt;

    }
};
