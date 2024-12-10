      int n=arr.size();
        int low=0;
        int high =n-1;
        int ans;
        
        while(low <= high ){
            int mid = (low+high)/2;
        
        
        
         if(arr[mid]>=target){
             high=mid-1;
         }else{
             low=mid+1;
         }
        }
        return low;
