class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int rem = ((nums[i]%value)+value)%value;
            freq[rem]++;
        }
        int mex  = 0;
        while(true){
            int rem = mex%value;
            if(freq[rem]>0){
                freq[rem]--;
                mex++;
            }else
            break;
        }
        return mex;
    }
};
