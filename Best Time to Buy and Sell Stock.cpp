class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int profit = 0;
        int day=prices[0];

        for(int i=1;i<n;i++){
            if(prices[i]>day){
                profit=max(profit,prices[i]-day);
            }else{
                day=prices[i];
            }
        }
        return profit;
    }
};
