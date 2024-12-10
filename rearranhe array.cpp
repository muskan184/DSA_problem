class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    int n= nums.size();
   vector<int>ans(n,0);
    int pos = 0;
    int nag = 1;

   for(int i=0;i<n;i++){
    if(nums[i]<0){
        ans[nag]=nums[i];
        nag+=2;
    }else{
        ans[pos]=nums[i];
        pos+=2;
    }
    }
   return ans;
    }
};
