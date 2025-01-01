class Solution {
int solveMem(vector<int>& prices,int index,int buy,int limit,vector<vector<vector<int>>> &dp)
    {
             if(index==prices.size()) return 0;
             if(limit==0) return 0;
             int profit=0;

             if(dp[index][buy][limit]!=-1) return dp[index][buy][limit];

             if(buy)
             {
                int buykaro=-prices[index]+solveMem(prices,index+1,0,limit,dp);
                int skipkaro=0+solveMem(prices,index+1,1,limit,dp);
                 profit=max(buykaro,skipkaro);
             }else
             {
                int sellkaro=+prices[index]+solveMem(prices,index,1,limit-1,dp);
                int ignorekaro=0+solveMem(prices,index+1,0,limit,dp);
                profit=max(sellkaro,ignorekaro);
             }
             return dp[index][buy][limit]=profit;
    }      

public:
    int maxProfit(vector<int>& prices) {

         int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
         return solveMem(prices,0,1,2,dp);

    }
};
