class Solution {
public:
    bool isPalindrome(string &s ,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    vector<vector<int>>dp;
    int MCM (string &s,int i,int j){
        if(i>j) return 0;
        if(isPalindrome(s,i,j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;

        for(int k=i;k<j;k++){
            if(isPalindrome(s, i, k)) { 
                int cost = 1 + MCM(s, k + 1, j);
                minCost = min(minCost, cost);
            }
        }
        return dp[i][j] = minCost;
    }
    int minCut(string s) {
        int n =s.size();
         dp.assign(n, vector<int>(n, -1));
        return MCM(s,0,n-1);
    }
};
