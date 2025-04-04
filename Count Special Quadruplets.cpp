class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int n = nums.size();
        int count =0;
         for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        int sum=nums[i]+nums[j]+nums[k];

                        if(sum == nums[l]){
                            count+=1;
                        }
                    }
                }
            }
         }
         return count;
    }
};
