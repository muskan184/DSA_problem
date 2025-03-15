class Solution {
public:
    bool house (vector<int>& nums,int n,int k,int mid){
        int steal=0;
        for(int i=0;i<n && steal<=k;i++){
            if(nums[i]<=mid){
                steal++;
                i++;
            }
        }
        return steal >= k;
    }
    int minCapability(vector<int>& nums, int k) {
        int n =nums.size();
        auto [min,max]=minmax_element(nums.begin(),nums.end());

        int left =*min,right=*max,mid;

        while(left<right){
            mid=(left+right)/2;
            if(house(nums,n,k,mid)){
                right=mid;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
