class Solution {
  public:

    map<pair<int,int>,int>dp;
    
    int MCM(int n,int k){
        if (k == 0 || k == 1) return k;
    if (n == 1) return k;
if (dp.count({n, k})) return dp[{n, k}];

    
    int low =1,high=k;
    int ans = INT_MAX;

    while(low<=high){
        int mid = low+(high-low)/2;
        int breakEgg = MCM(n- 1, mid - 1);
        int noBreak =MCM(n, k - mid);
        int temp = 1 + max(breakEgg, noBreak);
       
       if (breakEgg > noBreak){
           high =mid-1;
           ans = min(ans,temp);
       }else {
           low=mid+1;
           ans=min(ans,temp);
           
       }
       
    }
    return dp[{n,k}] = ans;
    }
    
    int eggDrop(int n, int k) {
    return MCM(n,k);
        
    }
};
