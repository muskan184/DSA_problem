    int maxLen(vector<int>& arr) {
        // code here
        unordered_map<int,int> prefixSumIndex;
        int maxlen=0;
        int sum=0;
         for(int i=0;i<arr.size();i++){
         sum+=arr[i];
         if (sum==0){
             maxlen=i+1;
         }
         if(prefixSumIndex.find(sum)!=prefixSumIndex.end()){
             maxlen=max(maxlen,i-prefixSumIndex[sum]);
         }else{
             prefixSumIndex[sum]=i;
         }
         }
         return maxlen;
    }
