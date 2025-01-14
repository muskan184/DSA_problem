class Solution {
public:
    int t[301][301];
    bool solve(int i, int j, string s, map<string, bool>& mp){
        string str = s.substr(i, j-i+1);
        if(mp.find(str) != mp.end())return true;

        if(t[i][j] != -1)return t[i][j];
        // cout << "h";

        bool ans = false;
        for(int k = i; k < j; k++){
            ans = ans || (solve(i, k, s, mp) && solve(k+1, j, s, mp));
        }

        return t[i][j] = ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(t, -1, sizeof(t));
        map<string, bool> mp;
        for(auto s : wordDict)mp[s] = true;

        return solve(0, s.length()-1, s, mp);
    }
};
