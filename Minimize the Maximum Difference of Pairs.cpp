class Solution {
public:
    bool minMax(vector<int>& nums,int p,int mid){
        int n =nums.size();
        int cnt=0;

        for(int i=0;i<n-1 && cnt <= p;){
            if(nums[i+1]-nums[i] <= mid) {
                cnt++;
                i+=2;
            }else i++;

        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());

        int low = 0,high = nums.back()-nums.front();

        while(low < high){
            int mid= low+(high-low)/2;
            if(minMax(nums,p,mid)){
                high=mid;
            }else low=mid+1;
        }
        return low;
    }
};
