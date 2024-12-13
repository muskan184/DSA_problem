class Solution {
public:
    int findmax(vector<int> &v){
        int maxi=INT_MIN;
        int n =v.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,v[i]);
        }
        return maxi;
    }

    int calculateTotalHours(vector<int> &v,int hours){
        int total=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            total+=ceil((double)v[i]/(double)hours);
        }
            return total;
    }
    int minEatingSpeed(vector<int>& v, int h) {
        int low=1, high=findmax(v);
        while(low<= high){
            int mid =(low+high)/2;
            int total = calculateTotalHours(v,mid);
            if(total <= h){
                high =mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
