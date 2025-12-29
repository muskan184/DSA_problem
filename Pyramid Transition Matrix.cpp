class Solution {
public:

    unordered_map<string,vector<char>>mp;
    unordered_map<string,bool>memo;

    bool solve(string bottom){
        if(bottom.size() == 1) return true;
        if(memo.count(bottom)) return memo[bottom];

        vector<string> nextRows;
        buildNext(bottom , 0 , "" , nextRows);

        for(string &row : nextRows){
            if(solve (row)) return memo[bottom] = true;
        }
        return memo[bottom] = false;
    }

    void buildNext(string &bottom , int idx, string curr ,vector<string> &nextRows){
        if(idx == bottom.size() -1){
            nextRows.push_back (curr);
            return ;
        }

        string key = bottom.substr(idx,2);
        if(mp.find(key) == mp.end()) return;

        for(char c: mp[key]) {
        buildNext(bottom,idx+1,curr+c,nextRows);
        }
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string &s :allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }
        return solve(bottom);
    }
};
