class Solution {
public:
    bool checkThreshold(vector<int> nums, int threshold, int divisor){
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            nums[i]= ceil((double)nums[i]/divisor);
            sum+=nums[i];
        }
        
        if(sum<=threshold) return true;
        else
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s=1;
        int e= *max_element(nums.begin(), nums.end());
        int mini= INT_MAX;
        while(s<e){
            int mid= s+(e-s)/2;
            if(checkThreshold(nums,threshold,mid)){
                mini= min(mini,mid);
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return s;
    }
};
