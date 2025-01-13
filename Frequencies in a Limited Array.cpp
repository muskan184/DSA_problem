  int longestSubarray(vector<int>& arr, int k) {
        // code here
        unordered_map <int ,int>sumMap;
        int maxlength =0;
        int sum=0;
         for(int i=0;i<arr.size();i++){
             sum+=arr[i];
             if(sum==k){
                 maxlength=i+1;
             }
             if(sumMap.find(sum-k) != sumMap.end()){
                 maxlength=max(maxlength,i-sumMap[sum-k]);
             }
             if(sumMap.find(sum) == sumMap.end() ){
                 sumMap[sum]=i;
             }
         }
         return maxlength;
    }
