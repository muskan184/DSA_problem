class Solution {
public:
    bool can (vector<int> &price , int k ,int mid){
        int count = 1;
        int last = price[0];
        int n = price.size();
        for(int i=1;i<n;i++){
            if(price[i]-last >= mid)
                {
                     count ++;
                     last = price[i];
                      if(count >= k) return true;
               }
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int low =0;
        int high = price.back()-price.front();
        int ans =0;

        while(low <= high){
            int mid = (low+high)/2;
            if(can(price,k,mid)){
                ans=mid;
                low=mid+1;

            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};
